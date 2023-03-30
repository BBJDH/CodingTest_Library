/*
 *14503 - 로봇 청소기
 *
 *BFS나 DFS로 접근하고자 했으나,
 *
 *요구사항을 잘 보니 로봇의 작동방식대로 맵을 탐색해야 한다.
 *
 *로봇의 작동방식대로 구현하고 시뮬레이션 해야만 특정 구역을 탐색하지 못하는 경우가 생긴다
 *
 *예시
 *
 *5 5		- 크기
 *1 2 2		- (2,1) 남쪽을 바라본 경우 (가장 왼쪽 상단은 0,0)
 *1 1 1 1 1
 *1 0 0 0 1
 *1 1 1 0 1
 *1 1 1 0 1
 *1 1 1 1 1
 *
 *위의 경우 모든 0 지역을 청소하지 못한다.
 *(해답은 4이다. 2,1에서 오른쪽 지역만을 청소하고 후진하여 벽에 도달한다.)
 *
 *
 *때문에 BFS나 DFS로 모든 연결된 0지역을 탐색하고자 하면 정답에 도달할 수없다.
 *
 *따라서 요구사항대로 구현하여 시뮬레이션을 통해 치운 방 갯수를 출력한다.
 *
 */

#include<iostream>

using namespace std;

struct _int2
{
	int X;
	int Y;
};

//반시계방향 0-북, 1-동, 2-남, 3-서
_int2 Direction[4] = { {0,-1}, {1,0}, {0,1}, {-1,0} };
int Map[50][50]{};
bool Visit[50][50]{};

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int SizeY = 0, SizeX = 0;
	_int2 CurrentPos{};
	int CurrentDirection = 0;
	int Result = 0;

	cin >> SizeY >> SizeX;
	cin >> CurrentPos.Y >> CurrentPos.X >> CurrentDirection;

	for (int y = 0; y < SizeY; y++)
	{
		for (int x = 0; x < SizeX; x++)
		{
			cin >> Map[y][x];
		}
	}

	while (true)
	{
		//후진해서 벽까지 옴
		if (Map[CurrentPos.Y][CurrentPos.X] == 1)
		{
			break;
		}

		//움직인 곳이 청소할 곳인경우
		if (Visit[CurrentPos.Y][CurrentPos.X] == false)
		{
			Visit[CurrentPos.Y][CurrentPos.X] = true;
			Result++;
			continue;
		}

		//주변 청소할 곳 검색
		bool IsExistUnCleanRoom = false;
		for (int i = 0; i < 4; i++)
		{
			_int2 NearByRoomPos{};
			NearByRoomPos.X = CurrentPos.X + Direction[i].X;
			NearByRoomPos.Y = CurrentPos.Y + Direction[i].Y;
			if (Map[NearByRoomPos.Y][NearByRoomPos.X] != 1 and Visit[NearByRoomPos.Y][NearByRoomPos.X] == false)
			{
				IsExistUnCleanRoom = true;
				break;
			}
		}
		//모든 방이 깨끈하면 후진
		if (IsExistUnCleanRoom == false)
		{
			CurrentPos.X = CurrentPos.X + (Direction[CurrentDirection].X * -1);
			CurrentPos.Y = CurrentPos.Y + (Direction[CurrentDirection].Y * -1);
			continue;
		}

		//반시계 방향회전 및 탐색
		for (int i = 0; i < 4; i++)
		{
			CurrentDirection = CurrentDirection - 1;
			if (CurrentDirection == -1)
			{
				CurrentDirection = 3;
			}
			_int2 NextPos{};
			NextPos.X = CurrentPos.X + Direction[CurrentDirection].X;
			NextPos.Y = CurrentPos.Y + Direction[CurrentDirection].Y;
			if (Map[NextPos.Y][NextPos.X] != 1 and Visit[NextPos.Y][NextPos.X] == false)
			{
				CurrentPos.X = NextPos.X;
				CurrentPos.Y = NextPos.Y;
				break;
			}
		}

	}
	cout << Result;
	return 0;
}