/*
    Some prime numbers can be expressed as a sum of other consecuitve prime numbers. For example, 5=2+3, 17=2+3+5+7, 41=2+3+5+7+11+13. The task is to find out how many prime numbers which satisfy this property are present in the range 3 to N subject to a constraint
    that summation should always start with number 2. Write code to find out the number of prime numbers that satisfy the above-mentioned
    property in given range.
*/

#include <iostream>
using namespace std;

int prime(int n)
{
    int flag = 0;
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        return 0;
    return 1;
}

int main()
{
    int n;
    cin >> n;
    int count = 0;
    for (int i = 3; i <= n; i++)
    {
        if (prime(i))
        {
            int num = 0;
            for (int j = 2; j <= i; j++)
            {
                if (prime(j))
                {
                    num += j;
                    if (num == i)
                    {
                        count++;
                        break;
                    }
                }
            }
        }
    }
    cout << count;
}