/*
 *13258 - ����+����
 *
 *�ش� ������ ��� 4�� �����Ǿ� ������
 *
 *�ܼ� ��Ģ�������� Ǯ�� ����ϴ�
 *
 *������ Ǯ��� �ܼ� �� �ܰ��� Ƽ������� �ѷ��� �ǰ�
 *���� ���� �ܰ� ��ŭ Ƽ���� �����ϴµ�,
 *�� �� �� �常�� ������ ������ ���ڸ�ŭ�� ���� �޴´�
 *
 *���� ��� ���� �ܰ���
 *
 *���ΰ��� ���� �ܰ� + (���ΰ��� ���� �ܰ� * �����ϼ� * ����)/�� �ܰ�
 *
 *���̵� ������� (����� 3)
 *
 */


#include <iostream>

using namespace std;


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	double n = 0;
	double interest = 0;
	double day = 0;
	double total = 0;
	double first = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		double inputNum = 0;

		cin >> inputNum;

		if (i == 0)
			first = inputNum;

		total += inputNum;
	}
	cin >> interest >> day;

	printf("%.10f", first + (first * day * interest) / total);

	return 0;
}