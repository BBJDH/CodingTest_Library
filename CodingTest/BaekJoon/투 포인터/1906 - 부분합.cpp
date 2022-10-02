
/*
1806 - 부분합

누적합 DP와 투포인터를 사용하는 문제이다
우선 입력을 받으면서 누적합을 모두 구해둔다 (차후 부분합에서 쓰기 위함 시간복잡도 절약)
이후 Left포인터와 Right포인터를 맨 왼쪽에서부터 시작한다(부분합 사용을 위해 0자리를 비우고 1부터 숫자를 기록해둔다)
Left - Right 까지의 합이 목표합 미만이라면 Right를 오른쪽으로 늘려 합공간을 늘리고
Left - Right 까지의 합이 목표합 이상이라면 Left를 오른쪽으로 늘려 합공간을 줄여서 최적길이를 찾는다
(합이 목표합 이상일때마다 Length를 업데이트해준다)
합을 구할때는 지정한 [Right] 인덱스의 누적합  - [Left-1] 인덱스의 누적합이 Left - Right의 누적합이 된다
(이때 Left가 0부터 시작하는 경우 -1 배열접근 우려를 고려하여 0을 비워두고 데이터를 보관한다)
*/
#include<iostream>
#include<vector>

using namespace std;
vector<int> Sequence{};
vector<int> DP_Sum{};
int ArrSize = 0;
int TargetSum = 0;
int MinLength = 0;

int MakeSum(int const Left, int const Right)
{
	return DP_Sum[Right] - DP_Sum[Left - 1];
}


void TwoPointer()
{
	int Left = 1, Right = 1;

	while (Left <= Right and Right < Sequence.size())
	{
		int Sum = MakeSum(Left, Right);
		if (Sum >= TargetSum)
		{
			if (MinLength == 0)
				MinLength = Right - Left + 1;
			else
				MinLength = min(MinLength, Right - Left + 1);
			Left++;
		}
		else
			Right++;
	}
	cout << MinLength;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> ArrSize >> TargetSum;
	Sequence.push_back(0);
	DP_Sum.push_back(0);
	for (int i = 1; i <= ArrSize; i++)
	{
		int InputNum = 0;
		cin >> InputNum;
		Sequence.push_back(InputNum);
		DP_Sum.push_back(InputNum + DP_Sum[i - 1]);
	}
	TwoPointer();
	return 0;
}
