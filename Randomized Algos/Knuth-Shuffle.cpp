#include <iostream>
#include <random>
#include <vector>
#include <ctime>
using namespace std;

void print(vector<int> v)
{
    for (int num : v)
    {
        cout << num << " ";
    }
    cout << endl;
}

void KnuthShuffle(vector<int> &v)
{
    srand(static_cast<unsigned int>(time(0)));

    for (int currentIndex = v.size() - 1; currentIndex > 0; --currentIndex)
    {
        int randomIndex = rand() % (currentIndex + 1);

        swap(v[currentIndex], v[randomIndex]);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int &e : v)
    {
        cin >> e;
    }

    KnuthShuffle(v);
    print(v);
}
