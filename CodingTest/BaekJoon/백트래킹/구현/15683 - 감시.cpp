/*
 * 15683 - 감시
 *
 *최대 맵의 크기는 64칸, CCTV의 개수도 8개이다
 *
 *따라서 모든 카메라를 4방향 모든 조합을 구한다고 해도 4^8 즉 6만 5천의 경우의 수를 가지며
 *
 *여기에 감시지역 마킹및 비감시지역 카운팅 비용을 100칸이라 한다고 하면 6,553,600 의 비용이 든다.
 *
 *따라서 주어진 1초의 시간 안애 충분히 풀이 가능하여
 *
 *브루트포스 및 백트래킹으로 완전 탐색하여 풀이했다.
 *
 *맵을 칠해서 넘기는 것이 아닌, 카매라의 조합을 만들어서 최종에서 주어진 맵을 복사하여
 *감시지역을 색칠하고 비감시 지역을 카운팅해 메모리 비용을 최소화 했다.
 *(최종 호출에서 맵이 복사된 후 사라지도록 구성)
 *
 *이후 계산된 BlindArea의 최소값을 매 조합의 끝단에서 업데이트하며
 *함수가 완전히 종료된 후 MinBlindArea를 출력한다.
 *
 */


#include <iostream>
#include <vector>

using namespace std;

struct _int2
{
	int X;
	int Y;
};

struct Camera
{
	int Type;
	_int2 Pos{};
	int Direction;
};

_int2 Size{};
vector<vector<int>> Map{};

// → ↑ ← ↓
_int2 Direction[4] = { {1,0}, {0,-1}, {-1,0}, {0,1} };
int MinBlindArea = 64;

void MarkAsDirection(int IndexOfDirection, _int2 const& Pos, vector<vector<int>>& CopiedMap)
{
	//주어진 방향으로 감시 지역을 기록
	_int2 CurrentPos = Pos;
	while (CurrentPos.X < Size.X and CurrentPos.X >= 0 and CurrentPos.Y < Size.Y and CurrentPos.Y >= 0 and CopiedMap[CurrentPos.Y][CurrentPos.X] != 6)
	{
		CopiedMap[CurrentPos.Y][CurrentPos.X] = 7;
		CurrentPos.X = CurrentPos.X + Direction[IndexOfDirection].X;
		CurrentPos.Y = CurrentPos.Y + Direction[IndexOfDirection].Y;
	}
}

void MarkCamArea(Camera const& Cam, vector<vector<int>>& CopiedMap)
{
	//Cam의 종류에 따라 각 방향 기록 함수 호출
	if (Cam.Type == 5)
	{
		for (int i = 0; i < 4; i++)
		{
			MarkAsDirection(i, Cam.Pos, CopiedMap);
		}
	}
	if (Cam.Type == 4)
	{
		for (int i = 0; i < 2; i++)
		{
			MarkAsDirection((i + Cam.Direction) % 4, Cam.Pos, CopiedMap);
		}
		MarkAsDirection((Cam.Direction + 3) % 4, Cam.Pos, CopiedMap);
	}
	if (Cam.Type == 3)
	{
		for (int i = 0; i < 2; i++)
		{
			MarkAsDirection((i + Cam.Direction) % 4, Cam.Pos, CopiedMap);
		}
	}
	if (Cam.Type == 2)
	{
		MarkAsDirection(Cam.Direction, Cam.Pos, CopiedMap);
		MarkAsDirection((Cam.Direction + 2) % 4, Cam.Pos, CopiedMap);
	}
	if (Cam.Type == 1)
	{
		MarkAsDirection(Cam.Direction, Cam.Pos, CopiedMap);
	}
}

int CheckBlindArea(vector<Camera> const& NewCamSet)
{
	vector<vector<int>> CopiedMap = Map;
	//주어진 각 카메라셋에 따른 감시구역 마킹
	for (Camera const& Elem : NewCamSet)
	{
		MarkCamArea(Elem, CopiedMap);
	}

	int Result = 0;
	for (int y = 0; y < Size.Y; y++)
	{
		for (int x = 0; x < Size.X; x++)
		{
			if (CopiedMap[y][x] == 0)
			{
				Result++;
			}
		}
	}
	return Result;
}

void BackTracking(int const CurrentCamIndex, vector<Camera> NewCamSet, vector<Camera> const& CameraSet)
{
	if (NewCamSet.size() == CameraSet.size())
	{
		MinBlindArea = min(MinBlindArea, CheckBlindArea(NewCamSet));
		return;
	}
	Camera NextSet = CameraSet[CurrentCamIndex];

	if (NextSet.Type == 5)
	{
		NewCamSet.push_back(NextSet);
		BackTracking(CurrentCamIndex + 1, NewCamSet, CameraSet);
		NewCamSet.pop_back();
	}
	else if (NextSet.Type == 2)
	{
		NextSet.Direction = 0;
		NewCamSet.push_back(NextSet);
		BackTracking(CurrentCamIndex + 1, NewCamSet, CameraSet);
		NewCamSet.pop_back();

		NextSet.Direction = 1;
		NewCamSet.push_back(NextSet);
		BackTracking(CurrentCamIndex + 1, NewCamSet, CameraSet);
		NewCamSet.pop_back();
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			NextSet.Direction = i;
			NewCamSet.push_back(NextSet);
			BackTracking(CurrentCamIndex + 1, NewCamSet, CameraSet);
			NewCamSet.pop_back();
		}
	}


}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	vector<Camera> CameraSet{};

	cin >> Size.Y >> Size.X;
	Map.resize(Size.Y);
	for (int y = 0; y < Size.Y; y++)
	{
		Map[y].resize(Size.X);
		for (int x = 0; x < Size.X; x++)
		{
			cin >> Map[y][x];

			if (Map[y][x] != 0 and Map[y][x] != 6)
			{
				CameraSet.push_back({ Map[y][x], {x,y}, 0 });
			}
		}
	}
	vector<Camera> NewCameraSet{};
	BackTracking(0, NewCameraSet, CameraSet);
	cout << MinBlindArea;
	return 0;
}