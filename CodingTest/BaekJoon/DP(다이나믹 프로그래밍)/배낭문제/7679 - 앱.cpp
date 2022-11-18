/*
 *7579 - 앱
 *
 * 배낭문제인데 무게가 천만으로 너무 크다.
 *이런경우 무게가아닌 최대값이 10001인 비용으로 배낭을 구성한다
 *비용 0부터 시작해 10000까지 각 행에 해당하는 앱의 비용을 소비하여
 *이전과 비교해 최대의 바이트 크기를 갱신한다.
 *
 */

#include <iostream>
#include <vector>
using namespace std;

#define INF 10000001
struct _int2
{
	int ByteSize;
	int Cost;
};

int Knapsack[101][10001]{};
vector<_int2> Activated_Apps{};

int AppSize = 0;
int ByteNeeded = 0;


void MakeKnasack()
{
	for (int i = 1; i <= AppSize; i++)
	{
		for (int cost = 0; cost < 10001; cost++)
		{
			if (cost < Activated_Apps[i].Cost)
				Knapsack[i][cost] = Knapsack[i - 1][cost];
			else
				Knapsack[i][cost] = max(Knapsack[i - 1][cost], Activated_Apps[i].ByteSize + Knapsack[i - 1][cost - Activated_Apps[i].Cost]);
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> AppSize >> ByteNeeded;
	Activated_Apps.push_back({});

	for (int i = 0; i < AppSize; i++)
	{
		int byteSize = 0;
		cin >> byteSize;

		Activated_Apps.push_back({ byteSize,0 });
	}
	for (int i = 1; i <= AppSize; i++)
	{
		int cost = 0;
		cin >> cost;
		Activated_Apps[i].Cost = cost;
	}

	MakeKnasack();

	for (int i = 0; i < 10001; i++)
	{
		if (Knapsack[AppSize][i] >= ByteNeeded)
		{
			cout << i;
			break;
		}
	}

	return 0;
}