#include<iostream>
#include <algorithm>
#include <string>

using namespace std;

string InputSrc{};
string InputDest{};
string Result{};

int ParseInt(string const& Str, int const Index)
{
	if (Index >= Str.size())
		return 0;
	return static_cast<int>(Str[Index] - '0');
}

void ReverseArr(string& Str)
{
	for (int i = 0; i < Str.size(); i++)
	{
		if (i >= (Str.size() / 2))
			break;
		swap(Str[i], Str[Str.size() - i - 1]);
	}
}
void PrintArr(string const& str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (i == 0 and str[i] == '0');
		else
		{
			cout << str[i];
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> InputSrc >> InputDest;
	ReverseArr(InputSrc);
	ReverseArr(InputDest);
	int Size = max(InputSrc.size(), InputDest.size());
	Result.push_back('0');
	for (int i = 0; i < Size; i++)
	{
		int Elem = (ParseInt(Result, i) + ParseInt(InputSrc, i) + ParseInt(InputDest, i));
		Result[i] = (Elem % 10) + '0';
		Result.push_back((Elem / 10) + '0');
	}
	ReverseArr(Result);
	PrintArr(Result);
	return 0;
}