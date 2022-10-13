
/*
11659 - ���� �� ���ϱ� 4

�⺻���� ������ ����, ���� ����ϰ� ���ϴ� ������ ��ȯ

*/


#include<iostream>
#include<vector>

using namespace std;

vector<int> DPArry{};


int ArrSize = 0;
int QueryCount = 0;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	DPArry.push_back(0);
	cin >> ArrSize >> QueryCount;
	int Sum = 0;
	while (ArrSize--)
	{
		int InputNum = 0;
		cin >> InputNum;
		Sum += InputNum;
		DPArry.push_back(Sum);
	}
	while (QueryCount--)
	{
		int StartIndex = 0;
		int EndIndex = 0;
		cin >> StartIndex >> EndIndex;
		cout << DPArry[EndIndex] - DPArry[StartIndex - 1] << "\n";
	}

	return 0;
}
