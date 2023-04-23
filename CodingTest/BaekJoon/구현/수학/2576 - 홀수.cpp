/*
 *2576 - 홀수
 *
 *문제의 요구사항대로 수를 입력받아 홀수를 판별한다.
 *
 *최소수를 100이상으로 두고 min 처리를 했을 때
 *
 *입력 받는 수는 99이하이므로
 *
 *min이 100으로 반복문을 빠져나온다면
 *홀수는 존재하지 않았던 것이다.
 *
 *min이 100인경우 -1을 출력하고 프로그램을 종료한다.
 *
 *
 */

#include <iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int Sum = 0, MinNum = 100;

	for (int i = 0; i < 7; i++)
	{
		int InputNum = 0;
		cin >> InputNum;

		if (InputNum % 2 == 1)
		{
			Sum += InputNum;
			MinNum = min(MinNum, InputNum);
		}
	}
	if (MinNum == 100)
	{
		cout << -1;
		return 0;
	}

	cout << Sum << "\n" << MinNum;
	return 0;
}