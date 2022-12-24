/*
 *14613 - ���� Ƽ���?
 *
 * 20ȸ�� ��� ���ٸ� 1000��, ��� �̱�ٸ� 3000���̴�
 *
 *�̰��� DP�� �����ؼ� BottomUp���� �����Ѵ�.
 *
 *
 *������ 0~ 40���� ����(20�� = 0 20�� 40)
 *
 *��δ� �̱�ٸ� 40���� ���̾�,
 *2500�� 30���� ���� 30~39������ �÷�Ƽ��
 *���� 20���� 29����
 *�ǹ��� 10~ 19
 *������ 9 ���Ϸ� ����Ѵ�.
 *
 *
 */

#include <iostream>

using namespace std;

//20�� ��������, ��δ� ���� 0��, ��δ� �̱�� 40��
double DP[21][41]{};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	double W = 0, L = 0, D = 0;

	cin >> W >> L >> D;

	DP[0][20] = 1.0f;

	for (int i = 1; i <= 20; i++)
	{
		for (int score = 0; score <= 40; score++)
		{
			DP[i][score + 1] += DP[i - 1][score] * W;
			DP[i][score - 1] += DP[i - 1][score] * L;
			DP[i][score] += DP[i - 1][score] * D;
		}
	}
	double bronze = 0, silver = 0, gold = 0, platinum = 0, diamond = 0;


	//* ��δ� �̱�ٸ� 40���� ���̾�,
	//* 2500�� 30���� ���� 30~39������ �÷�Ƽ��
	//* ���� 20���� 29����
	//* �ǹ��� 10~19
	//* ������ 9 ���Ϸ� ����Ѵ�.
	for (int i = 0; i <= 40; i++)
	{
		if (i == 40)
			diamond += DP[20][i];
		else if (i >= 30)
			platinum += DP[20][i];
		else if (i >= 20)
			gold += DP[20][i];
		else if (i >= 10)
			silver += DP[20][i];
		else
			bronze += DP[20][i];

	}
	cout << fixed;
	cout.precision(8);

	cout << bronze << "\n";
	cout << silver << "\n";
	cout << gold << "\n";
	cout << platinum << "\n";
	cout << diamond << "\n";


	return 0;
}