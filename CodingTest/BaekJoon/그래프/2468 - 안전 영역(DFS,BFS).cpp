/*
 *2468 - ���� ����(DFS,BFS)
 *
 *�־����� 0 ~ 100������ ���� ���̿� ���Ͽ� BFS�� ���� Ž���� ���� ��,
 *
 *����Ǵ� �ִ� ���� ������ ����Ѵ�.
 *
 *BFS 0 ~ 100���� ���̿� ���Ͽ� ��� BFS�� ����Ž���� �ǽ��Ѵ�
 *100X100�� ������ ���Ʈ������ ��� �־��� ���̿� ���Ͽ� BFS�� ������ Ž���Ѵ�.
 *
 *���� Ž������ ���� HeightOfWater���� ���ٸ� �ش� ������ BFS �����Ѵ�.
 *��ϵ� �������� �������Ѱ��� HeightOfWater���� ������ ���ϰ�
 *��� ���� 0~ 100�� ���Ͽ� �ִ� �������� ������Ʈ�Ѵ�.
 *
 *���� 100���� �����ߴٸ� ������ �ִ� ������ Result�� ��� �� �����Ѵ�.
 *
 *�߰� : DFS�ε� Ǯ��ô�. �޸������� �־����� �ڵ� �ۼ��� �ξ� �����ߴ�.
 *
 */

#include <iostream>
#include <queue>

using namespace std;

struct _int2
{
	int X;
	int Y;
};
queue<_int2> BFS_Queue{};
_int2 Direction[4] = { {1,0},{-1,0} ,{0,1} ,{0,-1} };
int Map[100][100]{};
bool Visit[100][100]{};

int Size = 0;

bool Push(_int2 const& Next)
{
	if (Visit[Next.Y][Next.X] == false)
	{
		BFS_Queue.push(Next);
		Visit[Next.Y][Next.X] = true;
		return true;
	}
	return false;
}

void RoundEdges(_int2 const& Current, int const HeightOfWater)
{
	for (int i = 0; i < 4; i++)
	{
		_int2 Next{};
		Next.X = Current.X + Direction[i].X;
		Next.Y = Current.Y + Direction[i].Y;
		if (Next.X >= 0 and Next.X < Size and Next.Y >= 0 and Next.Y<Size and
			Map[Next.Y][Next.X]>HeightOfWater)
		{
			Push(Next);
		}
	}
}

bool BFS(_int2 const& Start, int const HeightOfWater)
{
	bool const IsSucceeded = Push(Start);

	while (!BFS_Queue.empty())
	{
		_int2 const Current = BFS_Queue.front();
		BFS_Queue.pop();
		RoundEdges(Current, HeightOfWater);
	}
	return IsSucceeded;
}

bool DFS(_int2 const& Start, int const HeightOfWater)
{
	if (Visit[Start.Y][Start.X] == true)
	{
		return false;
	}
	Visit[Start.Y][Start.X] = true;

	for (int i = 0; i < 4; i++)
	{
		_int2 Next{};
		Next.X = Start.X + Direction[i].X;
		Next.Y = Start.Y + Direction[i].Y;
		if (Next.X >= 0 and Next.X < Size and Next.Y >= 0 and Next.Y<Size and
			Map[Next.Y][Next.X]>HeightOfWater)
		{
			DFS(Next, HeightOfWater);
		}
	}
	return true;
}


void Solution()
{
	int Result = 0;
	for (int HeightOfWater = 0; HeightOfWater <= 100; HeightOfWater++)
	{
		int NumOfField = 0;
		for (int i = 0; i < Size; i++)
		{
			fill_n(Visit[i], Size, false);
		}
		for (int y = 0; y < Size; y++)
		{
			for (int x = 0; x < Size; x++)
			{
				if (Map[y][x] > HeightOfWater)
				{
					//if(BFS({x,y},HeightOfWater) ==true)
					//{
					//	NumOfField++;
					//}
					if (DFS({ x,y }, HeightOfWater) == true)
					{
						NumOfField++;
					}
				}
			}
		}
		Result = max(Result, NumOfField);
	}
	cout << Result;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);


	cin >> Size;

	for (int y = 0; y < Size; y++)
	{
		for (int x = 0; x < Size; x++)
		{
			cin >> Map[y][x];
		}
	}
	Solution();

	return 0;
}