/*
16236 - 아기 상어

2차원 위치와 해당 위치의 물고기 크기, 이동한 거리, 먹은 횟수를 구조체로 지정
NXN 입력받은만큼 위치에 숫자를 기록

BFS 전체를 탐색 후 먹을 수있는 물고기는 가장 가까우면서 위쪽,왼쪽 순으로 우선순위큐에 들어가도록 작성

BFS완료 후 우선순위큐에서 하나를 빼고 나머지 모두삭제 (추후 이것은 정렬로 리팩토링하도록하자, 우선순위큐가 필요없다)
다시 BFS 시행
.
.
.
BFS로 모두 찾았는데도 우선순위큐에 아무것도 삽입 되지 않았다면
마지막에 뽑혀나왔던 우선순위큐 인자가 마지막 탐색위치가 된다

*/

#include<iostream>
#include<queue>
#include<vector>
#include<bitset>


using namespace std;

int Sea[21][21]{};
vector<bitset<21>> Visit{};

struct _int2
{
	int X;
	int Y;
};


struct Node
{
	_int2 Pos;
	int EatCount = 0;
	int Size;
	int Distance;
};

struct CMP
{
	bool operator()(Node const& Front, Node const& Rear)
	{
		if (Front.Distance == Rear.Distance)
		{
			if (Front.Pos.Y == Rear.Pos.Y)
				return  Front.Pos.X > Rear.Pos.X;
			return Front.Pos.Y > Rear.Pos.Y;
		}
		return Front.Distance > Rear.Distance;
	}
};

_int2 Direction[4] = { {0, -1}, {-1, 0}, {1,0},{0,1} };

queue<Node> BFS{};
priority_queue<Node, vector<Node>, CMP> NextStarts{};
int SeaSize = 0;
Node LastNode{};

void EatFish(Node& Current)
{
	if (Sea[Current.Pos.Y][Current.Pos.X] == 0)
		return;
	Current.EatCount++;
	Sea[Current.Pos.Y][Current.Pos.X] = 0;
	if (Current.EatCount == Current.Size and Current.Size <= 6)
	{
		Current.Size++;
		Current.EatCount = 0;
	}
}

//방문 기록, 큐 삽입
void Push(Node const& CurrentNode)
{
	BFS.push(CurrentNode);
	Visit[CurrentNode.Pos.Y][CurrentNode.Pos.X] = true;

}

//방문, 크기 비교, 큐 삽입 콜
void VisitNodes(Node const& CurrentNode)
{
	for (int i = 0; i < 4; i++)
	{
		Node NextNode = CurrentNode;
		NextNode.Pos.X += Direction[i].X;
		NextNode.Pos.Y += Direction[i].Y;
		NextNode.Distance++;
		//범위검사부터 시행
		if (NextNode.Pos.X > 0 and NextNode.Pos.Y > 0 and NextNode.Pos.X <= SeaSize and NextNode.Pos.Y <= SeaSize and
			Visit[NextNode.Pos.Y][NextNode.Pos.X] == false and CurrentNode.Size >= Sea[NextNode.Pos.Y][NextNode.Pos.X])
		{
			if (CurrentNode.Size > Sea[NextNode.Pos.Y][NextNode.Pos.X] and Sea[NextNode.Pos.Y][NextNode.Pos.X] != 0)
			{
				//후보 등록	
				NextStarts.push(NextNode);
				Visit[NextNode.Pos.Y][NextNode.Pos.X] = true;
			}
			else
				Push(NextNode);
		}
	}
}

void Solution()
{
	while (!NextStarts.empty())
	{
		LastNode = NextStarts.top();
		while (!NextStarts.empty())NextStarts.pop();
		for (int i = 1; i < 21; i++)
			Visit[i].reset();

		EatFish(LastNode);
		Push(LastNode);
		while (!BFS.empty())
		{
			Node const CurrentNode = BFS.front();
			BFS.pop();
			VisitNodes(CurrentNode);
		}
	}
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	Visit.resize(21);
	cin >> SeaSize;

	Node Start = { {0,0},0,2,0 };

	for (int Y = 1; Y <= SeaSize; Y++)
	{
		for (int X = 1; X <= SeaSize; X++)
		{
			int InputNum = 0;
			cin >> InputNum;

			if (InputNum == 9)
				Start.Pos = { X,Y };

			Sea[Y][X] = InputNum;
		}
	}
	Sea[Start.Pos.Y][Start.Pos.X] = 0;
	NextStarts.push(Start);
	Solution();
	cout << LastNode.Distance;

	return 0;
}