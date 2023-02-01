/*
 *2231 - ������
 *
 *�Է��� �鸸������ �ڿ����� ���ѵǹǷ�
 *
 *���Ʈ������ Ǯ�� �����ϴ�.
 *
 *1���� ������ �鸸���� �����ڷμ� �Է¹��� ���� ����������� �˻��Ѵ�.
 *
 *���� ������ �����Ѵٸ� �ش� ���� ��� �� ����
 *
 *�鸸���� Ž���� �����ߴٸ� 0�� ��� �� �����Ѵ�.
 *
 *
 */

#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, Result = 0;
	cin >> N;

	for (int i = 1; i <= 1000000; i++)
	{
		int MakeNum = i;
		int Candidate = i;
		while (Candidate)
		{
			MakeNum += Candidate % 10;
			Candidate /= 10;
		}
		if (MakeNum == N)
		{
			cout << i;
			return 0;
		}
	}
	cout << 0;
	return 0;
}