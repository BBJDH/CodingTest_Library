#include<iostream>
#include<deque>
#include<string>
#include<regex>
#include<sstream>
using namespace std;

deque<int> Series{};

void PushDeque(string const& Str)
{
	int PushNum = 0;
	for (int i = 0; i < Str.size(); i++)
	{
		PushNum += Str[i] - '0';
		if (i != Str.size() - 1)
			PushNum *= 10;
	}
	Series.push_back(PushNum);
}
void PrintElem(bool const IsFront)
{
	if (IsFront)
	{
		cout << Series.front();
		Series.pop_front();
	}
	else
	{
		cout << Series.back();
		Series.pop_back();
	}
}

void Function(string const& FuncStr)
{
	bool IsFront = true;
	for (int i = 0; i < FuncStr.size(); i++)
	{
		switch (FuncStr[i])
		{
		case 'R':
		{
			//앞/뒤 bool 토클
			IsFront = not IsFront;
			break;
		}
		case 'D':
		{
			if (Series.empty())
			{
				cout << "error" << "\n";
				return;
			}
			//해당 방향으로 pop
			if (IsFront) Series.pop_front();
			else Series.pop_back();
			break;

		}
		default:
			break;
		}
	}
	cout << "[";
	while (!Series.empty())
	{
		PrintElem(IsFront);
		if (Series.size() != 0)
			cout << ",";
	}
	cout << "]" << "\n";
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int TestCase = 0;

	cin >> TestCase;
	while (TestCase--)
	{
		string FuncStr{};
		string InputSeries{};
		int SeriesSize = 0;
		cin >> FuncStr >> SeriesSize;
		cin >> InputSeries;
		InputSeries = regex_replace(InputSeries, regex("[\\[\\]]"), "");
		istringstream InputSStream(InputSeries);
		string NumStr{};
		while (getline(InputSStream, NumStr, ','))
		{
			PushDeque(NumStr);
		}
		Function(FuncStr);
	}

	return 0;
}

