#include<iostream>
#include<string>
#include<algorithm>
#include<set>
using namespace std;

set<int> NumArr{};
short MaxNum = 0;
short SeriesSize = 0;

void ExtractNum(short const ExtractCount = 1, string const& Series = {}, short const MinNum = 1)
{
	for (auto iter = NumArr.begin(); iter != NumArr.end(); iter++)
	{
		if (*iter >= MinNum)
		{
			string NewSeries = Series;
			NewSeries = NewSeries + to_string(*iter) + " ";
			if (ExtractCount == SeriesSize)
				cout << NewSeries << "\n";
			else if (ExtractCount < SeriesSize)
				ExtractNum(ExtractCount + 1, NewSeries, *iter);
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> MaxNum >> SeriesSize;
	for (int i = 0; i < MaxNum; i++)
	{
		int InputNum = 0;
		cin >> InputNum;
		NumArr.insert(InputNum);
	}
	ExtractNum();

	return 0;
}
