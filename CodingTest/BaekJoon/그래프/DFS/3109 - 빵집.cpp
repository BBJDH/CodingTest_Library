/*
 *3109 -  ����
 *
 *
 *�� �� Ȥ�� �� �Ʒ����� �������� �����س��� �Ϸ� �Ǿ��ٸ� �� ���� 1���� �����Ѵ�
 *(�湮 ó���� �����Ѵ�.)
 *���ʴ�� ���̻� �������� ���� �Ұ����Ҷ����� �����Ѵ�.
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