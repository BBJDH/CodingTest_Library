/*

1043 - 거짓말

주어지는 파티의 멤버들을 Edge로 등록한다
진실을 아는 멤버로부터 BFS로 탐색하여 각 Edge로 진실을 퍼뜨린다고 생각하자
그러므로 진실을 아는 멤버로 BFS를 시행한 후, Visit방문이 되면 해당 멤버는 진실을 알고있게 된다.
파티의 첫번째 멤버가 true라면 그 파티는 참가할 수 없다.
반대로 false라면 모든 멤버가 false이므로 이파티는 참여 가능하다.

*/


#include<iostream>
#include<queue>
using namespace std;


int N = 0, M = 0;
vector<int> T_Nums{};
vector<vector<int>> PartyPeople{};
vector<vector<int>> Edges{};
queue<int>BFS_Queue{};
bool Visit[51]{};


void Push(int const Next)
{
	if (Visit[Next] == false)
	{
		BFS_Queue.push(Next);
		Visit[Next] = true;
	}
}

void RoundEdges(int const Current)
{
	for (auto const& Elem : Edges[Current])
		Push(Elem);
}

void BFS(int const Start)
{
	Push(Start);
	while (!BFS_Queue.empty())
	{
		int const Current = BFS_Queue.front();
		BFS_Queue.pop();
		RoundEdges(Current);
	}
}

int CountCanJoinParty()
{
	int Count = 0;
	for (int i = 0; i < PartyPeople.size(); i++)
	{
		int FirstPartyNum = PartyPeople[i][0];
		if (Visit[FirstPartyNum] == false)
			Count++;
	}
	return Count;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	PartyPeople.resize(M);
	Edges.resize(N + 1);
	fill_n(Visit, 51, false);
	int T_Num = 0;
	cin >> T_Num;
	while (T_Num--)
	{
		int Num = 0;
		cin >> Num;
		T_Nums.emplace_back(Num);
	}

	for (int i = 0; i < M; i++)
	{
		int InputCount = 0;
		cin >> InputCount;
		while (InputCount--)
		{
			int InputNum = 0;
			cin >> InputNum;
			PartyPeople[i].emplace_back(InputNum);
		}
		if (PartyPeople[i].size() > 1)
		{

			for (int j = 1; j < PartyPeople[i].size(); j++)
			{
				int const Start = PartyPeople[i][j - 1];
				int const Dest = PartyPeople[i][j];
				Edges[Start].emplace_back(Dest);
				Edges[Dest].emplace_back(Start);
			}
		}
	}

	//BFS All

	for (auto const& Elem : T_Nums)
		BFS(Elem);

	cout << CountCanJoinParty();

	return 0;
}