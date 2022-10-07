
/*

2565 - 전깃줄

왼쪽 전봇대를 기준으로 정렬하고 오른쪽 번호를 주목해보면

8 2 9 1 4 6 7 10 으로

가장 긴 증가하는 수열을 찾아서 반환하면
이 수가 가장 많이 이을 수 있는 전선 수 이다
하지만 우리가 원하는것은 끊을 전선 수이므로 전선수에서 위에서 구한 수를 빼서 반환한다
*/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Line
{
	int Left;
	int Right;
};

bool Compare(Line const& First, Line const& Second)
{
	return First.Left < Second.Left;
}

vector<Line> Lines{};
vector<int> MaxCounts{};

void Solution()
{
	MaxCounts.push_back(1);

	for (int i = 1; i < Lines.size(); i++)
	{
		int CurrnetCount = 0;
		for (int j = 0; j < i; j++)
		{
			if (Lines[i].Right > Lines[j].Right and CurrnetCount < MaxCounts[j])
				CurrnetCount = MaxCounts[j];
		}
		MaxCounts.push_back(CurrnetCount + 1);
	}
	sort(MaxCounts.begin(), MaxCounts.end());
	cout << Lines.size() - MaxCounts[MaxCounts.size() - 1];
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int InputCount = 0;

	cin >> InputCount;

	while (InputCount--)
	{
		Line InputLine{};
		cin >> InputLine.Left >> InputLine.Right;
		Lines.push_back(InputLine);
	}
	sort(Lines.begin(), Lines.end(), Compare);
	Solution();
	return 0;
}
