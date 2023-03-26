/*
 *15686 - ġŲ ���
 *
 *���� ��ü ġŲ�� �� �� �Է¹��� ���ѵ� ġŲ�� ����ŭ�� ������ ��� ���ؾ� �Ѵ�.
 *
 *���� ���� ������ ���ϱ� ���� ��Ʈ��ŷ�� �̿��� ������ ġŲ���� ������ ���Ѵ�.
 *
 *������ ġŲ���鿡 ���� ġŲ�Ÿ��� ���Ѵ�. (���Ʈ���� Ȥ�� �׷���Ž���� �̿��Ѵ�.)
 *
 *���ÿ� ������ ġŲ�Ÿ��� �ּҰ��� ������Ʈ�ϸ� �����Ѵ�.
 *
 *��� ġŲ�� ���տ� ���� ġŲ�Ÿ��� ��� ���ߴٸ�
 *
 *���������� ������Ʈ �ؿ� ġŲ�Ÿ��� �ּҰ��� ��ȯ�Ѵ�.
 *
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

int GetDistance(_int2 const& Start, _int2 const& Dest)
{
	return abs(Start.X - Dest.X) + abs(Start.Y - Dest.Y);
}

int GetDistanceOfChiken(vector<_int2> const& LocationOfHouses, vector<_int2> const& LocationOfChikenHouses)
{
	int Result = 0;

	for (_int2 const Start : LocationOfHouses)
	{
		int MinDistance = 200;
		for (_int2 const Dest : LocationOfChikenHouses)
		{
			MinDistance = min(MinDistance, GetDistance(Start, Dest));
		}
		Result += MinDistance;
	}
	return Result;
}

void Backtracking(int const StartIndex, int const Size, int& Result, vector<_int2> const& LocationOfHouses, vector<_int2> const& LocationOfChikenHouses, vector<_int2> Combinations)
{
	if (Combinations.size() == Size)
	{
		Result = min(Result, GetDistanceOfChiken(LocationOfHouses, Combinations));
		return;
	}
	for (int i = StartIndex; i < LocationOfChikenHouses.size(); i++)
	{
		Combinations.push_back(LocationOfChikenHouses[i]);
		Backtracking(i + 1, Size, Result, LocationOfHouses, LocationOfChikenHouses, Combinations);
		Combinations.pop_back();
	}
}

void Solution(vector<_int2> const& LocationOfHouses, vector<_int2> const& LocationOfChikenHouses, int const MaxNumOfChikenHouses)
{
	int Result = 300000;
	vector<_int2> CombinationsOfChikenHouse{};
	Backtracking(0, MaxNumOfChikenHouses, Result,
		LocationOfHouses, LocationOfChikenHouses, CombinationsOfChikenHouse);
	cout << Result;
}


int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	vector<_int2> LocationOfHouses{};
	vector<_int2> LocationOfChikenHouses{};
	int Size = 0;
	int MaxNumOfChikenHouses = 0;

	cin >> Size >> MaxNumOfChikenHouses;

	for (int y = 0; y < Size; y++)
	{
		for (int x = 0; x < Size; x++)
		{
			int NumOfInput = 0;
			cin >> NumOfInput;
			if (NumOfInput == 1)
			{
				LocationOfHouses.push_back({ x,y });
			}
			else if (NumOfInput == 2)
			{
				LocationOfChikenHouses.push_back({ x,y });
			}
		}
	}
	Solution(LocationOfHouses, LocationOfChikenHouses, MaxNumOfChikenHouses);
	return 0;
}