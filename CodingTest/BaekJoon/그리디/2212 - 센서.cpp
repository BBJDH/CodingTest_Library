
/*
 2212 ����
 �� �������� �Ÿ��� �����ְ� ���⼭ ���� ū �Ÿ��� ���߱� ��-1 ��ŭ �����ָ�
 ���߱� ����ŭ�� ���������� �����ȴ�
 ���� �����ִ� �������̰Ÿ��� ��� �����ָ� �ȴ�

*/

#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;

int SensorNum = 0;
int LinkerNum = 0;

vector<int> SenSorCood{};
vector<int> Distance{};

void Solution()
{
	int Answer = 0;

	for (int i = 0; i < SenSorCood.size() - 1; i++)
	{
		int CurrentDistance = SenSorCood[i + 1] - SenSorCood[i];
		Distance.push_back(CurrentDistance);
	}
	sort(Distance.begin(), Distance.end());
	for (int i = 0; i < Distance.size() - LinkerNum + 1; i++)
	{
		Answer += Distance[i];
	}
	cout << Answer;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> SensorNum >> LinkerNum;
	if (LinkerNum > SensorNum)
	{
		cout << 0;
		return 0;
	}
	for (int i = 0; i < SensorNum; i++)
	{
		int InputCood = 0;
		cin >> InputCood;
		SenSorCood.push_back(InputCood);
	}
	sort(SenSorCood.begin(), SenSorCood.end());

	Solution();
	return 0;
}
