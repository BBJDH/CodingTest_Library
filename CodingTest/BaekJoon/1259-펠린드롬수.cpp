#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
#include<cassert>
#include <stack>
#include<sstream>
using namespace std;

void CheckPalindorome(char const* const Target_Str, int const Str_size)
{
	int const Search_Max_Index = (Str_size + 1) / 2;
	int const Str_End_Index = Str_size - 1;
	for (int i = 0; i <= Search_Max_Index; i++)
	{
		if (Target_Str[i] != Target_Str[Str_End_Index - i])
		{
			cout << "no" << "\n";
			return;
		}
	}
	cout << "yes" << "\n";
	return;
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	while (true)
	{
		char str[100000]{};
		cin >> str;

		if (strlen(str) == 1 and str[0] == '0')
			return 0;

		CheckPalindorome(str, strlen(str));
	}



	return 0;
}