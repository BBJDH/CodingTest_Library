
#include<iostream>
#include<vector>
using namespace std;


vector<int> Bottles{};
int BottleNum = 0;
int FriendNum = 0;


/*
������ ���� �����ٶ� �� �ο��� �����ο����� ũ�ų� ���ٸ� left�� ������Ʈ (�� ū���� ���� �� �ִٴ� �ǹ� �̹Ƿ�)
�۴ٸ� Right�� ������Ʈ(���� ���� �����⿡�� ���ɸ��� �����ϹǷ� �� ���� ũ���� ���� ������ Ž��)
�������� ���� ������� �����Ͽ� left�� ������Ʈ �Ͽ����Ƿ� �������� Left�� ��ȯ
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
