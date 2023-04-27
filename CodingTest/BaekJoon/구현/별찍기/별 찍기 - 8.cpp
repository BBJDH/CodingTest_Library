/*
 *
 *2445 - �� ��� - 8
 *
 *
 *�� �� �ٸ��� ��, �� ����, �� ������ �ݺ������� ����Ѵ�
 *
 *���� 1���� N���� ��� �� ������ (N-i)*2�� ��Ģ���� ���ư���
 *
 *N ���� �����ߴٸ� �̹��� N-1���� 1���� �� �Ʒ� ��Ī�� �ǵ��� ����Ѵ�.
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

	for (int i = 1; i <= N; i++)
	{
		//�� ���
		for (int Star = 0; Star < i; Star++)
		{
			cout << "*";
		}
		for (int Blank = 0; Blank < (N - i) * 2; Blank++)
		{
			cout << " ";
		}
		for (int Star = 0; Star < i; Star++)
		{
			cout << "*";
		}
		cout << "\n";
	}
	for (int i = N - 1; i > 0; i--)
	{
		//�� ���
		for (int Star = 0; Star < i; Star++)
		{
			cout << "*";
		}
		for (int Blank = 0; Blank < (N - i) * 2; Blank++)
		{
			cout << " ";
		}
		for (int Star = 0; Star < i; Star++)
		{
			cout << "*";
		}
		cout << "\n";
	}

	return 0;
}