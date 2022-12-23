/*
 *
 *11058 - ũ������
 *
 *�װ��� ����� ���� �����ϰ� ǥ���ϸ�,
 *����� +1 (��� 1)
 *����� ���� (���纻 ������Ʈ) (��� 2)
 *���� �� �� �ٿ��ֱ� +���纻��ŭ �� ���� (��� 1)
 *
 *
 *
 *��ư�� 6�� ������ ��� ������ DP[N] = N�� �����Ѵ�. (7���� ������ �ؾ� 9�� Ŀ��)
 *
 *�׸��� ���� �ٿ��ִ� ��츦 ���� �Ʒ������� �߶� �����ϴ� ��츦 ���� �ִ� ���� DP�� �����Ѵ�.
 *(���� �ٿ��ֱ��� �ּҺ���� 2+1�� 3�̴�, �ٿ��ֱ� �ѹ� ����)
 *
 *ũ�Ⱑ int�� �Ѿ�Ƿ� long long���� DP�� �����.
 *
 */


#include<iostream>

using namespace std;

int Result = 0;

long long DP[101]{};


//topdown �ݺ���
void MakeDP()
{
	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 3;
	DP[4] = 4;
	DP[5] = 5;
	DP[6] = 6;

	for (int i = 7; i < 101; i++)
	{
		for (int copy = 1; copy + 2 < i; copy++)
		{
			DP[i] = max(DP[i], DP[i - 2 - copy] * (copy + 1));
		}
	}
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;

	cin >> N;
	MakeDP();
	cout << DP[N];
	return 0;
}