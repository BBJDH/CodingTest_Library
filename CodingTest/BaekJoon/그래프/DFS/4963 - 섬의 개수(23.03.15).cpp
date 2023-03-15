/*
 *4963 - ���� ����
 *
 *Direction �ϳ��� �߸� �Ҵ��� �ذῡ �ð��� �ɷȴ�.
 *({1,-1} ��� {1,1}�� �� �־���.)
 *
 *Ǯ�� ���
 *
 *�Է¹��� �� ���� ����� ������ �ξ��ٰ�
 *
 *Ž���� ���� ��� �ָ� ������ Ž���Ѵ�.
 *
 *
 *��������� ���� �湮�� �����ϱ�����
 *
 *�ش� ������ �湮���� ���� ���̶��
 *
 *�װ��� ���̶�� �����ϰ� ī��Ʈ�� �ø���.
 *
 *
 *Ž�� �Ϸ�� ���� Visit�� �̿��� ����ϰ�
 *
 *���� Ž������ �湮���� �ʵ��� ó���Ѵ�.
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

		//�ʱ�ȭ


		for (int i = 0; i < Size.Y; i++)
		{
			fill_n(Visit[i], Size.X, false);
		}

		//�湮 �ĺ� ��� (�����)
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

		//�湮 ����
		for (_int2 const& elem : PosOfStart)
		{
			if (Visit[elem.Y][elem.X] == false)
			{
				Result++;
				//DFS ��ŷ
				DFS(elem, Size);
			}
		}

		//��� ���
		cout << Result << "\n";

	}


	return 0;
}