/*
 *11727 - 2xn Ÿ�ϸ� 2
 *
 *n�� 1�ΰ�� 1
 *n�� 2�ΰ�� 3
 *3�ΰ�� (n-2)*2 + n-1
 *.
 *.
 *.
 *
 *(�ǳ�Ÿ���� Ⱦ���� ������� �Ǵ� 2*2�� ���ΰ���̹Ƿ� x2 + ������ ���常 �� ���)
 *
 *���������� ������ ���� 10007�� %ó���ϴ°��� ���� ����.
 *
 *
 */


#include<iostream>


using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int DP[1001]{};
	DP[1] = 1;
	DP[2] = 3;
	int N = 0;
	cin >> N;
	for (int i = 3; i <= N; i++)
	{
		DP[i] = (DP[i - 1] + DP[i - 2] * 2) % 10007;
	}


	cout << DP[N];


	return 0;
}