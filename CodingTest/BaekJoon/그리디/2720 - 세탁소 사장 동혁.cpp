/*
 *2720 - ��Ź�� ���� ����
 *
 *���� ū �������� ���ʴ�� ���� �������� ���� ���� ī���� �Ѵ�.
 *
 *������ ������ ī�����ϸ� �Ž������� �����Ͽ� ��ϱ��� ����Ѵ�.
 *
 *���� ī���õ� �������� ������ ����Ѵ�.
 *
 *���� ��ü ������ TestCase �� ��ŭ �ݺ��ϱ����� �ݺ����� �ѹ��� ��������.
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