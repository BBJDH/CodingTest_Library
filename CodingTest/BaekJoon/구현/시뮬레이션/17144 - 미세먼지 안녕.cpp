/*
 *
 * 17144 - 미세먼지 안녕!
 *
 * 4 3 1
 *
 * 0 30 7
 * -1 10 0
 * -1 0 20
 * 0 0 0
 *
 * 이 확산되면
 *
 * 6 15 11
 * 0 10 7
 * 0 6 8
 * 0 0 4
 *
 * 이후 공기 청정기가 작동한다면
 *
 * 15 11 7
 * 0 0 10
 * 0 0 6
 * 0 4 8
 *
 * 의 과정을 거친다.
 *
 *assert를 통해 공기 청정기는 한개소에만 설치됨을 확인했다.
 *
 *따라서 최초 입력시 공기 청정기 위치를 AirCeanerCounterClockWise, AirCeanerClockWise에 저장하고
 *-1을 0으로 대체하여 저장한다.
 *
 *확산 함수(Diffusion 함수)
 *입력받은 Map과 같은 크기 2차원 배열에 다음 확산을 기록하되 위의 공기 청정기 위치를 참고하여 확산한다.
 *확산시 5로 나눈 수만큼 확산되므로 4이하는 반드시 확산되지 않는다.
 *
 *공기청정기 확산 처리는 덱을 이용해 회전방향을 따라 삽입하여 끝 원소를 제거한 후 앞에 0을 추가하여 회전처리한다.
 *
 *
 *공기청정기, 공기회전 함수(Rotate 함수)
 *시계 방향과 반대방향을 모두 한 함수에 처리할 수 있도록 우측, 아래, 왼쪽, 위 순서로 Direction 배열을 만들고,
 *시계방향이면 인덱스를 +1씩 증가하여 2차원 배열에 접근하고
 *반시계 방향이면 인덱스를 -1씩 증가하되 음수가 된경우 인덱스 3으로 부터 감소하도록 하여 배열에 접근 처리한다.
 *
 *이후 4방향으로 회전하며 덱에 삽입하고 같은 순서로 다시 Map에 값을 대입할 예정이므로
 *덱의 맨 앞에 0을 추가(공기청정기 위치), 끝원소 하나 제거(공기청정기로 빨려들어갈 원소) 처리 한다.
 *
 *만들어진 덱을 위와 동일한 방법으로 다시 4방향 회전하며 Map의 값을 수정한 후 종료한다.
 *
 *
 *주어진 Time 만큼 위의 Diffusion, Rotate 함수를 호출하여 시간이 모두 지난 후의 결과를 출력한다.
 *
 *
 */

#include <iostream>
#include <vector>
#include <deque>
#include <cassert>

using namespace std;

struct _int2
{
	int X;
	int Y;
};

//우측, 아래, 왼쪽, 위 순
_int2 Direction[4] = { {1,0}, {0,1} , {-1,0}, {0,-1} };
_int2 Size{};
_int2 AirCeanerCounterClockWise{};
_int2 AirCeanerClockWise{};


void Diffusion(vector<vector<int>>& Map)
{
	vector<vector<int>> NewMap{};
	NewMap.resize(Size.Y, vector<int>(Size.X, 0));

	for (int y = 0; y < Size.Y; y++)
	{
		for (int x = 0; x < Size.X; x++)
		{
			int SideCount = 0;

			if (Map[y][x] > 4)
			{
				for (int i = 0; i < 4; i++)
				{
					_int2 Side{};
					Side.X = x + Direction[i].X;
					Side.Y = y + Direction[i].Y;

					if (0 <= Side.X and Side.X < Size.X and 0 <= Side.Y and Side.Y < Size.Y and
						not((Side.X == AirCeanerClockWise.X and Side.Y == AirCeanerClockWise.Y) or (Side.X == AirCeanerCounterClockWise.X and Side.Y == AirCeanerCounterClockWise.Y)))
					{
						NewMap[Side.Y][Side.X] += Map[y][x] / 5;
						SideCount++;
					}
				}
			}

			NewMap[y][x] += (Map[y][x] - (SideCount * (Map[y][x] / 5)));

		}
	}
	Map = NewMap;
}

void Rotate(vector<vector<int>>& Map, _int2 const& Pos, _int2 RotateSize, int ClockWise)
{
	deque<int> Nums{};
	int DirectionIndex = 0;
	int PushCount = 0;
	int SideCount = 0;
	_int2 CurrentPos = Pos;
	while (true)
	{


		if ((DirectionIndex % 2 == 0 and PushCount == RotateSize.X - 1) or (DirectionIndex % 2 == 1 and PushCount == RotateSize.Y - 1))
		{
			PushCount = 0;
			DirectionIndex = DirectionIndex + ClockWise;
			if (DirectionIndex < 0)
			{
				DirectionIndex = 3;
			}
			SideCount++;
			if (SideCount == 4)
			{
				break;
			}
		}

		Nums.push_back(Map[CurrentPos.Y][CurrentPos.X]);
		PushCount++;
		CurrentPos.X = CurrentPos.X + Direction[DirectionIndex].X;
		CurrentPos.Y = CurrentPos.Y + Direction[DirectionIndex].Y;

	}
	Nums.pop_back();
	Nums.push_front(0);

	CurrentPos = Pos;
	DirectionIndex = 0;
	PushCount = 0;
	SideCount = 0;
	while (true)
	{


		if ((DirectionIndex % 2 == 0 and PushCount == RotateSize.X - 1) or (DirectionIndex % 2 == 1 and PushCount == RotateSize.Y - 1))
		{
			PushCount = 0;
			DirectionIndex = DirectionIndex + ClockWise;
			if (DirectionIndex < 0)
			{
				DirectionIndex = 3;
			}
			SideCount++;
			if (SideCount == 4)
			{
				break;
			}
		}
		Map[CurrentPos.Y][CurrentPos.X] = Nums.front();
		Nums.pop_front();
		PushCount++;
		CurrentPos.X = CurrentPos.X + Direction[DirectionIndex].X;
		CurrentPos.Y = CurrentPos.Y + Direction[DirectionIndex].Y;
	}
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int Time = 0;
	cin >> Size.Y >> Size.X;
	cin >> Time;

	vector<vector<int>> Map{};
	Map.resize(Size.Y, vector<int>(Size.X, 0));
	int AirCeanerCount = 0;

	for (int y = 0; y < Size.Y; y++)
	{
		for (int x = 0; x < Size.X; x++)
		{
			cin >> Map[y][x];
			if (Map[y][x] == -1)
			{
				Map[y][x] = 0;
				assert(AirCeanerCount < 2);
				if (AirCeanerCount == 0)
				{
					AirCeanerCounterClockWise = { x,y };
				}
				else
				{
					AirCeanerClockWise = { x,y };
				}
				AirCeanerCount++;
			}
		}
	}

	while (Time--)
	{
		Diffusion(Map);
		Rotate(Map, AirCeanerCounterClockWise, { Size.X, AirCeanerCounterClockWise.Y + 1 }, -1);
		Rotate(Map, AirCeanerClockWise, { Size.X, Size.Y - AirCeanerClockWise.Y }, 1);
	}

	int TotalDust = 0;

	for (int y = 0; y < Size.Y; y++)
	{
		for (int x = 0; x < Size.X; x++)
		{
			TotalDust += Map[y][x];
		}
	}
	cout << TotalDust;
	return 0;
}