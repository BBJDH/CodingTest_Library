/*
 *2583 - 영역 구하기
 *
 * 각 좌표지점을 그래프로 다루어 너비우선 탐색을 통해 풀었다.
 *
 * 입력 받은 영역을 모두 1로 기록하고, 0인 영역을 BFS 한다
 * 성공시 Visit을 통해 중복 방문을 막는다.
 *
 * BFS에 성공하면 해당 영역은 한개로 취급한다.
 * 즉 해당 BFS에서 Pop 될때마다 영역의 크기를 ++하여
 * BFS종료시 이 결과를 결과 목록에 추가한다.
 *
 * 이것을 반복하여 결과목록인 Results의 크기와
 * 정렬하여 결과를 출력한다.
 *
 */

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

struct _int2
{
	int X;
	int Y;
};

queue<_int2> BFS_Queue{};
vector<int> Results{};
_int2 Direction[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int Map[100][100]{};
bool Visit[100][100]{};
_int2 Size{};


bool Push(_int2 const& Next)
{
	if (Visit[Next.Y][Next.X] == false and Map[Next.Y][Next.X] == 0)
	{
		Visit[Next.Y][Next.X] = true;
		BFS_Queue.push(Next);
		return true;
	}
	return false;

}

void RoundEdges(_int2 const& Current)
{
	for (int i = 0; i < 4; i++)
	{
		_int2 Next{};
		Next.X = Current.X + Direction[i].X;
		Next.Y = Current.Y + Direction[i].Y;
		if (Next.X >= 0 and Next.X < Size.X and Next.Y >= 0 and Next.Y < Size.Y)
		{
			Push(Next);
		}
	}
}

void BFS(_int2 const& Start)
{
	if (Push(Start) == false)
	{
		return;
	}
	int Result = 0;

	while (!BFS_Queue.empty())
	{
		_int2 const Current = BFS_Queue.front();
		BFS_Queue.pop();
		RoundEdges(Current);
		Result++;
	}
	Results.push_back(Result);
}

void Solution()
{
	for (int y = 0; y < Size.Y; y++)
	{
		for (int x = 0; x < Size.X; x++)
		{
			BFS({ x,y });
		}
	}
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);


	int NumOfZone = 0;
	cin >> Size.Y >> Size.X >> NumOfZone;

	while (NumOfZone--)
	{
		_int2 MinPos{};
		_int2 MaxPos{};
		cin >> MinPos.X >> MinPos.Y >> MaxPos.X >> MaxPos.Y;

		for (int y = MinPos.Y; y < MaxPos.Y; y++)
		{
			for (int x = MinPos.X; x < MaxPos.X; x++)
			{
				Map[y][x] = 1;
			}
		}
	}
	Solution();
	sort(Results.begin(), Results.end());
	cout << Results.size() << "\n";
	for (int const elem : Results)
	{
		cout << elem << "\n";
	}
	return 0;
}