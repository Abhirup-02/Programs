// find the subarrays which is equal to the given sum,starting and ending positions
// O(n^2)time complexity

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

    int sum;
    cin >> sum;
    for (int i = 0; i < n; i++)
    {
        int curr_sum = 0;
        for (int j = i; j < n; j++)
        {
            curr_sum += a[j];
            if (curr_sum == sum)
            {
                cout << i + 1 << " " << j + 1 << endl;
            }
        }
    }
}