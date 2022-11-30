/*
 *18111 - 마인크래프트
 *
 *블록하나를 캐는 비용 - 2초
 *블록하나를 채우는 비용 - 1초
 *
 *
 *최소높이 0에서 최대 높이는 블록중 최대 높이로 접근을 하되,
 *보유 블록이 0인경우를 고려하여 예외처리를 하자
 *
 */

#include <iostream>

using namespace std;

int N = 0, M = 0, B = 0;
int Map[500][500]{};


int CalcTime(int const Num)
{
	if (Num > 0)
		return Num;
	else
		return Num * (-2);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> B;

	int sumBlock = 0;
	int maxHeight = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			int inputNum = 0;
			cin >> inputNum;
			sumBlock += inputNum;
			Map[x][y] = inputNum;
			maxHeight = max(maxHeight, inputNum);
		}
	}

	int minTime = 1234567891;
	int maxBlock = (sumBlock + B) / (N * M);
	int resultHeight = 0;
	for (int currnet = maxHeight; currnet >= 0; currnet--)
	{
		//if (currnet > maxHeight)
		//	break;
		if (currnet > maxBlock) continue;

		int totalTime = 0;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				totalTime += CalcTime(currnet - Map[x][y]);
			}
		}

		if (minTime > totalTime)
			resultHeight = currnet;
		minTime = min(minTime, totalTime);
	}

	cout << minTime << " " << resultHeight;
	return 0;
}