#include <iostream>
using namespace std;
#define size(x) sizeof(x) / sizeof(x[0])

int main()
{
    int n = 20;
    int *aptr;

    aptr = &n;
    cout << *aptr << endl;
    *aptr = 21;
    cout << *aptr << endl;

    int arr[]{10, 20, 30, 40};
    cout << *arr << endl;

    int *ptr = arr;
    for (int i = 0; i < size(arr); i++)
    {
        // cout << *(arr + i) << " "; //index pointer
        //  arr++; // this is constant , cannot be incremented
        cout << *ptr << " ";
        ptr++;
    }
}
