/*
 *14502 - 연구소
 *
 *크기가 81개로 정해져 있으므로 벽을 3개 놓는 경우의 수는 81*81*81 는 54만가지 이하이다
 *따라서 브루트포스로 모두 입력해보고 BFS로 바이러스를 퍼뜨려본다
 *매 탐색시 벽의 개수는 고정이고 바이러스는 BFS의 큐에서 빠져나오는 만큼 카운트 시켜준다
 *이후 전체 블록수 - (벽 + 바이러스수) = 안전한 영역수 를 구해
 *최대값을 업데이트 하여 출력한다.
 *
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct _int2
{
	int X;
	int Y;
};

queue<_int2> BFS_Queue{};
vector<_int2>Virus_Start{};
_int2 Direction[4] = { {1,0}, {0,1} , {-1,0} , {0,-1} };
int Map[9][9]{};
bool Visit[9][9]{};
_int2 Size{};
int WallCount = 0;
int VirusCount = 0;
int MaxZone = 0;

void Push(_int2 const& Next)
{
	if (Visit[Next.Y][Next.X] == false)
	{
		BFS_Queue.push(Next);
		Visit[Next.Y][Next.X] = true;
	}
}


void RoundEdges(_int2 const& Current)
{
	for (int i = 0; i < 4; i++)
	{
		_int2 Next{};
		Next.X = Current.X + Direction[i].X;
		Next.Y = Current.Y + Direction[i].Y;
		if (Next.X >= 0 and Next.X < Size.X and Next.Y >= 0 and Next.Y < Size.Y and Map[Next.Y][Next.X] != 1)
			Push(Next);
	}
}

void BFS(_int2 const& Start)
{
	Push(Start);
	while (!BFS_Queue.empty())
	{
		VirusCount++;
		_int2 const Current = BFS_Queue.front();
		BFS_Queue.pop();
		RoundEdges(Current);
	}
}

void ActivateVirus()
{
	VirusCount = 0;
	for (int y = 0; y < Size.Y; y++)
		fill_n(Visit[y], Size.X, false);
	for (auto const& elem : Virus_Start)
		BFS(elem);
	MaxZone = max(MaxZone, Size.X * Size.Y - (WallCount + VirusCount));

}

void SetWall(_int2 const& Pos, int SetCount)
{
	if (SetCount > 3)
		return;

	for (int y = Pos.Y; y < Size.Y; y++)
	{
		int startX = 0;
		if (y == Pos.Y)
			startX = Pos.X;
		for (int x = startX; x < Size.X; x++)
		{
			if (Map[y][x] == 0)
			{
				Map[y][x] = 1;
				if (y == 7 and x == 1)
					int test = 0;
				if (SetCount + 1 == 3)
				{
					ActivateVirus();
				}
				SetWall({ x,y }, SetCount + 1);
				Map[y][x] = 0;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> Size.Y >> Size.X;

	for (int y = 0; y < Size.Y; y++)
	{
		for (int x = 0; x < Size.X; x++)
		{
			cin >> Map[y][x];

			switch (Map[y][x])
			{
			case 1: WallCount++; break;
			case 2: Virus_Start.push_back({ x,y }); break;
			}
		}
	}
	WallCount += 3;
	SetWall({ 0,0 }, 0);
	cout << MaxZone;

	return 0;
}