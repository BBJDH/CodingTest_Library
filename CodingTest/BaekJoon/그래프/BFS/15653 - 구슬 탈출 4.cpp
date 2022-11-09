/*
13460 - ���� Ż�� 2

�湮�迭�� 4���� �迭�� �����ؾ��Ѵ� ���������� Ư�� Pos�� ������ �Ķ������� �ش� ��ġ�� �־������� üũ
=>[Next.RedPos.Y][Next.RedPos.X][Next.BluePos.Y][Next.BluePos.X]

�Ķ������� ���ۿ� ������ ��츦 ���� �������ش�
������ ������ �������� ������ �ִ����� üũ�ϰ� ������ 2��ŭ, ���ٸ� 1��ŭ �ǵ�����

������ ������ǿ� �����ؾ��Ѵ�


ó�� �湮�迭�� 2�������� ��Ƽ� ���а� �� ��

8 10

##########
#.......O#
###.#.#.##
#........#
#B#.###..#
##.....#.#
#R...#...#
##########
ans: 10

�̷� ���̽��� ���ϰ� �湮�迭�� �����ߴ�

������ ������ ������ ��� Ÿ�� �� �ִ�.

 */



#include<iostream>
#include <queue>

using namespace  std;

struct _int2
{
	int X;
	int Y;
};

bool operator==(_int2 const& First, _int2 const& Second)
{
	return 	First.X == Second.X and First.Y == Second.Y;
}
bool operator!=(_int2 const& First, _int2 const& Second)
{
	return 	First.X != Second.X or First.Y != Second.Y;
}


struct Node
{
	_int2 RedPos;
	_int2 BluePos;
	int Count;
};


queue<Node> BFS_Queue{};

char Map[10][10]{};
bool Visit[10][10][10][10]{};
_int2 Direction[4] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

int SizeX = 0;
int SizeY = 0;
_int2 StartRedPos{};
_int2 StartBluePos{};
_int2 DestPos{};

/*
R visit���� �ΰ� B�� ���ۿ� ���������� ����
�湮�� �� ������ ���������� �湮 ó��
*/



void Push(Node const& Next)
{
	if (Visit[Next.RedPos.Y][Next.RedPos.X][Next.BluePos.Y][Next.BluePos.X] == false )
	{
		Visit[Next.RedPos.Y][Next.RedPos.X][Next.BluePos.Y][Next.BluePos.X] = true;
		BFS_Queue.push(Next);
	}
}


void RoundEdges(Node const& Current)
{
	//B�����ۿ� �����°����� �����Ѵ�
	//���� R���ۿ� ������ ���� Push(ť���� �����ȣ�� ���ϰ��̴�)
	//������ �׹��⿡���� R B ������ �̵���ǥ�� ����Ͽ� Push ó��
	//���������ʿ� �ٸ� ������ ���� ���� �־��ٸ� ������ -2�� �ǵ�����

	for (int i = 0; i < 4; i++)
	{
		Node Next{};
		Next = { Current.RedPos, Current.BluePos, Current.Count + 1 };
		int mul = 1;
		_int2 const PrevBluePos = Next.BluePos;
		while (true)
		{
			Next.BluePos = { Next.BluePos.X + Direction[i].X, Next.BluePos.Y + Direction[i].Y };


			//��￴���� �� ������ ��ġ�� �ȴٸ�, �� ����̴� ���⿡ �ٸ������� �����Ѵٸ�
			if (Next.BluePos == Next.RedPos)
				mul = 2;

			if (Map[Next.BluePos.Y][Next.BluePos.X] == 'O')break;
			if (Map[Next.BluePos.Y][Next.BluePos.X] == '#')
			{
				Next.BluePos = { Next.BluePos.X - Direction[i].X * mul, Next.BluePos.Y - Direction[i].Y * mul };
				break;
			}
		}
		mul = 1;
		while (true)
		{
			Next.RedPos = { Next.RedPos.X + Direction[i].X, Next.RedPos.Y + Direction[i].Y };
			//��￴���� �� ������ ��ġ�� �ȴٸ�, �� ����̴� ���⿡ �ٸ������� �����Ѵٸ�
			if (Next.RedPos == PrevBluePos)
				mul = 2;

			if (Map[Next.RedPos.Y][Next.RedPos.X] == 'O')break;
			if (Map[Next.RedPos.Y][Next.RedPos.X] == '#')
			{
				Next.RedPos = { Next.RedPos.X - Direction[i].X * mul, Next.RedPos.Y - Direction[i].Y * mul };
				break;
			}
		}
		if (Map[Next.BluePos.Y][Next.BluePos.X] == 'O')
			continue;



		Push(Next);


	}
}

void BFS()
{

	Push({ StartRedPos,StartBluePos,0 });
	while (!BFS_Queue.empty())
	{
		Node const Current = BFS_Queue.front();
		BFS_Queue.pop();
		if (Current.RedPos == DestPos)
		{
			//Blue�� ���� ������ ���� Push���� �ʵ��� ó���Ǿ������Ƿ� ���⼭ ����
			cout << Current.Count;
			return;
		}
		RoundEdges(Current);
	}
	cout << -1;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> SizeY >> SizeX;

	for (int y = 0; y < SizeY; y++)
	{
		for (int x = 0; x < SizeX; x++)
		{
			char inputChar{};
			cin >> inputChar;

			Map[y][x] = inputChar;

			switch (inputChar)
			{
			case 'R': StartRedPos = { x,y }; break;
			case 'B': StartBluePos = { x,y }; break;
			case 'O': DestPos = { x,y }; break;
			}

		}
	}
	BFS();

	return 0;
}