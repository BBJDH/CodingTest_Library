/*
 *1789 - ������ ��
 *
 *�ڿ������� �� �̹Ƿ� ���� ���� �ڿ����� 1���� �ڷʴ�� ���ذ���
 *
 *1���� N������ �� ���� = N(N+1)/2 �̹Ƿ�
 *
 * S >=N(N+1)/2 �� �ִ밪 N�� ã���� �ȴ�.
 *
 *�����غ��� 2*S >= N(N+1) ���谡 �����ϰ�
 *�̸� ���� ���ϱ� ���� N(N+1)�� ���� sqrt �Լ��� Ȱ���Ѵ�.
 *
 *�� N(N+1)�� �ƴ� N�� �������� �ٻ��Ͽ� �ٻ簪���κ��� Ž���ϸ�ȴ�.
 *
 */

#include<iostream>
#include <math.h>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long S = 0, SearchNum = 0;
	cin >> S;
	SearchNum = static_cast<long long>(sqrt(S * 2));
	//�ٻ簪 ���

	if (SearchNum * (SearchNum + 1) / 2 <= S)	//���� �����Ѵٸ� �״�� ���
	{
		cout << SearchNum;
		return 0;
	}
	//�׷��� ������� -1 ���
	cout << SearchNum - 1;

	return 0;
}