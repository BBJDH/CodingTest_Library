
/*
 *============================================
 *
 *�������� - ������ ����
 *
 *BFS�� Ǯ�� �����ϴ�.
 *�ٸ� ť�� ��ǥ�� �̵��� �ð��� ���� ��� �����Ѵ�.
 *
 *�� �ð��� ���� ������ �ð�, ���õǴ� �ð��� ��Ģ�� �����Ѵ�.
 *
 * ������� R =4 �� ���
 *
 *
 * 1 2 3 (0)���� �ɸ��� ���� 4 5 6 7 8 ���� �ɸ�
 * 9 10 11	(2)		12 13 14 15 16
 * 17 18 19   (4)      20 21 22 23 24
 *
 * �� ��Ģ�� ������ �ȴ�.
 *
 * ���� ��Ģ�� ���� ���������� �����Ӱ� �̵��ϵ��� �ΰ�,
 * ���ñ����� ������ �ڸ��� �񰨽� �������� Ȯ���Ͽ� ���ñ����� �ƴѰ�� ť�������ϸ� �ȵȴ�.
 * ���� �ִ� �ð� T�� �ʰ��ص� �����̹Ƿ� ť�� �����ϸ� �ȵȴ�.
 *
 *����, ��� �����̴°��� �ƴ� ���ڸ��� ����ϴ� ��쵵 ���Խ��Ѿ� �Ѵ�.
 *�̸� ���� �湮ó���� �ϵ�, ���ڸ��� �ӹ��� ��츸 �湮ó�� ���� �����Ų��.
 *
 *RoundEdge�� �ϸ� ���������� �����Ͽ��ٸ� �ش� Time�� ��� �� �����Ѵ�.
 *
 *
 *���� ��� ť�� ���Ƶ� �������� ���Ѵٸ� -1�� ����Ѵ�.
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
