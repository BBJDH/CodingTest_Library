/*
 *10996 - �� ��� - 21
 *
 * ��Ģ�� Ǯ���
 *
 * �Է¹��� �� InputNum�� ���Ͽ� 2N ��ŭ ������ ����Ѵ�
 * (1�ΰ�� 2�������� ������ ��µ����� ������ ������ ���๮�� �ѹ���
 * �����ϰ� ����ó���ȴ�.)
 *
 *�׸��� �� ���ι�ȣ�� Ȧ����� Ȧ�� ��°�� ����,
 *¦����� ¦�� ��°�� ���� ����Ѵ�.
 *
 * ���� ����� �ϴ� �Լ��� �ۼ��ϰ�,
 *
 * �Է¹��� InputNum*2 ��ŭ�� ���ο� ����
 * �Լ��� ȣ���Ѵ�.
 *
 *
 */

#include <iostream>

using namespace std;

void PrintStar(int const Num, int const LineNum)
{
	for (int i = 1; i <= Num; i++)
	{
		if (i % 2 == LineNum % 2)
		{
			cout << "*";
		}
		else
		{
			cout << " ";
		}
	}
}


int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int InputNum = 0;
	cin >> InputNum;

	for (int i = 0; i < InputNum * 2; i++)
	{
		PrintStar(InputNum, i + 1);
		cout << "\n";
	}

	return 0;
}