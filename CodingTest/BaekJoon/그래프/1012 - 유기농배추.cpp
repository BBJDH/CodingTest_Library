
/*
1012 - ����� ����

�׷��� Ž�������̴�
�����������κ��� �¿���ϸ� Ž���ؼ� ���̻� ������ ����+1�� ���ش�
���������� �׳� �Է¹������ ��� ����ִ´� (������ �湮ó�������� ƨ���������� ����)
��� ���������� Ž���� �� �÷����� �������� ��ȯ
���� ���̽� ������ Ŭ��� ������

*/

#include<iostream>
#include<vector>
#include<bitset>
#include<queue>

using namespace std;

struct _int2
{
	int X;
	int Y;
};

queue<_int2>BFS_Queue{};
vector<bitset<50>> Visit{};
vector<_int2> InputArr{};
_int2 Direction[4] = { {1,0},{-1,0},{0,1},{0,-1} };

int Width = 0;
int Height = 0;

int Answer = 0;

void Push(_int2 const& VisitPos)
{
	if (VisitPos.X >= 0 and VisitPos.Y >= 0 and VisitPos.X < Width and VisitPos.Y < Height and Visit[VisitPos.Y][VisitPos.X] == true)
	{
		BFS_Queue.push(VisitPos);
		Visit[VisitPos.Y][VisitPos.X] = false;
	}
}
void VisitDirection(_int2 const& CurrentPos)
{
	for (int i = 0; i < 4; i++)
	{
		_int2 const NextPos = { CurrentPos.X + Direction[i].X , CurrentPos.Y + Direction[i].Y };
		Push(NextPos);
	}
}

void BFS(_int2 const& StartPos)
{
	if (Visit[StartPos.Y][StartPos.X] == false)
		return;

	Push(StartPos);

	while (!BFS_Queue.empty())
	{
		_int2 const CurrentPos = BFS_Queue.front();
		BFS_Queue.pop();
		VisitDirection(CurrentPos);
	}
	Answer++;
}

void Clear()
{
	Answer = 0;
	Width = 0;
	Height = 0;

	for (int i = 0; i < Visit.size(); i++)
		Visit[i].reset();
	InputArr.clear();
}

int	main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int TestCase = 0;
	cin >> TestCase;
	Visit.resize(50);
	while (TestCase--)
	{
		int InputCount = 0;
		cin >> Width >> Height >> InputCount;
		while (InputCount--)
		{
			_int2 InputPos{};

			cin >> InputPos.X >> InputPos.Y;
			InputArr.push_back(InputPos);
			Visit[InputPos.Y][InputPos.X] = true;
		}
		for (int i = 0; i < InputArr.size(); i++)
		{
			BFS(InputArr[i]);
		}
		cout << Answer << "\n";
		Clear();
	}


	return 0;
}