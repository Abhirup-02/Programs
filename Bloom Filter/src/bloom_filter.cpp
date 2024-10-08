#include <iostream>
#include <vector>
using namespace std;

#include <hash.hh>

class BloomFilter
{
    vector<bool> bitArray;
    size_t size;

public:
    BloomFilter(size_t size) : size(size), bitArray(size, false)
    {
    }

    int hash_1(const string &str)
    {
        return StringHash::HashFunction(str, 17) % size;
    }

    int hash_2(const string &str)
    {
        return StringHash::HashFunction(str, 31) % size;
    }

    int hash_3(const string &str)
    {
        return StringHash::HashFunction(str, 53) % size;
    }

    void add(const string &input)
    {
        bitArray[hash_1(input)] = true;
        bitArray[hash_2(input)] = true;
        bitArray[hash_3(input)] = true;
    }

    bool contains(const string &input)
    {
        return bitArray[hash_1(input)] && bitArray[hash_2(input)] && bitArray[hash_3(input)];
    }
};

int main()
{
    BloomFilter bloomFilter(1000);

    bloomFilter.add("hello");

    cout << "Contains 'hello': " << (bloomFilter.contains("hello") ? "Yes" : "No") << endl;
    cout << "Contains 'world': " << (bloomFilter.contains("world") ? "Yes" : "No") << endl;
}
