/*
 *14613 - 너의 티어는?
 *
 * 20회를 모두 진다면 1000점, 모두 이긴다면 3000점이다
 *
 *이것을 DP로 구성해서 BottomUp으로 진행한다.
 *
 *
 *점수를 0~ 40으로 매핑(20패 = 0 20승 40)
 *
 *모두다 이긴다면 40에서 다이아,
 *2500을 30으로 매핑 30~39까지는 플래티넘
 *골드는 20에서 29까지
 *실버는 10~ 19
 *브론즈는 9 이하로 계산한다.
 *
 *
 */

#include <iostream>

using namespace std;

//20이 시작점수, 모두다 지면 0점, 모두다 이기면 40점
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


	//* 모두다 이긴다면 40에서 다이아,
	//* 2500을 30으로 매핑 30~39까지는 플래티넘
	//* 골드는 20에서 29까지
	//* 실버는 10~19
	//* 브론즈는 9 이하로 계산한다.
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