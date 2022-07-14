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
Ÿ�� �ѹ��� ���� ��ȯ, �� ���ڸ����� ���� ������ŭ 1�� Ž��
- ������ ã�Ҵµ� ���� ���� ���� 1�� ������ ���ٸ� ������ �ʿ� ����

10�� 7�� �̹Ƿ�

*/
