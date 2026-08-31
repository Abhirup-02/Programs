// if summation of factorial of each digit returns the original number then it is a strong number
#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
        return n * factorial(n - 1);
}

int strongNumber(int n)
{
    int strong = 0;
    int original = n;
    while (n != 0)
    {
        int temp = n % 10;
        strong += factorial(temp);
        n /= 10;
    }
    if (strong == original)
    {
        cout << original << " is a Strong number" << endl;
    }
}

int main()
{
    int x, y; // x=lower limit,y=upper limit
    cout << "Enter the range: ";
    cin >> x >> y;

    // strong numbers within a range
    for (int i = x; i <= y; i++)
    {
        strongNumber(i);
    }
    return 0;
}