/*
1799 - 비숍

row 범위 0 ~ (N-1)X2  => X+Y는 같은 대각선(우상단 - 좌하단)에서 합이 같다
col 범위 0 ~ (N-1)X2  => 마찬가지로 이번엔 좌상단 - 우하단 대각선은 X-Y가 일치한다
								(하지만 음수가 발생하므로 X-Y+N-1 로 방문기록)


01234
1
2
3
4

0시작 : 0 2 4 행넘김
		1 3 5 행넘김
		0 2 4...
		=> 홀수인덱스 홀수 시작 (0이면 (행+0)%2 로 시작)
1시작 : 1 3   행넘김
		0 2 4 행넘김
		1 3
		짝수 인덱스 홀수 시작 ((행+1)%2로 시작)
*/

#include<iostream>
#include<vector>

using namespace std;

struct _int2
{
	int X;
	int Y;
};

vector<bool> Row_Visit{};
vector<bool> Col_Visit{};

bool Blocked[10][10]{};
int Size = 0;
int ZeroColorMaxCount = 0;
int OneColorMaxCount = 0;

void DeployBishop(int Row, int Count, int const& StartColor)
{
	for (int y = Row; y < Size; y++)
	{

		for (int x = (y + StartColor) % 2; x < Size; x += 2)
		{
			int RowIndex = x + y;
			int ColIndex = x - y + Size - 1;
			if (Blocked[y][x] == true and Row_Visit[RowIndex] == false and Col_Visit[ColIndex] == false)
			{
				Row_Visit[RowIndex] = true;
				Col_Visit[ColIndex] = true;
				DeployBishop(y, Count + 1, StartColor);
				Row_Visit[RowIndex] = false;
				Col_Visit[ColIndex] = false;
			}
		}
	}

	if (StartColor)
		OneColorMaxCount = max(OneColorMaxCount, Count);
	else
		ZeroColorMaxCount = max(ZeroColorMaxCount, Count);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> Size;

	Row_Visit.resize((Size - 1) * 2 + 1);
	Col_Visit.resize((Size - 1) * 2 + 1);

	for (int y = 0; y < Size; y++)
	{
		for (int x = 0; x < Size; x++)
		{
			bool Input = false;
			cin >> Input;
			Blocked[y][x] = Input;
		}
	}

	DeployBishop(0, 0, 0);
	DeployBishop(0, 0, 1);

	cout << OneColorMaxCount + ZeroColorMaxCount;
	return 0;
}
