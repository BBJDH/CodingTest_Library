/*
 * 11389 - 케빈 베이컨의 6단계 법칙
 *
 * 각 모든 친구로부터 BFS, 모든 친구를 탐색한 비용을 누적하여 계산한다
 *
 *가장 적은 비용을 출력하는게 아니라 가장 적은 비용을 가진 사람을 출력해야 한다.
 *
 *각 탐색을 시작할 친구를 Start 다른 모든 친구를 Dest로 하여 BFS를 하고 누적 경로를 합산한다.
 *
 *가장 적은 경로였던 Start를 보존한다.
 *
 *모든 반복문을 탈출한다면 Start를 출력한다
 *
 *각 Start에서 Dest로 향하는 비용이 중복 사용되므로, DP를 추가하면 더 빨라질 수 있다
 *
 *예들을 어 1 에서 2로 가는 비용을 DP에 업데이트하고
 *
 *다음 2에서 1로가는 비용이 필요할때는 전에 기록 되어있는지 (비용이 INF가 아닌지)를 체크한다
 *
 *비용이 이미 계산 되어있다면 해당 비용으로 사용하여 시간을 단축 시킬 수 있다.
 *
 *
 *혹은 플로이드 워셜을 사용해도 된다.
 *
 *
 * 문제의 예제
 *
 * 1 3
 * 1 4
 * 2 3
 * 3 4
 * 4 5
 *
 * 1 - 2 는 2비용
 * 1 - 3 은 1비용
 * 1 - 4 는 1비용
 * 1 - 5 는 2비용
 *
 *
 * 1 - 2 => 2
 * 1 - 3 => 1
 * 1 - 4 => 1
 * 1 - 5 => 2
 *
 * 1은 6
 *
 * 2 - 1 => 2
 * 2 - 3 => 1
 * 2 - 4 => 2
 * 2 - 5 => 3
 *
 * 2 는 8
 *
 * 3 -
 *
 */


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct _int2
{
	int Num;
	int Count;
};

bool Visit[101]{};
vector<vector<int>>Edges{};
queue<_int2>BFSQueue{  };


void Push(_int2 const& Next)
{
	if (Visit[Next.Num] == false)
	{
		Visit[Next.Num] = true;
		BFSQueue.push(Next);
	}
}

void RoundEdge(_int2 const& Current)
{
	for (int const elem : Edges[Current.Num])
	{
		_int2 Next{};
		Next.Num = elem;
		Next.Count = Current.Count + 1;
		Push(Next);
	}
}

int BFS(_int2 const& Start, int const Dest)
{
	int Result = 0;
	BFSQueue = queue<_int2>();
	for (int i = 1; i < 101; i++)
	{
		fill_n(Visit, 101, false);
	}
	Push(Start);
	while (!BFSQueue.empty())
	{
		_int2 Current = BFSQueue.front();
		BFSQueue.pop();
		if (Current.Num == Dest)
		{
			Result = Current.Count;
			break;
		}
		RoundEdge(Current);

	}
	return Result;
}


int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int MinResult = 500000;
	int Result = 0;
	int NumOfPeople = 0, NumOfEdges = 0;
	cin >> NumOfPeople >> NumOfEdges;
	Edges.resize(NumOfPeople + 1);

	while (NumOfEdges--)
	{
		int Start = 0;
		int Dest = 0;

		cin >> Start >> Dest;
		Edges[Start].push_back(Dest);
		Edges[Dest].push_back(Start);
	}
	for (int Start = 1; Start <= NumOfPeople; Start++)
	{
		int CurrentResult = 0;
		for (int Dest = 1; Dest <= NumOfPeople; Dest++)
		{
			if (Start == Dest)
			{
				continue;
			}
			CurrentResult += BFS({ Start ,0 }, Dest);
		}
		if (MinResult > CurrentResult)
		{
			MinResult = min(MinResult, CurrentResult);
			Result = Start;
		}
	}
	cout << Result;

	return 0;
}