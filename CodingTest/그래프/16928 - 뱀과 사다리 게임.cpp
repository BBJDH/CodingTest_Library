
/*
��� ��ٸ��� �� �迭�� ����, ���������� �ε����� ���������� ���
������ �������κ��� 1~6��ŭ �湮�� �õ��ϰ� �湮�� ������ ��ٸ� �Ǵ� ���̶�� �ش� ������������ �湮
�湮�õ��� Count+1
100�� �湮�Ѵٸ� ����

*/

#include<iostream>
#include<vector>
#include<queue> 
#include<bitset>

using namespace std;


struct _int2
{
	int Pos;
	int Count;
};

bitset<101> Visit{};
int LadderAndSnakes[101]{};
int LadderCount = 0;
int SnakeCount = 0;
queue<_int2> BFS{};

void Push(_int2 const& Pos)
{
	if (!Visit[Pos.Pos])
	{
		BFS.push(Pos);
		Visit[Pos.Pos] = true;
	}
}

void RollDice(_int2 const& CurrentPos)
{
	for (int i = 1; i <= 6; i++)
	{
		_int2 NextPos = { CurrentPos.Pos + i, CurrentPos.Count + 1 };
		if (NextPos.Pos > 100)
			break;
		if (LadderAndSnakes[NextPos.Pos])
		{
			NextPos.Pos = LadderAndSnakes[NextPos.Pos];
		}
		Push(NextPos);
	}
}

void Game()
{
	while (!BFS.empty())
	{
		_int2 CurrentPos = BFS.front();
		BFS.pop();
		if (CurrentPos.Pos == 100)
		{
			cout << CurrentPos.Count;
			break;
		}
		RollDice(CurrentPos);
	}

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> LadderCount >> SnakeCount;

	int InputCount = LadderCount + SnakeCount;

	while (InputCount--)
	{

		int StartPos = 0;
		int DestPos = 0;

		cin >> StartPos >> DestPos;
		LadderAndSnakes[StartPos] = DestPos;

	}
	Push({ 1,0 });
	Game();
	return 0;
}

