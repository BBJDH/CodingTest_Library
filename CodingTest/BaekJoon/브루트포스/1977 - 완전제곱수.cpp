/*
 *1977 - ����������
 *
 *
 *������ ���� ������ 1���� 100���� ���̴�.
 *
 *���� 1���� 100���� �ݺ����� ����ϸ�
 *�Է¹��� �ִ� �ּҰ� ������ ������ �ɸ��°��
 *
 *�ּҰ��� ����ϰ� Sum�� �� ���� �����Ѵ�.
 *
 *Sum�� 0�̶�� � ���� ������ ������ �ʾ����Ƿ� -1
 *
 *�̿��� ���� �ִ밪�� �ּҰ��� ����Ѵ�.
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