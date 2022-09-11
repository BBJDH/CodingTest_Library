
#include<iostream>
#include<vector>
using namespace std;


vector<int> Bottles{};
int BottleNum = 0;
int FriendNum = 0;


/*
임의의 수로 나눠줄때 그 인원이 지정인원보다 크거나 같다면 left를 업데이트 (더 큰수로 나눌 수 있다는 의미 이므로)
작다면 Right를 업데이트(현재 수로 나누기에는 막걸리가 부족하므로 더 작은 크기인 왼쪽 값에서 탐색)
나누어진 수가 같은경우 포함하여 left로 업데이트 하였으므로 마지막에 Left로 반환
*/

int GetDivide(int const Num)
{
	int DivideCount = 0;
	for (int const& Elem : Bottles)
	{
		DivideCount += Elem / Num;
	}
	return DivideCount;
}


void Solution()
{
	long long Left = -1;
	long long Right = INT32_MAX;
	long long Mid = 0;
	while (Left + 1 < Right)
	{
		Mid = (Left + Right) / 2;

		if (GetDivide(static_cast<int>(Mid)) >= FriendNum)
			Left = Mid;
		else
			Right = Mid;
	}
	cout << Left;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> BottleNum >> FriendNum;

	while (BottleNum--)
	{
		int InputBottle = 0;
		cin >> InputBottle;
		Bottles.push_back(InputBottle);
	}
	Solution();


	return 0;
}
