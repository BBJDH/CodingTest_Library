/*
 *2522 - �� ��� - 12
 *
 *������ �䱸���״�� �����Ѵ�.
 *
 *�Է¹��� N�� ���Ͽ� ���� ������ �������� �ݺ����� �ۼ��ߴ�
 *
 *���� N-(���� ����)��ŭ ������ ����� ���� �����ϰ�,
 *���� ���� ������ŭ ����Ѵ�.
 *
 *�̰��� �ٽ� �Ųٷ� N-1���� ����Ѵ�.
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

		for (int Star = N - i; Star > 0; Star--)
		{
			cout << " ";
		}
		for (int Blank = 0; Blank < i; Blank++)
		{
			cout << "*";
		}
		cout << "\n";
	}

	for (int i = N - 1; i > 0; i--)
	{

		for (int Star = N - i; Star > 0; Star--)
		{
			cout << " ";
		}
		for (int Blank = 0; Blank < i; Blank++)
		{
			cout << "*";
		}
		cout << "\n";
	}

	return 0;
}