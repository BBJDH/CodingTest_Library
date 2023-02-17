/*
 *1018 - 체스판 다시 칠하기
 *
 *입력된 보드의 크기는 최대 50X50이다
 *즉 42*42의 1764 경우의 수에 대해 첫 색이 흰색인 경우, 검은색인경우
 *64칸을 비교해주면 된다.
 *비교 횟수를 계산해보면, 1764 * 128(64+64) = 225792
 *
 *이므로 브루트포스로 풀이가 가능하다.
 *
 *처음에는 BW를 번갈아서 직접 체크하려했으나,
 *검은색 따로 흰색 따로 작성해야 하므로 코드가 난잡해진다.
 *
 *때문에 미리 만들어둔 체스판(흰색, 검은색 시작 두가지)에
 *
 *보드의 시작지점을 입력받아서 비교 처리했다.
 *
 */


#include <iostream>
#include <string>
#include <vector>

using namespace std;

string BlackFirst[8] = {
"BWBWBWBW",
"WBWBWBWB",
"BWBWBWBW",
"WBWBWBWB",
"BWBWBWBW",
"WBWBWBWB",
"BWBWBWBW",
"WBWBWBWB" };

string WhiteFirst[8] = {
"WBWBWBWB",
"BWBWBWBW",
"WBWBWBWB",
"BWBWBWBW",
"WBWBWBWB",
"BWBWBWBW",
"WBWBWBWB",
"BWBWBWBW" };

int SizeX = 0, SizeY = 0;
int MinCountToChange = 2501;
vector<string> InputStr{};

void UpdateCount(int StartX, int StartY)
{
	int CountWhiteFirst = 0;
	int CountBlackFirst = 0;
	int Result = 0;
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			if (InputStr[StartY + y][StartX + x] != WhiteFirst[y][x])
			{
				CountWhiteFirst++;
			}
			if (InputStr[StartY + y][StartX + x] != BlackFirst[y][x])
			{
				CountBlackFirst++;
			}
		}
	}
	Result = min(CountWhiteFirst, CountBlackFirst);
	MinCountToChange = min(MinCountToChange, Result);
}

void Solution()
{
	for (int y = 0; y <= SizeY - 8; y++)
	{
		for (int x = 0; x <= SizeX - 8; x++)
		{
			UpdateCount(x, y);
		}
	}
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> SizeY >> SizeX;

	for (int i = 0; i < SizeY; i++)
	{
		string input{};
		cin >> input;
		InputStr.push_back(input);
	}
	Solution();
	cout << MinCountToChange;

	return 0;
}