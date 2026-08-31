#include <iostream>
#include <cmath>
#include <string>
#include <climits>
#include <algorithm>
#include <iomanip>
#include <array>
#include <vector>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		int ans = 0;
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			int product = a[i] * (1 + res);
			ans += product;
			res = product;
		}
		cout << ans << endl;
	}
	return 0;
}
