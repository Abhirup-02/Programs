#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // check between adjacent two elements in the array,if the order is wrong then swap them
    // the max element will bubble up after each iteration
    int counter = 1;
    int comparison = 0;
    while (counter < n)
    {
        int flag;
        for (int i = 0; i < n - counter; i++)
        {
            comparison++;
            if (arr[i] > arr[i + 1])
            {
                flag = 0;
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
            else
            {
                flag = 1;
            }
        }
        counter++;
        if (flag == 1)
            break;
    }
    cout << "The sorted array is:" << " ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\nComparison needed " << comparison;
}