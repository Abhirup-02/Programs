// You are given an array arr[] of N integers including 0. The task is to find the smallest positive integer number missing from the array
// Constraints
// 1 <= N <= 10^6
// 10^-6 <= Ai <= 10^6

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    const int N = 1e6 + 2;
    bool check[N];
    for (int i = 0; i < N; i++)
    {
        check[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            check[arr[i]] = true;
        }
    }
    int ans = -1;
    for (int i = 1; i < N; i++)
    {
        if (check[i] == false)
        {
            ans = i;
            break;
        }
    }

    cout << ans << endl;
}