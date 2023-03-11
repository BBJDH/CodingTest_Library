/*
 *2747 - �Ǻ���ġ ��
 *
 *2�� ���������� ���� �̸� ��ȭ������ �Ͽ�
 *
 *DP[i] = DP[i-1] + DP[i-2]�� �޸������̼� �Ѵ�.
 *
 *N���� ����� �Ϸ��ߴٸ� �� ���� ����ϰ� ����
 *
 */
#include <iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int DP[46]{};
	DP[0] = 0;
	DP[1] = 1;
	DP[2] = 1;
	int N = 0;
	cin >> N;

	for (int i = 2; i <= N; i++)
	{
		DP[i] = DP[i - 1] + DP[i - 2];
	}
	cout << DP[N];

	return 0;
}