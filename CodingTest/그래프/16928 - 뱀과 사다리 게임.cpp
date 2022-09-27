
/*
뱀과 사다리를 한 배열에 보관, 시작지점의 인덱스로 도착지점을 기록
지정된 지점으로부터 1~6만큼 방문을 시도하고 방문할 지점이 사다리 또는 뱀이라면 해당 도착지점으로 방문
방문시도시 Count+1
100을 방문한다면 종료

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

