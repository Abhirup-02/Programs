// Maximum circular subarray sum
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int kadane(int arr[], int n)
{
    int currsum = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currsum += arr[i];
        if (currsum < 0)
        {
            currsum = 0;
        }
        maxSum = max(maxSum, currsum);
    }
    return maxSum;
}

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int wrapSum;
    int nonwrapSum;

    nonwrapSum = kadane(a, n);
    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum += a[i];
        a[i] = -a[i];
    }

    wrapSum = totalSum + kadane(a, n);

    cout << max(nonwrapSum, wrapSum) << endl;
}