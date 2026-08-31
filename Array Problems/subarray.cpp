// print subarrays of an array
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                cout << a[k] << " ";
            }

            cout << endl;
        }
    }
}

// Maximum subarray sum brute force approach, time complexity O(n^3)
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int max_sum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += a[k];
            }
            max_sum = max(max_sum, sum);
        }
    }
    cout << max_sum;
}

// Maximum subarray sum, time complexity O(n^2) [cumulative sum approach]
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int curr_sum[n + 1];
    curr_sum[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        curr_sum[i] = curr_sum[i - 1] + a[i - 1];
    }

    int max_sum = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 0; j < i; j++)
        {
            sum = curr_sum[i] - curr_sum[j];
            max_sum = max(max_sum, sum);
        }
    }
    cout << max_sum;
}

// Maximum subarray sum, time complexity O(n)[Kadane's algorithm]
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int max_sum = INT_MIN;
    int currsum = 0;
    for (int i = 0; i < n; i++)
    {
        currsum += a[i];
        // update sum as 0 if sum becomes negative
        if (currsum < 0)
        {
            currsum = 0;
        }
        max_sum = max(max_sum, currsum);
    }

    cout << max_sum;
}