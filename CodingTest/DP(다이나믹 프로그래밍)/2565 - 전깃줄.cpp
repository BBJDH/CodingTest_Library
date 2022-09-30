
/*

2565 - ������

���� �����븦 �������� �����ϰ� ������ ��ȣ�� �ָ��غ���

8 2 9 1 4 6 7 10 ����

���� �� �����ϴ� ������ ã�Ƽ� ��ȯ�ϸ�
�� ���� ���� ���� ���� �� �ִ� ���� �� �̴�
������ �츮�� ���ϴ°��� ���� ���� ���̹Ƿ� ���������� ������ ���� ���� ���� ��ȯ�Ѵ�
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
