/*
 *2490 - ������
 *
 *0�� ���������� ����� ��� �����ϴ�
 *
 *0�� - ��, 1�� - ��, 2�� - ��, 3�� - ��, 4�� - ��
 *
 *�̷��� ���ε� �迭�� �����ϰ�
 *
 *�־��� �װ��� ������ 0�� ������ ī�����Ͽ�
 *
 *�迭�� �ε����� ���ε� ����� ����Ѵ�.
 *
 */

#include <iostream>

using namespace std;

char ResultOfCount[5] = { 'E','A','B','C','D' };

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 3; i++)
	{
		int CountOfZero = 0;
		for (int i = 0; i < 4; i++)
		{
			int InputNum = 0;
			cin >> InputNum;
			if (InputNum == 0)
			{
				CountOfZero++;
			}
		}
		cout << ResultOfCount[CountOfZero] << "\n";
	}

	return 0;
}