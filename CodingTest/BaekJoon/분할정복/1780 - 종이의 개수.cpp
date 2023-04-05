/*
 *1780 - 종이의 개수
 *
 *분할정복을 통해 풀이 가능하다.
 *
 *9구역으로 나누어 나눈 구역의 크기가 1이 될때까지 분할한다
 *
 *분할된 구역이 1, 0, 1- 인지를 구분하여 값을 반환받는다
 *
 *반환받은 9구역이 모두 일치한다면 해당 구역이 1, 0, -1 인지를 판별하여 반환한다.
 *
 *일치하지 않는다면 1, 0, -1의 갯수를 카운팅하고 2를 반환한다
 *(2는 해당 구역이 불일치 상태이며 이 지역은 더이상 카운팅할 필요 없다는 의미로 사용한다.)
 *
 *주어지는 입력도 친절하게 3분할씩 가능하도록 3의 지수로 들어온다.
 *종이의 왼쪽 상단인 {0,0}과 현재 종이의 사이즈를 넘겨 최종적으로 이 종이가 한장짜리 종이인지도 확인해준다.
 *
 *이후 누적된 카운트들을 요구사항대로 출력해준다.
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
vector<vector<int>> Map{};
int CountOfZero = 0;
int CountOfOne = 0;
int CountOfMinusOne = 0;
int DivideAndConquer(_int2 const& StartPos, int const Size)
{
	if (Size == 1)
	{
		return Map[StartPos.Y][StartPos.X];
	}

	int CurrentZeroCount = 0;
	int CurrentOneCount = 0;
	int CurrentMinusCount = 0;

	for (int y = StartPos.Y; y < StartPos.Y + Size; y = y + (Size / 3))
	{
		for (int x = StartPos.X; x < StartPos.X + Size; x = x + (Size / 3))
		{
			int Result = DivideAndConquer({ x,y }, Size / 3);
			if (Result == -1)
			{
				CurrentMinusCount++;
				continue;
			}
			if (Result == 0)
			{
				CurrentZeroCount++;
				continue;
			}
			if (Result == 1)
			{
				CurrentOneCount++;
				continue;
			}
		}
	}

	//9구역 일치하는 경우
	if (CurrentMinusCount == 9)
	{
		return -1;
	}
	if (CurrentZeroCount == 9)
	{
		return 0;
	}
	if (CurrentOneCount == 9)
	{
		return 1;
	}

	//하나라도 일치하지않는다면 카운팅 올려주고 불일치 반환
	CountOfZero += CurrentZeroCount;
	CountOfOne += CurrentOneCount;
	CountOfMinusOne += CurrentMinusCount;
	return 2;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int Size = 0;
	cin >> Size;
	Map.resize(Size);
	for (int y = 0; y < Size; y++)
	{
		Map[y].resize(Size);
		for (int x = 0; x < Size; x++)
		{
			cin >> Map[y][x];
		}
	}

	int const Result = DivideAndConquer({ 0,0 }, Size);
	if (Result == 1)
	{
		CountOfOne++;
	}
	if (Result == 0)
	{
		CountOfZero++;
	}
	if (Result == -1)
	{
		CountOfMinusOne++;
	}
	cout << CountOfMinusOne << "\n";
	cout << CountOfZero << "\n";
	cout << CountOfOne << "\n";

	return 0;
}