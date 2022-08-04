#include<iostream>
#include<queue>
#include <vector>
#include <string>
using namespace std;

struct _int2
{
	int X;
	int Y;
};
struct MoveData
{
	_int2 Locatrion;
	int MoveCount;
	bool CanBreakAble;
};
_int2 Direction[4] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
vector<vector<int>> Map;
vector<int> Results;
queue<MoveData> BFS_Queue;

int MapX = 0;
int MapY = 0;

void Push(MoveData const& PushData)
{
	int const IndexX = PushData.Locatrion.X;
	int const IndexY = PushData.Locatrion.Y;
	//도착했다면 이동한 비용을 배열에 추가
	if (IndexX == MapX and IndexY == MapY)
	{
		Results.push_back(PushData.MoveCount);
		return;
	}

	//유효한 위치인지 검사(벽 포함)
	if (IndexX > 0 and IndexX <= MapX and IndexY > 0 and IndexY <= MapY
		and Map[IndexY][IndexX] != -1)
	{
		//벽을 부순경우는 방문 표시를 -2로, 부수지않은 경우는 -1로 표시
		//벽을 부수지 않는 경우의 수는 -2를 통과 가능하고 지나면 -1로 표시
		//벽을 부순 경우의 수는 -2 와 -1 모두 지나지 않음

		//해당 지점이 벽 이면서 아직 부술 기회가 있다면 부숨
		if (Map[IndexY][IndexX] == 1 and PushData.CanBreakAble)
		{
			BFS_Queue.push({ PushData.Locatrion, PushData.MoveCount, false });
			Map[IndexY][IndexX] = -1;
		}
		else if (Map[IndexY][IndexX] == 0)
		{
			//안가본 경로라면
			BFS_Queue.push({ PushData.Locatrion, PushData.MoveCount, PushData.CanBreakAble });
			if (PushData.CanBreakAble)
				Map[IndexY][IndexX] = -1;
			else
				Map[IndexY][IndexX] = -2;
		}
		else if (Map[IndexY][IndexX] == -2 and PushData.CanBreakAble)
		{
			BFS_Queue.push({ PushData.Locatrion, PushData.MoveCount, PushData.CanBreakAble });
			Map[IndexY][IndexX] = -1;
		}
	}
}

void Push_Queue(MoveData const& CurrentData)
{
	//맵 고려하지않고 그냥 4방위로 Push()를 Call
	//Push에서 유효성을 검사함
	for (int i = 0; i < 4; i++)
	{
		_int2 const CurrentLocation = { CurrentData.Locatrion.X + Direction[i].X, CurrentData.Locatrion.Y + Direction[i].Y };
		Push({ CurrentLocation, CurrentData.MoveCount + 1, CurrentData.CanBreakAble });
	}
}

void BFS()
{
	while (!BFS_Queue.empty())
	{
		MoveData const CurrentData = BFS_Queue.front();
		BFS_Queue.pop();
		Push_Queue(CurrentData);
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	cin >> MapY >> MapX;
	Map.push_back({});

	for (int i = 1; i <= MapY; i++)
	{
		Map.push_back({});
		string MapInput{};
		cin >> MapInput;
		Map[i].push_back(0);

		for (int k = 0; k < MapX; k++)
		{
			int const MapElem = MapInput[k] - '0';
			Map[i].push_back(MapElem);
		}
	}
	Push({ { 1,1 },1,true });
	BFS();
	if (Results.empty())
		cout << -1;
	else
		cout << Results[0];
	return 0;
}
