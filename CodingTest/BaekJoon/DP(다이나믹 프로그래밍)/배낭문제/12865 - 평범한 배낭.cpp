/*
12865 - 평범한 배낭

0-1 Knapsack Problem이며 정해진 점화식은 다음과 같다

DP[itemindex][weight] = max(DP[itemindex-1][weight], DP[itemindex-1][weight- item.weight] +item.value)
(현재 아이템에서의 최대 가치 = MAX(이전 아이템행의 최대 가치, 현재아이템이 추가된 경우의 최대 가치)


DP는 행이 아이템, 열이 무게인 2차원 배열이다, 예제를 적용해 보면,
		0 1 2 3 4  5 6  7
0-item  0 0 0 0 0 0  0  0
1-item  0 0 0 0 0 0  13 13
2-item  0 0 0 0 8 8  13 13
3-item  0 0 0 6 8 8  13 14
4-item  0 0 0 6 8 12 13 14

편의상 행과 열에 0번을 비운다.

이후 목표 무게인 DP[N][W]을 반환하면 된다.

문자열 알고리즘 LCS와 유사하다.

*/


#include<iostream>
#include<vector>

using namespace std;

struct _int2
{
	int Weight;
	int Value;
};
int DP[101][100001]{};
vector<_int2> Item{};


int N = 0, W = 0;

void MakeDP()
{
	for (int i = 1; i <= N; i++)
	{
		for (int w = 1; w <= W; w++)
		{
			if (w < Item[i].Weight)
				DP[i][w] = DP[i - 1][w];
			else
				DP[i][w] = max(DP[i - 1][w], DP[i - 1][w - Item[i].Weight] + Item[i].Value);
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	Item.push_back({ 0,0 });
	cin >> N >> W;
	int Count = W;
	while (Count--)
	{
		int Weight = 0, Value = 0;
		cin >> Weight >> Value;

		Item.push_back({ Weight, Value });
	}
	MakeDP();
	cout << DP[N][W];

	return 0;
}