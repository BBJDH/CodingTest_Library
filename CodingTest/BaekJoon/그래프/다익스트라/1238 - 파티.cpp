/*
1238 - ��Ƽ

�� �������� X�� ���ϰ� X���� �� ������ ���ϴ� �ִܰ���� ���� �ʿ��ϴ�
���� X�� ���ϴ� �������� ���ͽ�Ʈ�� ���ְ�, �ٽ� �ݴ�������� ���ͽ�Ʈ�� ���ش�

����� edge�� ������ ���������� ���� �������ְ�, ���ͽ�Ʈ�� ���� �����ش�
X���� �� ������ ���ϴ� ������ �״�� X���� ���ͽ�Ʈ�� ������ �ִܰ�θ� �����ϰ�
���������� �������� X���� ���ͽ�Ʈ�� �ϸ� �� �������� X�� ���ϴ� �ִܰ�ȣ�� ���� �� �ִ�.
*/

#include<iostream>
#include<queue>
#include<vector>
#define INF 2000000000

using namespace std;

struct _int2
{
	int Pos;
	int Weight;
};

bool operator>(_int2 const& Left, _int2 const& Right)
{
	return Left.Weight > Right.Weight;
}
bool operator<(_int2 const& Left, _int2 const& Right)
{
	return Left.Weight < Right.Weight;
}

priority_queue<_int2, vector<_int2>, greater<_int2>> Dijkstra_Queue{};
vector<vector<_int2>> Edges{};
vector<vector<_int2>> Edges_Reverse{};
int Distance[1001]{};
int ReversDistance[1001]{};
int N = 0, M = 0, X = 0;

void SetDistance()
{
	for (int i = 0; i < 1001; i++)
	{
		Distance[i] = INF;
		ReversDistance[i] = INF;
	}
}
void RoundEdges(_int2 const& Current)
{
	for (auto const& Elem : Edges[Current.Pos])
	{
		_int2 Next{};
		Next.Pos = Elem.Pos;
		Next.Weight = Current.Weight + Elem.Weight;

		if (Next.Weight < Distance[Next.Pos])
		{
			Distance[Next.Pos] = Next.Weight;
			Dijkstra_Queue.push(Next);
		}
	}
}
void RoundEdges_Reverse(_int2 const& Current)
{
	for (auto const& Elem : Edges_Reverse[Current.Pos])
	{
		_int2 Next{};
		Next.Pos = Elem.Pos;
		Next.Weight = Current.Weight + Elem.Weight;

		if (Next.Weight < ReversDistance[Next.Pos])
		{
			ReversDistance[Next.Pos] = Next.Weight;
			Dijkstra_Queue.push(Next);
		}
	}
}

void Dijkstra(_int2 const& Start, bool IsReverse)
{
	Dijkstra_Queue.push(Start);
	if (IsReverse)
		ReversDistance[Start.Pos] = 0;
	else
		Distance[Start.Pos] = 0;
	while (!Dijkstra_Queue.empty())
	{
		_int2 const Current = Dijkstra_Queue.top();
		Dijkstra_Queue.pop();

		if (not IsReverse and Distance[Current.Pos] < Current.Weight) continue;
		if (IsReverse and ReversDistance[Current.Pos] < Current.Weight) continue;
		if (IsReverse)
			RoundEdges_Reverse(Current);
		else
			RoundEdges(Current);
	}
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> X;
	Edges.resize(N + 1);
	Edges_Reverse.resize(N + 1);
	while (M--)
	{
		int Start = 0, Dest = 0, Weight = 0;
		cin >> Start >> Dest >> Weight;
		Edges[Start].push_back({ Dest,Weight });
		Edges_Reverse[Dest].push_back({ Start,Weight });
	}
	SetDistance();
	Dijkstra({ X,0 }, false);
	Dijkstra({ X,0 }, true);

	int Sum = 0;
	for (int i = 1; i <= N; i++)
	{
		Sum = max(Sum, Distance[i] + ReversDistance[i]);
	}
	cout << Sum;
	return 0;
}