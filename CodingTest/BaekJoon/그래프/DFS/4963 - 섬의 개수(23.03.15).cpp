/*
 *4963 - 섬의 개수
 *
 *Direction 하나를 잘못 할당해 해결에 시간이 걸렸다.
 *({1,-1} 대신 {1,1}이 들어가 있었다.)
 *
 *풀이 방법
 *
 *입력받을 때 육지 목록을 저장해 두었다가
 *
 *탐색을 통해 모든 주면 육지를 탐색한다.
 *
 *
 *육지목록을 통해 방문을 시작하기전에
 *
 *해당 육지가 방문하지 않은 곳이라면
 *
 *그곳을 섬이라고 생각하고 카운트를 늘린다.
 *
 *
 *탐색 완료된 곳은 Visit을 이용해 기록하고
 *
 *다음 탐색에서 방문하지 않도록 처리한다.
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct _int2
{
	int X;
	int Y;
};

int Map[50][50]{};
bool Visit[50][50]{};
_int2 Direction[8] =
{ {0,-1},{1,-1},
	{1,0},{1,1},
	{0,1},{-1,1},
	{-1,0},{-1,-1} };

void DFS(_int2 const& PosOfStart, _int2 const& Size)
{
	Visit[PosOfStart.Y][PosOfStart.X] = true;
	for (int i = 0; i < 8; i++)
	{
		_int2 const NextPos = { PosOfStart.X + Direction[i].X,PosOfStart.Y + Direction[i].Y };

		if (NextPos.X >= 0 and NextPos.X < Size.X and NextPos.Y >= 0 and NextPos.Y < Size.Y and
			Visit[NextPos.Y][NextPos.X] == false and Map[NextPos.Y][NextPos.X] == 1)
		{
			DFS(NextPos, Size);
		}
	}
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);


	while (true)
	{
		vector<_int2> PosOfStart{};
		_int2 Size{};
		int Result = 0;
		cin >> Size.X >> Size.Y;

		if (Size.X == 0 and Size.Y == 0)
		{
			return 0;
		}

		//초기화


		for (int i = 0; i < Size.Y; i++)
		{
			fill_n(Visit[i], Size.X, false);
		}

		//방문 후보 등록 (입출력)
		for (int y = 0; y < Size.Y; y++)
		{
			for (int x = 0; x < Size.X; x++)
			{
				cin >> Map[y][x];
				if (Map[y][x] == 1)
				{
					PosOfStart.push_back({ x,y });
				}
			}
		}

		//방문 시작
		for (_int2 const& elem : PosOfStart)
		{
			if (Visit[elem.Y][elem.X] == false)
			{
				Result++;
				//DFS 마킹
				DFS(elem, Size);
			}
		}

		//결과 출력
		cout << Result << "\n";

	}


	return 0;
}