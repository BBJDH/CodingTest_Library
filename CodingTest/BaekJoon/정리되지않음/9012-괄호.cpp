#include <iostream>
#include <stack>
#include <string>
using namespace std;

void Check_VPS(string const& target)
{
	stack<char>  Left_bracket{};

	for (int i = 0; i < target.size(); i++)
	{
		char Single_char = static_cast<char>(target[i]);
		switch (Single_char)
		{
		case '(':
		{
			Left_bracket.push('(');
			break;
		}
		case ')':
		{
			if (Left_bracket.empty())
			{
				cout << "NO" << "\n";
				return;
			}
			Left_bracket.pop();
			break;
		}

		default:
			break;
		}
	}
	if (Left_bracket.empty())
	{
		cout << "YES" << "\n";
		return;
	}
	cout << "NO" << "\n";
	return;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int TestCase = 0;

	cin >> TestCase;
	while (TestCase--)
	{
		string Input_String{};
		cin >> Input_String;
		Check_VPS(Input_String);
	}
	return 0;
}
