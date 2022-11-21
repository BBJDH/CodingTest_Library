/*
 *1193 - �м�ã��
 *�밢�� �������� ���ڸ� ��Ƴ�������
 *1���� ũ�ٸ� �ش� ������ 1�� ���� ���� �밢������ �Ѿ��
 *���� �밢������ 2���� ũ�ٸ� 2�� ���� ���� �밢���� �Ѿ��
 *3���� ũ�ٸ� 3�� ���� ���� �밢���� �Ѿ��
 *.
 *.
 *.
 *�� �밢������ 1���� �ش� �밢���� ����ϴ� �������� ǥ�ð� ����������
 *
 *�� �밢 �������� �����밢���� ���Ѿ���� ǥ�õ� ���� ������ ���� ����
 *1  2  3  4
 *1  2  3
 *1  2
 *1
 *���⿡ �� �밢�� ����+1�� ������
 *
 *1(1) 2(1) 3(1) 4(1)
 *1(2) 2(2) 3(2)
 *1(3) 2(3)
 *1(4)
 *
 *�� ���� ������ ���� ���缺�� ���̱� �����Ѵ�
 *���� �������׷� �ٲ� ������ָ�ȴ�
 *
 *����� �����ϴ� �� �밢���� ��� ���� Ȧ/¦�� ���� ����� �����ش�
 */


#include<iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int inputNum = 0;
	cin >> inputNum;

	int denominator = 1;
	while (inputNum > denominator)
	{
		inputNum -= denominator;
		denominator++;
	}
	if (denominator % 2)
		cout << (denominator + 1) - inputNum << "/" << inputNum;
	else
		cout << inputNum << "/" << (denominator + 1) - inputNum;
	return 0;
}