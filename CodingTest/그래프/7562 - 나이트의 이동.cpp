#include <iostream>
#include <queue>
#include <cstring>
using namespace std;


struct _float2
{
	int x;
	int y;
	int MoveCount = 0;
	bool operator==(_float2 const RightPos) const
	{
		return this->x == RightPos.x and this->y == RightPos.y;
	}
};
bool Visit[301][301]{};
_float2 KnightStep[8] = { {-2, -1}, {-2, +1}, {-1, -2},{+1, -2}, {+2, -1},{+2, +1}, {-1, +2},{+1, +2} };

int TestCase = 0;			//첫 줄, 테스트 케이스
int ChassMaxLenth = 0;		//각 테스트 케이스의 첫 줄 체스판 크기
_float2 StartPos{ 0,0 };	//각 테스트 케이스의 두번째 줄 시작위치
_float2 DestPos{ 0,0 };		//각 테스트 케이스의 세번째 줄 도착위치
queue<_float2> BFS_Queue;


void Push_Queue(_float2 const& pos)
{
	if (pos.x >= 0 and pos.x < ChassMaxLenth and pos.y >= 0 and pos.y < ChassMaxLenth and (not Visit[pos.y][pos.x]))
	{
		Visit[pos.y][pos.x] = true;
		BFS_Queue.push(pos);
	}
}

void Search_NextStep(_float2 const& pos)
{
	for (int i = 0; i < 8; i++)
	{
		Push_Queue({ pos.x + KnightStep[i].x,  pos.y + KnightStep[i].y ,pos.MoveCount + 1 });
	}
}

void BFS_Loop()
{
	while (!BFS_Queue.empty())
	{
		_float2 const CurrentPos = BFS_Queue.front();
		BFS_Queue.pop();
		if (CurrentPos == DestPos)
		{
			cout << CurrentPos.MoveCount << "\n";
			while (!BFS_Queue.empty())
				BFS_Queue.pop();
			return;
		}
		Search_NextStep(CurrentPos);
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> TestCase;
	while (TestCase--)
	{
		cin >> ChassMaxLenth >> StartPos.x >> StartPos.y >> DestPos.x >> DestPos.y;
		memset(Visit, false, sizeof(Visit));
		Push_Queue(StartPos);
		BFS_Loop();
	}



	return 0;
}