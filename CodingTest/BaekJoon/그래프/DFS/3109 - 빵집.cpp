/*
 *3109 -  빵집
 *
 *
 *맨 위 혹은 맨 아래부터 파이프를 연결해나가 완료 되었다면 이 길을 1개로 인정한다
 *(방문 처리도 진행한다.)
 *차례대로 더이상 파이프를 연결 불가능할때까지 지속한다.
 *
 */


#include <iostream>

using namespace  std;

struct _int2
{
	int X;
	int Y;
};

char Map[10000][500]{};
bool Visit[10000][500]{};
_int2 Direction[3] = { {1,-1},{1,0},{1,1} };


int R = 0, C = 0;


bool DFS(_int2 const& Current)
{

	Visit[Current.Y][Current.X] = true;
	if (Current.X == C - 1)
		return true;

	for (int i = 0; i < 3; i++)
	{
		_int2 Next{};
		Next.X = Current.X + Direction[i].X;
		Next.Y = Current.Y + Direction[i].Y;

		if (Next.X < C and Next.Y >= 0 and Next.Y < R
			and Map[Next.Y][Next.X] != 'x' and Visit[Next.Y][Next.X] == false and DFS(Next))
		{
			return true;
		}
	}
	return false;
}


void Solution()
{
	int count = 0;
	for (int i = 0; i < R; i++)
	{
		if (DFS({ 0,i }))
			count++;

	}
	cout << count;
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	cin >> R >> C;

	for (int y = 0; y < R; y++)
	{
		for (int x = 0; x < C; x++)
		{
			cin >> Map[y][x];
		}
	}
	Solution();

	return 0;
}