/*
 *
 *2443 - �� ��� - 6
 *
 *
 *������ �䱸���״�� ����⸦ �����Ѵ�
 *
 *���� 1 ������� 0�̶�� �Ѵٸ�,
 *
 *
 *N = 5 �� ��,
 *
 *111111111  �� ���� 0��,  �� 9��
 *01111111   �� ���� 1��,  �� 7��
 *0011111	 �� ���� 2��,  �� 5��
 *000111	 �� ���� i��,  �� (N-i)*2-1
 *00001		 �� ��Ģ���� �ݺ����� �����Ѵ�.
 *
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
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int Blank = 0; Blank < i; Blank++)
		{
			cout << " ";
		}
		for (int Star = 0; Star < (N - i) * 2 - 1; Star++)
		{
			cout << "*";
		}
		cout << "\n";
	}

	return 0;
}