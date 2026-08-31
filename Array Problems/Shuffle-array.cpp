/* Given array nums consisting of 2n elements in the form of [x1,x2,.....,xn,y1,y2,.....,yn]
   Return the array in the form [x1,y1,x2,y2,......,xn,yn] */

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int N = 2 * n;
    int a[N];

    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    // shuffle elements
    int j = n;
    for (int i = 0; i < n - 1; i++)
    {
        int temp = a[j];
        j++;

        int count = n - i - 1;
        int k = i + 1;

        while (count > 0)
        {
            a[k + n - 1] = a[k + n - 2];
            k--;
            count--;
        }
        a[2 * i + 1] = temp;
    }
    // print shuffled array
    for (int i = 0; i < N; i++)
    {
        cout << a[i] << " ";
    }

    // for(int i=0; i<n; i++){
    //     cout<<a[i]<<" "<<a[n+i]<<" ";
    // }
}
