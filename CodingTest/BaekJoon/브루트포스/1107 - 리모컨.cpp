/*
1107 - ������
�ܼ� Ű�� ���������� Ȯ���ϰ� ��δ� Ȯ���ؼ� ���ϴ� �����̴�
�ٸ� ������ �ι�� ��ƾ� �Ѵ�
500000
6
0 1 2 3 4 5

�� ��츦 �����غ���

*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<int> MinCounts{};
bool NumEnable[10]{};

int TargetNum = 0;
int CandidateNum = 0;

bool CheckCanUse(int CheckNum)
{
	string CheckStr = to_string(CheckNum);

	for (int i = 0; i < CheckStr.size(); i++)
	{
		int NumIndex = CheckStr[i] - '0';
		if (NumEnable[NumIndex] == false)
			return false;
	}
	return true;
}

void Solution()
{
	int MinCount = abs(100 - TargetNum);
	for (int i = 0; i < 1000000; i++)
	{
		if (CheckCanUse(i))
		{
			int NewCount = abs(i - TargetNum) + 1;
			int CurrentNum = i;
			while (CurrentNum /= 10)
			{
				NewCount++;
			}
			MinCount = min(MinCount, NewCount);
		}
	}
	cout << MinCount;
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int InputCount = 0;

	fill_n(NumEnable, 10, true);
	cin >> TargetNum >> InputCount;
	while (InputCount--)
	{
		int InputNum = 0;
		cin >> InputNum;
		NumEnable[InputNum] = false;
	}
	Solution();
	return 0;
}
