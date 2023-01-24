/*
 * 10870 - �Ǻ���ġ�� 5
 *
 * DP�� ����� dp[1]=dp[2]=1 �� ���� �־�ΰ�
 * dp[i] = dp[i-1]+dp[i-2]�� ������ �޸������̼� �Ѵ�.
 *
 * ������� int ������ �Ѿ�� ����
 *
 *
 */

#include <iostream>
#define Size 21
using namespace std;


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int DP[100]{};
	DP[1] = 1;
	DP[2] = 1;
	for (int i = 3; i <= Size; i++)
	{
		DP[i] = DP[i - 1] + DP[i - 2];
	}
	int n = 0;
	cin >> n;
	cout << DP[n];

	return 0;
}