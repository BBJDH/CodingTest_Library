/*
 *5565 - ������
 *
 *�� �ݾ� �հ迡�� 9���� ������ ������ ���� �ѱ��� å ������ ����Ѵ�.
 *
 *�䱸���״�� �����Ѵ�.
 *
 */

#include<iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int Money = 0;
	cin >> Money;

	for (int i = 0; i < 9; i++)
	{
		int InputNum = 0;
		cin >> InputNum;
		Money -= InputNum;
	}
	cout << Money;
	return 0;
}