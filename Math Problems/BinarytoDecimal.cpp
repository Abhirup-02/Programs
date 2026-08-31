#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int BinarytoDecimal(string s)
{
    int sum = 0;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[s.length() - i - 1] == '0')
        {
            sum += 0;
        }
        else
        {
            sum += pow(2, i);
        }
    }
    return sum;
}

int main()
{
    string s;
    cin >> s;

    cout << BinarytoDecimal(s) << endl;
}
