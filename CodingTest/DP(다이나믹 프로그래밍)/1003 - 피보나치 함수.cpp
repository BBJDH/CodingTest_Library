
/*

1003 - �Ǻ���ġ �Լ�

�Ǻ���ġ ������ ��� ���� �ƴ� ������ 0 �� 1�� �ʿ��ϴ�

���� ����ü�� ���� DP�� �����Ѵ�

0, 1 ,,,, �� �����ϹǷ�

�ʱ� ��ȭ���� {1,0}, {0,1} �� �����Ѵ�

*/

#include<iostream>

using namespace std;


struct _int2
{
	int ZeroCount;
	int OneCount;
};

_int2 DP[41]{ {1,0},{0,1}, };

_int2 operator+(_int2 const& First, _int2 const& Second)
{
	return { First.ZeroCount + Second.ZeroCount  , First.OneCount + Second.OneCount };
}

void MakeDPArr()
{
	for (int i = 2; i < 41; i++)
	{
		DP[i] = DP[i - 1] + DP[i - 2];
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	MakeDPArr();
	int TestCase = 0;

	cin >> TestCase;

	while (TestCase--)
	{
		int InputNum = 0;

		cin >> InputNum;

		cout << DP[InputNum].ZeroCount << " " << DP[InputNum].OneCount << "\n";
	}

	return 0;
}

