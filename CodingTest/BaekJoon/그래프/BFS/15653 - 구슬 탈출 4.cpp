/*
13460 - 구슬 탈출 2

방문배열을 4차원 배열로 설정해야한다 빨간구슬이 특정 Pos에 있을때 파란구슬이 해당 위치에 있었는지를 체크
=>[Next.RedPos.Y][Next.RedPos.X][Next.BluePos.Y][Next.BluePos.X]

파란구슬이 구멍에 빠지는 경우를 먼저 제거해준다
구슬을 굴릴때 겹쳐지는 구술이 있는지를 체크하고 벽에서 2만큼, 없다면 1만큼 되돌린다

마지막 출력조건에 유의해야한다


처음 방문배열을 2차원으로 잡아서 실패가 뜬 후

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

이런 케이스를 접하고 방문배열을 수정했다

구슬은 구슬을 벽으로 삼아 타고갈 수 있다.

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
R visit만을 두고 B는 구멍에 빠지는지만 감시
방문은 다 굴러간 끝지점에서 방문 처리
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
	//B가구멍에 빠지는경우부터 제거한다
	//이후 R구멍에 빠지는 경우는 Push(큐에서 종료신호로 쓰일것이다)
	//나머지 네방향에대한 R B 구슬의 이동좌표를 계산하여 Push 처리
	//굴러가는쪽에 다른 구슬이 앞을 막고 있었다면 벽에서 -2로 되돌려줌

	for (int i = 0; i < 4; i++)
	{
		Node Next{};
		Next = { Current.RedPos, Current.BluePos, Current.Count + 1 };
		int mul = 1;
		_int2 const PrevBluePos = Next.BluePos;
		while (true)
		{
			Next.BluePos = { Next.BluePos.X + Direction[i].X, Next.BluePos.Y + Direction[i].Y };


			//기울였을때 두 구슬이 겹치게 된다면, 즉 기울이는 방향에 다른구슬이 존재한다면
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
			//기울였을때 두 구슬이 겹치게 된다면, 즉 기울이는 방향에 다른구슬이 존재한다면
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
			//Blue가 같이 빠지는 경우는 Push되지 않도록 처리되어있으므로 여기서 종료
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