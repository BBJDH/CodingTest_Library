/*
 *1018 - ü���� �ٽ� ĥ�ϱ�
 *
 *�Էµ� ������ ũ��� �ִ� 50X50�̴�
 *�� 42*42�� 1764 ����� ���� ���� ù ���� ����� ���, �������ΰ��
 *64ĭ�� �����ָ� �ȴ�.
 *�� Ƚ���� ����غ���, 1764 * 128(64+64) = 225792
 *
 *�̹Ƿ� ���Ʈ������ Ǯ�̰� �����ϴ�.
 *
 *ó������ BW�� �����Ƽ� ���� üũ�Ϸ�������,
 *������ ���� ��� ���� �ۼ��ؾ� �ϹǷ� �ڵ尡 ����������.
 *
 *������ �̸� ������ ü����(���, ������ ���� �ΰ���)��
 *
 *������ ���������� �Է¹޾Ƽ� �� ó���ߴ�.
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