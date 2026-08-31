#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    float armstrong = 0;
    cout << "Enter a number to check whether it is a armstrong number or not: ";
    cin >> n;
    int original = n;
    int digits = (n == 0) ? 1 : log10(n) + 1;
    while (n != 0)
    {
        int temp = n % 10;
        armstrong += pow(temp, digits);
        n /= 10;
    }
    if (armstrong == original)
    {
        cout << "Armstrong number" << endl;
    }
    else
    {
        cout << "Not Armstrong number" << endl;
    }
}
