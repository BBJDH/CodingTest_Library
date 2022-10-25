/*
12865 - ����� �賶

0-1 Knapsack Problem�̸� ������ ��ȭ���� ������ ����

DP[itemindex][weight] = max(DP[itemindex-1][weight], DP[itemindex-1][weight- item.weight] +item.value)
(���� �����ۿ����� �ִ� ��ġ = MAX(���� ���������� �ִ� ��ġ, ����������� �߰��� ����� �ִ� ��ġ)


DP�� ���� ������, ���� ������ 2���� �迭�̴�, ������ ������ ����,
		0 1 2 3 4  5 6  7
0-item  0 0 0 0 0 0  0  0
1-item  0 0 0 0 0 0  13 13
2-item  0 0 0 0 8 8  13 13
3-item  0 0 0 6 8 8  13 14
4-item  0 0 0 6 8 12 13 14

���ǻ� ��� ���� 0���� ����.

���� ��ǥ ������ DP[N][W]�� ��ȯ�ϸ� �ȴ�.

���ڿ� �˰��� LCS�� �����ϴ�.

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