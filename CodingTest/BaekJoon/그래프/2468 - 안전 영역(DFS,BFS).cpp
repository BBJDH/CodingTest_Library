/*
 *2468 - 안전 영역(DFS,BFS)
 *
 *주어지는 0 ~ 100까지의 빗물 높이에 대하여 BFS로 구역 탐색을 했을 때,
 *
 *도출되는 최대 구역 갯수를 출력한다.
 *
 *BFS 0 ~ 100까지 높이에 대하여 모두 BFS로 구역탐색을 실시한다
 *100X100의 영역을 브루트포스로 모두 주어진 높이와 비교하여 BFS로 구역을 탐색한다.
 *
 *현재 탐색중인 높이 HeightOfWater보다 높다면 해당 구역을 BFS 시작한다.
 *기록된 구역들을 증가시켜가며 HeightOfWater마다 구역이 구하고
 *모든 높이 0~ 100에 대하여 최대 구역수를 업데이트한다.
 *
 *높이 100까지 시행했다면 구해진 최대 구역수 Result를 출력 후 종료한다.
 *
 *추가 : DFS로도 풀어봤다. 메모리증가가 있었지만 코드 작성은 훨씬 수월했다.
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