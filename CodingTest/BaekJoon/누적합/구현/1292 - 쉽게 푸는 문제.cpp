/*
 * 1292 - ���� Ǫ�� ����
 *
 * �������� �̿��� Ǯ����.
 *
 * �־��� ��Ģ�� ���� ���� ���� �迭�� �����Ѵ�.
 *
 * 1000���� ��� �迭�� ���� �� �־��� ������ ����
 * SumFromZero[Dest] - SumFromZero[Start - 1] �� ��ȯ�Ѵ�.
 *
 * �ѹ� �迭�� ����� ���� �迭�� �̿��� � �����̵� �������� ��ȯ ����������.
 *
 *
 * �Ǵ� �ܼ� ������ ���ؼ��� ���� �����ϴ�
 *
 * ���� �ջ�����߿� Start ~ Dest ������ �ش��ϴ� ��쿡�� Sum�� �ջ��Ͽ� ����Ѵ�.
 * �������� �Է��� �ѹ��� �־����Ƿ� ���� ������ ��ĺ��� �� ����� ����.
 *
 *
 */


#include<iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int SumFromZero[1001]{};
	int Sum = 0;
	int Num = 1;
	int Count = 0;
	for (int i = 1; i < 1001; i++)
	{
		Sum += Num;
		Count++;
		SumFromZero[i] = Sum;
		if (Count == Num)
		{
			Count = 0;
			Num++;
		}
	}

	//�Է�
	int Start = 0, Dest = 0;
	cin >> Start >> Dest;
	cout << SumFromZero[Dest] - SumFromZero[Start - 1];

	return 0;
}