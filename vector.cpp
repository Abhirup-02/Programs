#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &e : v)
    {
        cin >> e;
    }

    vector<int> w;
    // int min = *min_element(v.begin(),v.end()); 
    for (int i = 0; i < n; i++)
    {
        w.push_back(v[i]);
    }
    sort(v.begin(), v.end());

    int j = 0;
    for (int i = 0; i < w.size(); i++)
    {
        if (v[j] == w[i])
        {
            w.erase(w.begin() + i);
            j++;
            i--;
        }
    }
    for (int i = 0; i < w.size(); i++)
    {
        cout << w[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}