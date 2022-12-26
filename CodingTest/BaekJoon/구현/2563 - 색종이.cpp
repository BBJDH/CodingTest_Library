/*
 *2563 - 색종이
 *
 *들어오는 좌표대로 10*10 공간을 칠할 2차원 배열 bool 공간을 만든다
 *
 *입력을 받으면서 색종이크기만큼 true로 바꿔 준후
 *
 *전체 bool공간을 완전 탐색하여 true 갯수를 출력한다.
 *
 */


#include <iostream>

using namespace std;

struct _int2
{
	int X;
	int Y;
};

bool Map[101][101]{};



void Paint(_int2 const& Start)
{
	for (int y = Start.Y; y < Start.Y + 10; y++)
	{
		for (int x = Start.X; x < Start.X + 10; x++)
		{
			Map[y][x] = true;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;

	cin >> N;

	int answer = 0;

	for (int i = 0; i < N; i++)
	{
		_int2 inputPos{};
		cin >> inputPos.X >> inputPos.Y;
		Paint(inputPos);
	}
	for (int y = 0; y < 101; y++)
	{
		for (int x = 0; x < 101; x++)
		{
			if (Map[y][x] == true)
				answer++;
		}
	}
	cout << answer;

	return 0;
}