
/*

1003 - 피보나치 함수

피보나치 수열의 결과 값이 아닌 더해진 0 과 1이 필요하다

따라서 구조체로 만들어서 DP를 구성한다

0, 1 ,,,, 로 시작하므로

초기 점화식은 {1,0}, {0,1} 로 시작한다

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

