// check for balanced brackets.

#include <iostream>
#include <stack>
using namespace std;

bool areBracketsBalanced(string expr)
{
	stack<char> temp;
	for (int i = 0; i < expr.length(); i++)
	{
		if (temp.empty())
		{
			temp.push(expr[i]);
		}
		else if ((temp.top() == '(' && expr[i] == ')') || (temp.top() == '{' && expr[i] == '}') || (temp.top() == '[' && expr[i] == ']'))
		{
			temp.pop();
		}
		else
		{
			temp.push(expr[i]);
		}
	}
	if (temp.empty())
	{
		return true;
	}
	return false;
}

int main()
{
	string s;
	cin >> s;
	string expr;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(' || s[i] == ')' || s[i] == '{' || s[i] == '}' || s[i] == '[' || s[i] == ']')
		{
			expr.push_back(s[i]);
		}
	}

	cout << expr << " -> ";
	if (areBracketsBalanced(expr))
		cout << " Balanced";
	else
		cout << " Not Balanced";
}
