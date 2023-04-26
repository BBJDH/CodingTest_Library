
/*
 *============================================
 *
 *연습문제 - 스파이 잠입
 *
 *BFS로 풀이 가능하다.
 *다만 큐에 좌표와 이동한 시간을 같이 묶어서 삽입한다.
 *
 *각 시간에 따라 안전한 시간, 감시되는 시간의 규칙이 존재한다.
 *
 * 예를들어 R =4 인 경우
 *
 *
 * 1 2 3 (0)까지 걸리지 않음 4 5 6 7 8 까지 걸림
 * 9 10 11	(2)		12 13 14 15 16
 * 17 18 19   (4)      20 21 22 23 24
 *
 * 의 규칙을 가지게 된다.
 *
 * 위의 규칙에 따라 안전구간은 자유롭게 이동하도록 두고,
 * 감시구간은 움직인 자리가 비감시 구역인지 확인하여 감시구역이 아닌경우 큐에삽입하면 안된다.
 * 또한 최대 시간 T를 초과해도 실패이므로 큐에 삽입하면 안된다.
 *
 *또한, 계속 움직이는것이 아닌 제자리에 대기하는 경우도 포함시켜야 한다.
 *이를 위해 방문처리를 하되, 제자리에 머무는 경우만 방문처리 없이 진행시킨다.
 *
 *RoundEdge를 하며 도착지점에 도착하였다면 해당 Time을 출력 후 종료한다.
 *
 *
 *만약 모든 큐를 돌아도 도착하지 못한다면 -1을 출력한다.
 *
 */

#include <iostream>
#include <vector>
#include <string>
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
	int Time;
};

_int2 Direction[5] = { {0,0}, {1,0}, {-1,0}, {0,1}, {0,-1} };
queue<Node> BFSQueue{};
vector<string> Beach{};

bool Visit[30][30]{};
int R = 0, T = 0;
void Push(Node const& Next)
{
	if (Beach[Next.Pos.Y][Next.Pos.X] != 'R'
		and ((((Next.Time / R) % 2) == 0 and Next.Time % R != 0) or (Beach[Next.Pos.Y][Next.Pos.X] == 'B'))
		and Visit[Next.Pos.Y][Next.Pos.X] == false and Next.Time <= T)
	{
		BFSQueue.push(Next);
		Visit[Next.Pos.Y][Next.Pos.X] = true;
	}
}

int RoundEdges(Node const& Current)
{
	for (int i = 0; i < 5; i++)
	{
		Node Next{};
		Next.Pos.X = Current.Pos.X + Direction[i].X;
		Next.Pos.Y = Current.Pos.Y + Direction[i].Y;
		Next.Time = Current.Time + 1;

		if (i == 0 )
		{
			Visit[Next.Pos.Y][Next.Pos.X] = false;
			Push(Next);
			continue;
		}

		if (Next.Pos.Y < 0 and Next.Time <= T)
		{
			return Next.Time;
		}

		if (Next.Pos.X >= 0 and Next.Pos.X < Beach[0].size() and Next.Pos.Y >= 0 and Next.Pos.Y < Beach.size())
		{
			Push(Next);
		}
	}
	return -1;
}

int BFS(Node const& Start)
{
	Visit[Start.Pos.Y][Start.Pos.X] = true;
	BFSQueue.push(Start);
	int Result = -1;
	while (!BFSQueue.empty())
	{
		Node Current = BFSQueue.front();
		BFSQueue.pop();
		Result = RoundEdges(Current);
		if(Result != -1)
		{
			return Result;
		}
	}
	return Result;
}


int solution(vector<string> beach, int r, int t)
{
	int answer = 0;
	_int2 Start{};
	Beach = beach;
	R = r;
	T = t;
	for (int y = 0; y < beach.size(); y++)
	{
		for (int x = 0; x < beach[y].size(); x++)
		{
			if (beach[y][x] == 'R')
			{
				for (int i = 1; i <= 2; i++)
				{
					if (y + i < beach.size() and beach[y + i][x] != 'R')
					{
						Beach[y + i][x] = 'B';
					}
				}
				continue;
			}
			if (beach[y][x] == 'Z')
			{
				Start = { x,y };
				continue;
			}
		}
	}
	answer = BFS({ Start ,0 });
	return answer;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	//Solution({"........",
	//				 ".R......",
	//				 "R.....RR",
	//				 "........",
	//				 "....R...",
	//				 "........",
	//				 "........",
	//				 "Z......."},4,20);
	//Solution({"........", ".R......", "R.....RR", "........", "....R...", "........", "........", "Z......."},3,20);
	//Solution({"...","RRR","...","Z.."}, 10, 60);
	//Solution({".","Z"}, 10, 1);
	//Solution({".","Z"}, 10, 2);

	//[12] 3456 [78] 9101112
	Solution({ "RRRRR.",
					  "......",
					  "......",
					  "......",
					  "Z....." }, 3, 60);

	return 0;
}
