/*
 *
 *4883 - 삼각 그래프
 *
 *첫줄에서의 DP는 가운데 점과의 합산으로 기록한다
 *
 *그다음줄의 DP는 윗줄에서의 각 최소값만을 취해 합한다
 *
 *이후 마지막줄에 도달하면 DP[3]에서의 최솟값과 가운데 수의 합을 출력
 *
 *
 */



#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;
	int TestCase = 1;
	vector<long long>DP{};
	while (true)
	{
		cin >> N;

		if (N == 0)
			break;

		for (int i = 0; i < N; i++)
		{
			vector<long long> inputNums{};
			inputNums.resize(3);

			for (int i = 0; i < 3; i++)
			{
				cin >> inputNums[i];
			}


			if (i == 0)
			{
				DP = inputNums;
				DP[0] = 1234567890;
				DP[1] = inputNums[1];
				DP[2] = DP[1] + inputNums[2];

				continue;
			}
			if (i == 1)
			{
				//두번째줄은 첫줄의 가운데 수만이 선택된다
				long long centerNum = DP[1];

				DP[0] = inputNums[0] + centerNum;
				DP[1] = inputNums[1] + min(DP[2], min(DP[0], centerNum));
				DP[2] = inputNums[2] + min(DP[2], min(DP[1], centerNum));
				continue;
			}
			long long leftDP = DP[0];
			long long centerDP = DP[1];

			DP[0] = inputNums[0] + min(DP[0], DP[1]);
			DP[1] = inputNums[1] + min(min(DP[0], leftDP), min(DP[1], DP[2]));
			DP[2] = inputNums[2] + min(DP[2], min(DP[1], centerDP));
		}
		cout << TestCase << ". " << DP[1] << "\n";
		TestCase++;
	}


	return 0;
}