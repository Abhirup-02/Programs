#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <openssl/sha.h>

std::string sha256(const std::string &input)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((const unsigned char *)input.c_str(), input.size(), hash);

    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << std::hex << std::setw(2) << std::setfill('0')
           << (int)hash[i];
    }
    return ss.str();
}

struct Record
{
    int id;
    std::string name;
    int score;

    std::string serialize() const
    {
        return std::to_string(id) + "|" + name + "|" + std::to_string(score);
    }

    static Record deserialize(const std::string &line)
    {
        Record r;
        std::stringstream ss(line);
        std::string token;

        std::getline(ss, token, '|');
        r.id = std::stoi(token);

        std::getline(ss, token, '|');
        r.name = token;

        std::getline(ss, token, '|');
        r.score = std::stoi(token);

        return r;
    }
};

// tree[0] = leaves
// tree[last] = root level
using MerkleTree = std::vector<std::vector<std::string>>;

MerkleTree buildMerkleTree(const std::vector<Record> &records)
{
    MerkleTree tree;

    // ---- leaf level ----
    std::vector<std::string> level;
    for (const auto &r : records)
    {
        level.push_back(sha256(r.serialize()));
    }
    tree.push_back(level);

    // ---- build up ----
    while (level.size() > 1)
    {
        std::vector<std::string> next;

        for (size_t i = 0; i < level.size(); i += 2)
        {
            std::string left = level[i];
            std::string right = (i + 1 < level.size()) ? level[i + 1] : left;
            next.push_back(sha256(left + right));
        }

        tree.push_back(next);
        level = next;
    }

    return tree;
}

int findMismatchIndex(const MerkleTree &A, const MerkleTree &B)
{
    int index = 0;

    // start from root level, go down
    for (int level = A.size() - 1; level > 0; --level)
    {
        int left = index * 2;
        int right = left + 1;

        if (A[level - 1][left] != B[level - 1][left])
        {
            index = left;
        }
        else
        {
            index = right;
        }
    }

    return index;
}

void writeDataset(const std::string &filename, const std::vector<Record> &records)
{
    std::ofstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Failed to open file for writing: " << filename << "\n";
        return;
    }

    for (const auto &r : records)
    {
        file << r.serialize() << "\n";
    }

    file.close();
    std::cout << "Written " << records.size() << " records to " << filename << "\n";
}

std::vector<Record> readDataset(const std::string &filename)
{
    std::vector<Record> records;
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "Failed to open file for reading: " << filename << "\n";
        return records;
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (!line.empty())
        {
            records.push_back(Record::deserialize(line));
        }
    }

    file.close();
    std::cout << "Read " << records.size() << " records from " << filename << "\n";
    return records;
}

int main()
{
    const int N = 100;

    // ---- Build and write datasets ----
    std::vector<Record> dbA;
    std::vector<Record> dbB;

    // for (int i = 0; i < N; i++)
    // {
    //     Record r{i, "user_" + std::to_string(i), i * 10};
    //     dbA.push_back(r);
    //     dbB.push_back(r);
    // }

    // ---- introduce ONE mismatch ----
    // int badIndex = 73;
    // dbB[badIndex].score = 9999; // change only one record

    // Write datasets to files
    // writeDataset("dataset_A.txt", dbA);
    // writeDataset("dataset_B.txt", dbB);

    // ---- Read datasets from files ----
    dbA = readDataset("dataset_A.txt");
    dbB = readDataset("dataset_B.txt");

    std::cout << "\n";

    auto treeA = buildMerkleTree(dbA);
    auto treeB = buildMerkleTree(dbB);

    std::string rootA = treeA.back()[0];
    std::string rootB = treeB.back()[0];

    std::cout << "Root A: " << rootA << "\n";
    std::cout << "Root B: " << rootB << "\n\n";

    if (rootA == rootB)
    {
        std::cout << "Databases are identical\n";
        return 0;
    }

    int mismatch = findMismatchIndex(treeA, treeB);

    std::cout << "Mismatch found at index: " << mismatch << "\n\n";

    std::cout << "Record in DB A:\n";
    std::cout << "  id=" << dbA[mismatch].id
              << ", name=" << dbA[mismatch].name
              << ", score=" << dbA[mismatch].score << "\n";

    std::cout << "Record in DB B:\n";
    std::cout << "  id=" << dbB[mismatch].id
              << ", name=" << dbB[mismatch].name
              << ", score=" << dbB[mismatch].score << "\n";

    return 0;
}
