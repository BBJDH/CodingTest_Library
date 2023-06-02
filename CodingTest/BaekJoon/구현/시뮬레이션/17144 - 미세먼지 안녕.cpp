/*
 *
 * 17144 - �̼����� �ȳ�!
 *
 * 4 3 1
 *
 * 0 30 7
 * -1 10 0
 * -1 0 20
 * 0 0 0
 *
 * �� Ȯ��Ǹ�
 *
 * 6 15 11
 * 0 10 7
 * 0 6 8
 * 0 0 4
 *
 * ���� ���� û���Ⱑ �۵��Ѵٸ�
 *
 * 15 11 7
 * 0 0 10
 * 0 0 6
 * 0 4 8
 *
 * �� ������ ��ģ��.
 *
 *assert�� ���� ���� û����� �Ѱ��ҿ��� ��ġ���� Ȯ���ߴ�.
 *
 *���� ���� �Է½� ���� û���� ��ġ�� AirCeanerCounterClockWise, AirCeanerClockWise�� �����ϰ�
 *-1�� 0���� ��ü�Ͽ� �����Ѵ�.
 *
 *Ȯ�� �Լ�(Diffusion �Լ�)
 *�Է¹��� Map�� ���� ũ�� 2���� �迭�� ���� Ȯ���� ����ϵ� ���� ���� û���� ��ġ�� �����Ͽ� Ȯ���Ѵ�.
 *Ȯ��� 5�� ���� ����ŭ Ȯ��ǹǷ� 4���ϴ� �ݵ�� Ȯ����� �ʴ´�.
 *
 *����û���� Ȯ�� ó���� ���� �̿��� ȸ�������� ���� �����Ͽ� �� ���Ҹ� ������ �� �տ� 0�� �߰��Ͽ� ȸ��ó���Ѵ�.
 *
 *
 *����û����, ����ȸ�� �Լ�(Rotate �Լ�)
 *�ð� ����� �ݴ������ ��� �� �Լ��� ó���� �� �ֵ��� ����, �Ʒ�, ����, �� ������ Direction �迭�� �����,
 *�ð�����̸� �ε����� +1�� �����Ͽ� 2���� �迭�� �����ϰ�
 *�ݽð� �����̸� �ε����� -1�� �����ϵ� ������ �Ȱ�� �ε��� 3���� ���� �����ϵ��� �Ͽ� �迭�� ���� ó���Ѵ�.
 *
 *���� 4�������� ȸ���ϸ� ���� �����ϰ� ���� ������ �ٽ� Map�� ���� ������ �����̹Ƿ�
 *���� �� �տ� 0�� �߰�(����û���� ��ġ), ������ �ϳ� ����(����û����� ������ ����) ó�� �Ѵ�.
 *
 *������� ���� ���� ������ ������� �ٽ� 4���� ȸ���ϸ� Map�� ���� ������ �� �����Ѵ�.
 *
 *
 *�־��� Time ��ŭ ���� Diffusion, Rotate �Լ��� ȣ���Ͽ� �ð��� ��� ���� ���� ����� ����Ѵ�.
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

//����, �Ʒ�, ����, �� ��
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