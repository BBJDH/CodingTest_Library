/*
 *15963 - CASIO
 *
 *int�� ������ ���� ǥ�� ������ ����� ����
 *
 *10�� �ڸ��� ��� �Է¹޴´ٸ� int�δ� ǥ���� �Ұ��ϴ�
 *
 *99���� ���� �� �ְ� long long �ڷ����� ����Ѵ�.
 *
 */

#include <iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	long long N = 0, M = 0;

	cin >> N >> M;

	if (N == M)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}


	return 0;

}