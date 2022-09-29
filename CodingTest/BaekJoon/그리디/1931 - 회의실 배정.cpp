
/*
1931 - ȸ�ǽ� ����

ȸ�ǰ� ������ �ð��� �������� ����

ù ȸ�Ǻ��� ������ ��� ���� ȸ���� ���۽ð��� ���� ����� ����� ������ �����½ð����� ũ�ų� ���ٸ�,

���� ��Ͽ� �߰�, Count++

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct _int2
{
	int Start;
	int End;
};

vector<_int2> Array_Meeting{};


bool CMP(_int2 const& First, _int2 const& Second)
{
	if (First.End == Second.End)
		return First.Start < Second.Start;
	return First.End < Second.End;
}
void Solution()
{
	int TimeEnd = 0;
	int Count = 0;
	for (auto const& Elem : Array_Meeting)
	{
		if (TimeEnd <= Elem.Start)
		{
			TimeEnd = Elem.End;
			Count++;
		}
	}
	cout << Count;
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int InputCount = 0;
	cin >> InputCount;

	while (InputCount--)
	{
		_int2 InputData{};

		cin >> InputData.Start >> InputData.End;

		Array_Meeting.push_back(InputData);
	}
	sort(Array_Meeting.begin(), Array_Meeting.end(), CMP);
	Solution();
	return 0;
}

