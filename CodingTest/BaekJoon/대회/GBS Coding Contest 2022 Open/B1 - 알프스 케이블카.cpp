
/*
 *B1�� - ������ ���̺�ī
 *
 *
 *�� ������� ���� ��������� �Ÿ��� �ִܰŸ��̹Ƿ�
 *
 *�� �Ÿ��� �������� ����Ѵ�.
 *
 *
 */

#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;

	cin >> N;
	long long sum = 0;
	long long prev = 0;
	for (int i = 0; i < N; i++)
	{
		long long inputNum = 0;

		cin >> inputNum;

		if (i == 0)
		{
			prev = inputNum;
			continue;
		}

		sum += abs(inputNum - prev) * abs(inputNum - prev) + (prev + inputNum) * (prev + inputNum);
		prev = inputNum;
	}

	cout << sum;

	return 0;
}
