/*
 *
 * 1010 - �ٸ� ����
 *
 *������ ������ ���� ����Ʈ�� ������ ����Ʈ���� �����̹Ƿ�
 *
 *������ ����Ʈ�� N ���� ����Ʈ�� r �̶�� �ϸ�
 *
 *nCr �� ���� ������� ����ȴ�.
 *
 *nCr �� n! / r!(n-r)! ����
 *
 *������ n!�� r! �� ���丮���� �״�� ���ϸ� long long �������� ��Ż�Ѵ�.
 *
 *�׷��ٸ� ��� ���ؾ� �ϴ°�?
 *
 *nCr�� ����غ��� ������ ���� �����ȴ�
 *
 * n-r�� r�� �������� Count ��� �Ѵٸ�
 *
 *N���� Count����ŭ�� ������ / Count! ���� �����Ѵ�.
 *
 *������ �и� ���� ���� ���� ���� ����ϸ� ���� long long�� ��Ż�� ����� �ֱ� ������
 *
 *Count��ŭ ���� �ݺ����� ���� ���ϱ�� �����⸦ ���� ����Ͽ� �����Ѵ�.
 *
 *
 */

#include<iostream>

using namespace std;

void GetCombination(int const N, int const R)
{
	int Count = 0;
	int Result = 1;
	Count = min(R, N - R);

	for (int i = 0; i < Count; i++)
	{
		Result *= (N - i);
		Result /= (i + 1);
	}
	cout << Result << "\n";
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, R = 0, TestCase = 0;
	cin >> TestCase;

	while (TestCase--)
	{
		cin >> R >> N;
		GetCombination(N, R);
	}

	return 0;
}