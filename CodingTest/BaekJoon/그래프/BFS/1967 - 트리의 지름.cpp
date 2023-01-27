/*
 *1967 - 트리의 지름
 *
 *====처음에 했던 생각====
 *각 자식노드를 기준으로 완전탐색으로 진행하여
 *
 *가장 먼거리를 저장한다.
 *
 *때문에 처음에는 모든 자식노드들을 저장하고,
 *
 *그것에 대한 BFS로 완전 탐색을 진행했더니
 *
 *속도가 1648ms가 나왔다...
 *
 *노드 10000개에 대한 BFS를 모두 하였으니 당연한일...
 *
 *어떤 좋은 방법이 있을까?
 *
 *====개선안====
 *
 *기존안은 노드 10000개에 대한 BFS를 진행하고 있었다.
 *
 *하지만 1번 노드가 항상 root이므로
 *
 *1번으로 BFS를 진행하여 가장 긴 노드를 찾는다.(이것이 다음 BFS의 시작점)
 *
 *찾아진 긴 노드로 BFS를 한다면 반드시 여기서 가장 긴 길이가 등장한다.
 *(결국 BFS는 1에서 한번, 여기서 찾아진 가장 먼 노드로 한번, 총 두번만 하면 된다.)
 *
 *
 *
 *즉, 트리의 지름이 되는 끝 노드는
 *
 *반드시 해당 트리의 가장 먼 노드를 포함한다
 *
 *코드 수정후 속도가 1648ms 에서 4ms로 줄었다.
 *
 *
 */

#include<iostream>
#include <vector>
#include <queue>

using namespace std;
struct _int2
{
	int Node;
	int Weight;
};

bool Visit[10001]{};
vector<vector<_int2>> Edges{};
vector<int>StartNodes{};
queue<_int2>BFS_Queue{};
int MaxWeight = 0;

void Push(_int2 const& Next)
{
	if (Visit[Next.Node] == false)
	{
		Visit[Next.Node] = true;
		BFS_Queue.push(Next);
	}
}

void RoundEdges(_int2 const& Current)
{
	for (int i = 0; i < Edges[Current.Node].size(); i++)
	{
		_int2 Next{};
		Next.Node = Edges[Current.Node][i].Node;
		Next.Weight = Current.Weight + Edges[Current.Node][i].Weight;
		Push(Next);
	}
}

int BFS(int const Start)
{
	int FurthestNode = 0;
	fill_n(Visit, 10001, false);
	BFS_Queue = queue<_int2>{};
	Push({ Start ,0 });
	while (!BFS_Queue.empty())
	{
		_int2 const Current = BFS_Queue.front();
		BFS_Queue.pop();
		RoundEdges(Current);
		if (MaxWeight < Current.Weight)
		{
			MaxWeight = Current.Weight;
			FurthestNode = Current.Node;
		}
	}
	return FurthestNode;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N = 0;
	cin >> N;
	Edges.resize(N + 1);
	while (N--)
	{
		int Start = 0, Dest = 0, Weight = 0;
		cin >> Start >> Dest >> Weight;
		Edges[Start].push_back({ Dest,Weight });
		Edges[Dest].push_back({ Start,Weight });
		StartNodes.push_back(Dest);
	}


	int const FurthestNode = BFS(1);
	BFS(FurthestNode);

	cout << MaxWeight;

	return 0;
}