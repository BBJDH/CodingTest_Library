/*
 * 16953 - A �� B
 *
 *�ι�°�� �Է¹��� DestNum���� �Ųٷ� �����Ѵ�.
 *
 *2 162
 *162 ->81 -> 8 -> 4-> 2
 *
 *DestNum�� Ȧ����� 10���� ������(���� �ڸ��� ������Ƿ� -1ó���� �ʿ����.)
 *¦���̸� 2�� ����� �����Ѵ�.
 *
 *DestNum�� Ȧ�� �϶� �����ڸ��� 1�� �ƴѰ�� StartNum�� ������ �� �����Ƿ�
 *�ݺ��� Ż��ó���Ѵ�.
 *
 *�׷��� Ž���� ���� Ǯ���� �ְ����� ���Ͱ��� �׸��� �� �����ϴ�.
 *�׻� �ּҿ������� �ذ� �����ϴ�.
 *
 */

#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int StartNum = 0, DestNum = 0;
	int Count = 0;
	cin >> StartNum >> DestNum;

	while (DestNum > StartNum)
	{
		if (DestNum % 2 == 1)
		{
			if (DestNum % 10 != 1)
				break;
			DestNum /= 10;
		}
		else
			DestNum /= 2;

		Count++;
		if (StartNum == DestNum)
		{
			cout << Count + 1;
			return 0;
		}
	}
	cout << -1;

	return 0;
}