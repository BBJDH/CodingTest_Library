#include<iostream>
#include<string>
#include <map>

using namespace std;

map<string, bool> TargetString{};


int main()
{
	int CompareString_Size = 0;
	int InputString_Size = 0;
	int count = 0;
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> CompareString_Size >> InputString_Size;

	for (int i = 0; i < CompareString_Size; i++)
	{
		string input{};
		cin >> input;
		TargetString.insert(make_pair(input, false));
	}

	for (int i = 0; i < InputString_Size; i++)
	{
		string input{};
		cin >> input;
		if (TargetString.find(input) != TargetString.end())
			count++;
	}

	cout << count;
	return 0;
}

