#include <iostream>
#include <string>
#include <regex>
#include <algorithm>	
using namespace std;

int StrSize = 0;
string First{}, Second{};
char const* Ignore[5] = { "a", "e", "i", "o", "u" };

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> StrSize >> First >> Second;

	string temp1 = First;
	string temp2 = Second;

	sort(temp1.begin(), temp1.end());
	sort(temp2.begin(), temp2.end());

	if (First.front() == Second.front() and First[StrSize - 1] == Second[StrSize - 1])
	{
		for (int i = 0; i < 5; i++)
		{
			First = regex_replace(First, regex(Ignore[i]), "");
			Second = regex_replace(Second, regex(Ignore[i]), "");
		}
		if (First == Second and temp1 == temp2)
		{
			cout << "YES";
			return 0;
		}

	}
	cout << "NO";
	return 0;
}
