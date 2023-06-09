/*
 *2720 - 세탁소 사장 동혁
 *
 *가장 큰 동전부터 차례대로 값을 내려가며 동전 수를 카운팅 한다.
 *
 *쿼터의 갯수를 카운팅하며 거스름돈을 감산하여 페니까지 계산한다.
 *
 *이후 카운팅된 동전들의 갯수를 출력한다.
 *
 *위의 전체 과정을 TestCase 수 만큼 반복하기위해 반복문을 한번더 덧씌웠다.
 *
 *
 *
 */
#include <iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int ValueOfCoin[4] = { 25,10,5,1 };
	int CountOfCoin[4]{};


	int TestCase = 0;
	cin >> TestCase;

	while (TestCase--)
	{
		int InputMoney = 0;
		cin >> InputMoney;

		fill_n(CountOfCoin, 4, 0);

		for (int i = 0; i < 4; i++)
		{
			while (InputMoney >= ValueOfCoin[i])
			{
				InputMoney -= ValueOfCoin[i];
				CountOfCoin[i]++;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			cout << CountOfCoin[i] << " ";
		}
		cout << "\n";
	}


	return 0;
}