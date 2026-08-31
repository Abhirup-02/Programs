#include <iostream>
using namespace std;

int main()
{
  int a, b, c, max;
  cout << "Enter three numbers: ";
  cin >> a >> b >> c;

  /*
    if a>b and a>c, then we assign a
    to max else if b>c we assign b
    to max else we assign c to max
  */

  max = a > b && a > c ? a : b > c ? b
                                   : c;

  cout << "The maximum number is " << max << endl;
}