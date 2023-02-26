/*
 *13866 - �� ������
 *
 *���� ���� �������°� ������ ����� 1��� 4���� ���� ¥��,
 *2��� 3���� ���� ¥�� ������� ��Ģ�� ��������.
 *
 *���� �Է¹޴� ������ Min�� Max�� ���� �з��Ͽ� ���� ¥��
 *
 *���� ���� ������ ������ִ� �ڵ带 �ۼ��Ѵ�.
 *
 *�� ������ ������� �� ���������� �˼��� ����.
 *
 *���� �� ���� ���� ���밪���� ����Ѵ�.
 *
 *���� ������ 0~ 10000���� ���ѵǹǷ� �̸� ������ Min�� Max�� �ʱ�ȭ�Ѵ�.
 *
 *
 */
#include<iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int NumberOfMin = 100000;
	int NumberOfMax = -1;
	int Sum = 0;
	for (int i = 0; i < 4; i++)
	{
		int NumOfInput = 0;
		cin >> NumOfInput;
		NumberOfMin = min(NumberOfMin, NumOfInput);
		NumberOfMax = max(NumberOfMax, NumOfInput);
		Sum += NumOfInput;
	}
	int Team1 = (NumberOfMin + NumberOfMax);
	int Team2 = Sum - Team1;
	cout << abs(Team1 - Team2);


	return 0;
}