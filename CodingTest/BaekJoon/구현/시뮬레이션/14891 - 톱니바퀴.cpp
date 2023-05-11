/*
 *14891 - 톱니바퀴
 *
 *Deque를 이용해 풀이 했다.
 *
 *각 톱니바퀴(Gear)를 Deque로 지정하고 (S면 true, N은 false)
 *동쪽 톱니바퀴는 0번 인덱스,
 *서쪽 톱니바퀴는 4번 인덱스,
 *북쪽 톱니바퀴는 6번 인덱스로 지정한다.
 *
 *시계방향은 deque의 뒤에서 빼서 앞으로 집어넣고
 *반시계방향은 앞에서 빼서 뒤로 넣어 처리한다.
 *
 *각 Gear가 도는 경우의 수는 요구사항 그대로 조건문으로 작성하되,
 *쉽게 작성할 수 있도록 Gear가 회전하는 함수를 별도로 작성했다.
 *
 *모든 기어가 돌아간뒤, 북쪽 톱니바퀴인 6번 인덱스를 확인하여 점수를 합산한다.
 *
 *각 기어를 벡터로 만든다면 2^(인덱스)로 합산되니 이런 규칙을 이용해
 *pow로 점수를 합산했다.
 *
 *
 */


#include <iostream>
#include <deque>
#include <vector>
#include <cmath>

using namespace std;

void MakeGear(string const& InStr, deque<bool>& Gear)
{
	for (int i = 0; i < 8; i++)
	{
		int Elem = false;
		int const index = (i + 2) % 8;
		if (InStr[index] == '1')
		{
			Elem = true;
		}
		Gear.push_back(Elem);
	}
}

void RotateSingleGear(deque<bool>& Gear, bool const Direction)
{
	if (Direction == true)
	{
		//시계 방향
		int const Elem = Gear.back();
		Gear.pop_back();
		Gear.push_front(Elem);
	}
	else
	{
		//반시계 방향
		int const Elem = Gear.front();
		Gear.pop_front();
		Gear.push_back(Elem);
	}
}

void RotateAllGear(vector<deque<bool>>& Gears, int const SrcGear, bool IsClockWise)
{
	if (SrcGear == 0)
	{
		if (Gears[0][0] == Gears[1][4])
		{
			RotateSingleGear(Gears[0], IsClockWise);
			return;
		}
		RotateSingleGear(Gears[0], IsClockWise);
		IsClockWise = !IsClockWise;

		if (Gears[1][0] == Gears[2][4])
		{
			RotateSingleGear(Gears[1], IsClockWise);
			return;
		}
		RotateSingleGear(Gears[1], IsClockWise);
		IsClockWise = !IsClockWise;

		if (Gears[2][0] == Gears[3][4])
		{
			RotateSingleGear(Gears[2], IsClockWise);
			return;
		}
		RotateSingleGear(Gears[2], IsClockWise);
		IsClockWise = !IsClockWise;
		RotateSingleGear(Gears[3], IsClockWise);
		return;
	}

	if (SrcGear == 3)
	{
		if (Gears[3][4] == Gears[2][0])
		{
			RotateSingleGear(Gears[3], IsClockWise);
			return;
		}
		RotateSingleGear(Gears[3], IsClockWise);
		IsClockWise = !IsClockWise;

		if (Gears[2][4] == Gears[1][0])
		{
			RotateSingleGear(Gears[2], IsClockWise);
			return;
		}
		RotateSingleGear(Gears[2], IsClockWise);
		IsClockWise = !IsClockWise;

		if (Gears[1][4] == Gears[0][0])
		{
			RotateSingleGear(Gears[1], IsClockWise);
			return;
		}
		RotateSingleGear(Gears[1], IsClockWise);
		IsClockWise = !IsClockWise;
		RotateSingleGear(Gears[0], IsClockWise);
		return;
	}

	if (SrcGear == 1)
	{
		if (Gears[0][0] != Gears[1][4])
		{
			RotateSingleGear(Gears[0], !IsClockWise);
		}


		if (Gears[1][0] == Gears[2][4])
		{
			RotateSingleGear(Gears[1], IsClockWise);
			return;
		}
		RotateSingleGear(Gears[1], IsClockWise);
		IsClockWise = !IsClockWise;

		if (Gears[2][0] == Gears[3][4])
		{
			RotateSingleGear(Gears[2], IsClockWise);
			return;
		}
		RotateSingleGear(Gears[2], IsClockWise);
		IsClockWise = !IsClockWise;
		RotateSingleGear(Gears[3], IsClockWise);
		return;
	}

	if (SrcGear == 2)
	{
		if (Gears[3][4] != Gears[2][0])
		{
			RotateSingleGear(Gears[3], !IsClockWise);

		}


		if (Gears[2][4] == Gears[1][0])
		{
			RotateSingleGear(Gears[2], IsClockWise);
			return;
		}
		RotateSingleGear(Gears[2], IsClockWise);
		IsClockWise = !IsClockWise;

		if (Gears[1][4] == Gears[0][0])
		{
			RotateSingleGear(Gears[1], IsClockWise);
			return;
		}
		RotateSingleGear(Gears[1], IsClockWise);
		IsClockWise = !IsClockWise;
		RotateSingleGear(Gears[0], IsClockWise);
		return;
	}
}

void GetScore(vector<deque<bool>> const& Gears)
{
	int Result = 0;
	for (int i = 0; i < 4; i++)
	{
		if (Gears[i][6] == true)
		{
			Result += static_cast<int>(pow(2, i));
		}
	}
	cout << Result;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	vector<deque<bool>> Gears{};
	Gears.resize(4);

	for (int i = 0; i < 4; i++)
	{
		string InputStr{};
		cin >> InputStr;
		MakeGear(InputStr, Gears[i]);
	}

	int RotateCount = 0;
	cin >> RotateCount;
	while (RotateCount--)
	{
		int GearNum = 0, DirectionNum = 0;
		cin >> GearNum >> DirectionNum;
		bool IsClockWise = false;
		if (DirectionNum == 1)
		{
			IsClockWise = true;
		}
		RotateAllGear(Gears, GearNum - 1, IsClockWise);
	}
	GetScore(Gears);
	return 0;
}