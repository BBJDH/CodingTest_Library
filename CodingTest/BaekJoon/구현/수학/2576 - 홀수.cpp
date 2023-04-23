/*
 *2576 - Ȧ��
 *
 *������ �䱸���״�� ���� �Է¹޾� Ȧ���� �Ǻ��Ѵ�.
 *
 *�ּҼ��� 100�̻����� �ΰ� min ó���� ���� ��
 *
 *�Է� �޴� ���� 99�����̹Ƿ�
 *
 *min�� 100���� �ݺ����� �������´ٸ�
 *Ȧ���� �������� �ʾҴ� ���̴�.
 *
 *min�� 100�ΰ�� -1�� ����ϰ� ���α׷��� �����Ѵ�.
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