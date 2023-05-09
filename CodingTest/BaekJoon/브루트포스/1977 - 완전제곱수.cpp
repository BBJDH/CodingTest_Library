/*
 *1977 - 완전제곱수
 *
 *
 *제곱할 수의 범위는 1에서 100까지 뿐이다.
 *
 *따라서 1에서 100까지 반복문을 통과하며
 *입력받은 최대 최소값 사이의 범위에 걸리는경우
 *
 *최소값을 기록하고 Sum에 그 값을 누적한다.
 *
 *Sum이 0이라면 어떤 수도 구간에 들어오지 않았으므로 -1
 *
 *이외의 경우는 최대값과 최소값을 출력한다.
 *
 *
 */

#include <iostream>

using namespace std;


int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int RangeOfMin = 0, RangeOfMax = 0;
	int MinNum = 10000, Sum = 0;
	cin >> RangeOfMin >> RangeOfMax;

	for (int i = 1; i <= 100; i++)
	{
		int SquareNum = i * i;
		if (SquareNum >= RangeOfMin and SquareNum <= RangeOfMax)
		{
			Sum += SquareNum;
			MinNum = min(MinNum, SquareNum);
		}
	}

	if (Sum == 0)
	{
		cout << -1;
	}
	else
	{
		cout << Sum << "\n" << MinNum << "\n";
	}


	return 0;
}