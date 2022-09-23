/*
10026 - 적록색약

간단하게 구역만큼  BFS 후 더이상 BFS 불가능하면 그룹 카운트를 올림
정상인지 색약인지 유무에 따른 컬러값을 설정 후 BFS

정상에대해 그룹카운팅이 끝난 후 방문 처리 초기화

*/
#include<iostream>
#include<queue>
#include<bitset>
#include<vector>

using namespace std;

struct Node
{
	int X;
	int Y;
};

vector<bitset<100>>Visits{};
queue<Node> BFS{};
Node Direction[4] = { {-1,0},{0,-1},{1,0},{0,1} };
vector<Node>StartPositions{};
vector<Node>StartPositions_RB{};
char Paints[100][100]{};

int PaintSize = 0;
int GroupCount = 0;
char CurrentColor[2]{};

void Push(Node const& VisitPos)
{
	if (VisitPos.X >= 0 and VisitPos.Y >= 0 and
		VisitPos.X < PaintSize and VisitPos.Y < PaintSize and
		Visits[VisitPos.Y][VisitPos.X] == false and
		(Paints[VisitPos.Y][VisitPos.X] == CurrentColor[0] or Paints[VisitPos.Y][VisitPos.X] == CurrentColor[1]))
	{
		Visits[VisitPos.Y][VisitPos.X] = true;
		BFS.push(VisitPos);
	}
}

void VisitSides(Node const& CurrentPos)
{
	for (int i = 0; i < 4; i++)
	{
		Push({ CurrentPos.X + Direction[i].X,CurrentPos.Y + Direction[i].Y });
	}
}
void SetCurrentColor(char const StartColor, bool IsWeakness)
{
	if (IsWeakness)
	{
		switch (StartColor)
		{
		case 'R':case 'G':
		{
			CurrentColor[0] = 'R';
			CurrentColor[1] = 'G';
			break;
		}
		case 'B':
		{
			CurrentColor[0] = 'B';
			CurrentColor[1] = ' ';
		}
		}
	}
	else
	{
		CurrentColor[0] = StartColor;
		CurrentColor[1] = ' ';

	}
}
void FindGroup(Node const& StartPos, bool IsWeakness)
{
	if (Visits[StartPos.Y][StartPos.X] == true)
		return;
	SetCurrentColor(Paints[StartPos.Y][StartPos.X], IsWeakness);
	Push(StartPos);
	while (!BFS.empty())
	{
		Node const CurrentPos = BFS.front();
		BFS.pop();
		VisitSides(CurrentPos);
	}

	GroupCount++;
}

void Solution()
{

	for (auto const& Elem : StartPositions)
		FindGroup(Elem, false);
	cout << GroupCount << ' ';
	GroupCount = 0;

	for (int i = 0; i < 100; i++)
		Visits[i].reset();

	for (auto const& Elem : StartPositions)
		FindGroup(Elem, true);
	cout << GroupCount;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	Visits.resize(100);
	cin >> PaintSize;
	char PrevColor{};
	for (int i = 0; i < PaintSize; i++)
	{
		for (int j = 0; j < PaintSize; j++)
		{
			char InputColor{};
			cin >> InputColor;
			Paints[i][j] = InputColor;

			StartPositions.push_back({ j,i });

		}
	}
	Solution();

	return 0;
}