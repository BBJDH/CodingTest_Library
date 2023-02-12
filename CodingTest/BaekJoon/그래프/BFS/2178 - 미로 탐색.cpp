/*
 * 2178 - �̷� Ž��
 *
 *�׷��� Ž��(�ʺ�켱Ž��)���� �ذ��ߴ�
 *
 *�־����� Map�� int���� �ƴ� ���ڿ��̸� �������� 0,0�� �ƴ� 1,1����
 *
 *�̰��� ȥ������ �ʰ� Ž���ؾ� �Ѵ�.
 *
 *�� ������ �̵� ������ Ž�� ������ �ִ� 4�������� �迭�� �׷����� �����ߴ�.
 *(Edge���� ���ٸ� ��������Ʈ�� �����Ѵ�.)
 *
 *������ BFS�� �����ߴٸ� �ѹ��� ������ �ްԵȴ�.
 *(���ٸ� ���ܰ� ����.)
 *
 */

#include<iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct _int2
{
	int X;
	int Y;
};

struct Node
{
	_int2 Pos;
	int Count;
};
_int2 Direction[4] = { {1,0},{-1,0},{0,1},{0,-1} };
vector<string> Map{};
queue<Node>BFS_Queue{};
bool Visit[101][101]{};
int SizeX = 0, SizeY = 0;

void Push(Node const& Next)
{
	if (Visit[Next.Pos.Y][Next.Pos.X] == false and Map[Next.Pos.Y - 1][Next.Pos.X - 1] == '1')
	{
		BFS_Queue.push(Next);
		Visit[Next.Pos.Y][Next.Pos.X] = true;
	}
}

bool Round_Edges(Node const& Current)
{
	for (int i = 0; i < 4; i++)
	{
		Node Next{};
		Next.Pos.X = Current.Pos.X + Direction[i].X;
		Next.Pos.Y = Current.Pos.Y + Direction[i].Y;
		Next.Count = Current.Count + 1;

		if (Next.Pos.X == SizeX and Next.Pos.Y == SizeY)
		{
			cout << Next.Count;
			return true;
		}

		if (Next.Pos.X > 0 and Next.Pos.Y > 0 and Next.Pos.X <= SizeX and Next.Pos.Y <= SizeY)
		{
			Push(Next);
		}

	}
	return false;
}

void BFS()
{
	_int2 Start{ 1,1 };
	Push({ Start ,1 });
	while (!BFS_Queue.empty())
	{
		Node const Current = BFS_Queue.front();
		BFS_Queue.pop();
		if (Round_Edges(Current) == true)
			break;
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> SizeY >> SizeX;
	for (int i = 0; i < SizeY; i++)
	{
		string inputStr{};
		cin >> inputStr;
		Map.push_back(inputStr);
	}
	BFS();
	return 0;
}