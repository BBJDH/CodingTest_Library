#include <iostream>

using namespace std;

int NumberOfBottle = 0;

int Buy_Water(int NumberToMake)
{
	int LowerBit = NumberOfBottle;
	for (int i = 31; i > 0; i--)
	{
		if (NumberToMake == 0)
		{
			if (LowerBit == 0)
				return 0;
			return (1 << i) - LowerBit;
		}
		if (NumberOfBottle & (1 << (i - 1)))
		{
			LowerBit &= ~(1 << (i - 1));
			NumberToMake--;

		}

	}
	return 0;
}



int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int NumberToMake = 0;
	cin >> NumberOfBottle >> NumberToMake;
	cout << Buy_Water(NumberToMake);
	return 0;
}

/*
타겟 넘버를 이진 변환, 맨 앞자리부터 만들 병수만큼 1을 탐색
- 끝까지 찾았는데 만들 병수 보다 1의 갯수가 적다면 구매할 필요 없음

10의 7승 이므로

*/
