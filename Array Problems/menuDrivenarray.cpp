#include <iostream>
#include <algorithm>
using namespace std;

void Sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

void Update(int arr[], int n, int pos, int k)
{
    if (pos - 1 < n && pos - 1 >= 0)
    {
        arr[pos - 1] = k;
    }
    else
    {
        cout << "Not valid position" << endl;
    }
}

int Insert(int arr[], int n, int pos, int k)
{
    if (pos - 1 > n || pos - 1 < 0)
    {
        cout << "Insertion not possible" << endl;
    }
    if (pos - 1 == n)
    {
        arr[pos - 1] = k;
    }
    int i = n;
    while (i >= pos)
    {
        arr[i] = arr[i - 1];
        i--;
    }
    n++;
    arr[pos - 1] = k;

    return n;
}

int BinarySearch(int arr[], int n, int k)
{
    Sort(arr, n);

    int s = 0, e = n;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == k)
        {
            return mid;
        }
        else if (arr[mid] > k)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
}

int Delete(int arr[], int n, int pos)
{
    if (pos - 1 >= n || pos - 1 < 0)
    {
        cout << "Cannot Delete" << endl;
    }
    int i = pos - 1;
    while (i < n - 1)
    {
        arr[i] = arr[i + 1];
        i++;
    }
    n--;
    return n;
}

void Display(int arr[], int n)
{
    cout << "The array ->  ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n;
    cout << "Enter array size :";
    cin >> n;
    int a[n];

    cout << "Enter inputs ->";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Choose an operation ->" << endl;
    cout << "Press 1 to Update" << endl;
    cout << "Press 2 to Insert" << endl;
    cout << "Press 3 to Search" << endl;
    cout << "Press 4 to Delete" << endl;
    cout << "Press 5 to Display" << endl;

    int pos, item, len;
    int x;
    cin >> x;
    switch (x)
    {
    case 1:
        cout << "Enter the position and item to update :";
        cin >> pos >> item;
        Update(a, n, pos, item);
        Display(a, n);
        break;

    case 2:
        cout << "Enter the position and item to insert :";
        cin >> pos >> item;
        len = Insert(a, n, pos, item);
        Display(a, len);
        break;

    case 3:
        cout << "Enter an element to search :";
        cin >> item;
        Sort(a, n);
        Display(a, n);
        cout << endl;
        cout << "In the sorted array element present at position " << BinarySearch(a, n, item) + 1 << endl;
        break;

    case 4:
        cout << "Enter a position to delete the element :";
        cin >> pos;
        len = Delete(a, n, pos);
        Display(a, len);
        break;

    case 5:
        Display(a, n);
        break;

    default:
        cout << "Choose a valid operation" << endl;
    }
}