#include <iostream>
#include <iomanip>
using namespace std;

void PascalTriangle(int n)
{
    for (int i = 0; i < n; i++)
    {
        int space = 40 - 3 * i;
        int bin = 1;
        for (int j = 1; j <= space; j++)
        {
            cout << " ";
        }
        for (int k = 0; k <= i; k++)
        {
            if (i == 0 || k == 0)
            {
                cout << bin;
            }
            else
            {
                bin = bin * (i - k + 1) / k;
                cout << setw(6) << bin;
            }
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    PascalTriangle(n);
}