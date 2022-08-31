

/*
랜선 자르기

주어진 수들의 합을 지정된 목표 랜선 수로 나눔, 이 수가 최대수
최대수로부터 아래로 브루트포스 -> 시간초과!
이분탐색을 활용 1부터 위에서 구한 최대수까지

*/
#include<iostream>
#include<vector>

using namespace std;

vector<long long> Cables{};

long long DivideCables(long long const CableSize)
{
	long long DivideCount = 0;
	for (long long const& Elem : Cables)
	{
		DivideCount += Elem / CableSize;
	}
	return DivideCount;
}

void Solution(long long const DivideNum, long long const Sum)
{
	long long StartSize = 1;
	long long EndSize = Sum / DivideNum;
	long long CurrentSize = 0;
	long long answer = 0;
	while (StartSize <= EndSize)
	{
		CurrentSize = (EndSize + StartSize) / 2;
		long long const CableNum = DivideCables(CurrentSize);
		if (CableNum >= DivideNum)
		{
			answer = CurrentSize;
			StartSize = CurrentSize + 1;
		}
		else
			EndSize = CurrentSize - 1;
	}
	cout << answer;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long InputCableCount = 0;
	long long DivideNum = 0;
	long long Sum = 0;
	cin >> InputCableCount >> DivideNum;

	while (InputCableCount--)
	{
		long long InputSize = 0;
		cin >> InputSize;
		Cables.push_back(InputSize);
		Sum += InputSize;
	}
	Solution(DivideNum, Sum);

	return 0;
}
