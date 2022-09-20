/*
16236 - �Ʊ� ���

2���� ��ġ�� �ش� ��ġ�� ����� ũ��, �̵��� �Ÿ�, ���� Ƚ���� ����ü�� ����
NXN �Է¹�����ŭ ��ġ�� ���ڸ� ���

BFS ��ü�� Ž�� �� ���� ���ִ� ������ ���� �����鼭 ����,���� ������ �켱����ť�� ������ �ۼ�

BFS�Ϸ� �� �켱����ť���� �ϳ��� ���� ������ ��λ��� (���� �̰��� ���ķ� �����丵�ϵ�������, �켱����ť�� �ʿ����)
�ٽ� BFS ����
.
.
.
BFS�� ��� ã�Ҵµ��� �켱����ť�� �ƹ��͵� ���� ���� �ʾҴٸ�
�������� �������Դ� �켱����ť ���ڰ� ������ Ž����ġ�� �ȴ�

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

//�湮 ���, ť ����
void Push(Node const& CurrentNode)
{
	BFS.push(CurrentNode);
	Visit[CurrentNode.Pos.Y][CurrentNode.Pos.X] = true;

}

//�湮, ũ�� ��, ť ���� ��
void VisitNodes(Node const& CurrentNode)
{
	for (int i = 0; i < 4; i++)
	{
		Node NextNode = CurrentNode;
		NextNode.Pos.X += Direction[i].X;
		NextNode.Pos.Y += Direction[i].Y;
		NextNode.Distance++;
		//�����˻���� ����
		if (NextNode.Pos.X > 0 and NextNode.Pos.Y > 0 and NextNode.Pos.X <= SeaSize and NextNode.Pos.Y <= SeaSize and
			Visit[NextNode.Pos.Y][NextNode.Pos.X] == false and CurrentNode.Size >= Sea[NextNode.Pos.Y][NextNode.Pos.X])
		{
			if (CurrentNode.Size > Sea[NextNode.Pos.Y][NextNode.Pos.X] and Sea[NextNode.Pos.Y][NextNode.Pos.X] != 0)
			{
				//�ĺ� ���	
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