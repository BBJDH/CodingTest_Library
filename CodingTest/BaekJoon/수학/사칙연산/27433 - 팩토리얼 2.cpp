/*
 *27433 - ���丮�� 2
 *
 *������ �䱸���״�� N���� �����Ͽ� ��� �ڿ����� �����ش�.
 *
 *�ٸ� 20!�� ��� 2432902008176640000 ���� int�� ������ �ʰ��ϹǷ�
 *
 *long long���� Result�� ����Ͽ� ����Ѵ�.
 *
 *
 */

#include <iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N = 0;
	long long Result = 1;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		Result = Result * i;
	}
	cout << Result;

	return 0;
}