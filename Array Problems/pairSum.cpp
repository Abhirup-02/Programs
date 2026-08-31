// Check if there exists two elements in an array such that their sum is equal to given k
#include <iostream>
#include <climits>
using namespace std;

bool pairSum(int arr[], int n, int k)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == k)
            {
                cout << i << " " << j << endl;
                return true;
            }
        }
    }
    return false;
}

int main()
{

    int arr[] = {2, 4, 7, 11, 14, 16, 20, 21};
    int k = 31;

    cout << pairSum(arr, 8, k) << endl;
}

// Check if there exists two elements in an array such that their is equal to given k, time complexity O(n)
// for this method to be applied array must be sorted
#include <iostream>
#include <climits>
using namespace std;

bool pairSum(int arr[], int n, int k)
{
    int low = 0, high = n - 1;
    while (low < high)
    {
        if (arr[low] + arr[high] == k)
        {
            cout << low + 1 << " " << high + 1 << endl;
            return true;
            break;
        }
        else if (arr[low] + arr[high] < k)
        {
            low++;
        }
        else
        {
            high--;
        }
    }
    return false;
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

    int k;
    cin >> k;

    cout << pairSum(a, n, k) << endl;
}