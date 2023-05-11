/*
 *14891 - ��Ϲ���
 *
 *Deque�� �̿��� Ǯ�� �ߴ�.
 *
 *�� ��Ϲ���(Gear)�� Deque�� �����ϰ� (S�� true, N�� false)
 *���� ��Ϲ����� 0�� �ε���,
 *���� ��Ϲ����� 4�� �ε���,
 *���� ��Ϲ����� 6�� �ε����� �����Ѵ�.
 *
 *�ð������ deque�� �ڿ��� ���� ������ ����ְ�
 *�ݽð������ �տ��� ���� �ڷ� �־� ó���Ѵ�.
 *
 *�� Gear�� ���� ����� ���� �䱸���� �״�� ���ǹ����� �ۼ��ϵ�,
 *���� �ۼ��� �� �ֵ��� Gear�� ȸ���ϴ� �Լ��� ������ �ۼ��ߴ�.
 *
 *��� �� ���ư���, ���� ��Ϲ����� 6�� �ε����� Ȯ���Ͽ� ������ �ջ��Ѵ�.
 *
 *�� �� ���ͷ� ����ٸ� 2^(�ε���)�� �ջ�Ǵ� �̷� ��Ģ�� �̿���
 *pow�� ������ �ջ��ߴ�.
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
		//�ð� ����
		int const Elem = Gear.back();
		Gear.pop_back();
		Gear.push_front(Elem);
	}
	else
	{
		//�ݽð� ����
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