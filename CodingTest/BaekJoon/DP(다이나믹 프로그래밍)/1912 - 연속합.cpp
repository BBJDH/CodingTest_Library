

/*
1912 - 연속합

연속된 현재 합을 저장할곳과, 업데이트 되는 현재합중에서 최대합을 보관할 곳을 생성,
입력된 번호를 합하고 더한 합은 현재 합에 저장, 현재합이 입력된 번호보다 작다면 번호로 리셋
그리고 업데이트된 현재합을 기준으로 지속 최대합과 비교, 업데이트


*/
#include<iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int MaxSum = -2000;
	int CurrentSum = 0;
	int NumSize = 0;
	cin >> NumSize;

	while (NumSize--)
	{
		int InputNum = 0;

		cin >> InputNum;
		CurrentSum += InputNum;
		if (CurrentSum < InputNum)
			CurrentSum = InputNum;
		if (CurrentSum > MaxSum)
			MaxSum = CurrentSum;
	}
	cout << MaxSum;

	return 0;
}
