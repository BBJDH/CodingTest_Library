/*
 *10798 - 세로읽기
 *
 *입력받는 문자열을 5개를 char 2차원 배열에 집어 넣는다.
 *
 *vector를 이용해 2차원 배열을 구형하여 각 행마다 사이즈를 알 수 있게 했다.
 *
 *이후 임의의 좌표와 이차원 벡터를 넘겨주면 해당 위치의 문자를 출력해주는 함수를 작성한다.
 *
 *만약 해당 좌표가 벡터의 접근 사이즈를 넘었다면 아무것도 출력하지 않는다.
 *
 *이것을 문제의 요구대로 X로는 15개 y로는 5개 만큼 순환하여 출력한다.
 *
 *
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void PrintChar(vector<vector<char>> const& InputChar, int const X, int const Y)
{
	if (X >= InputChar[Y].size())
	{
		return;
	}
	cout << InputChar[Y][X];
}


int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	vector<vector<char>> InputChar{};
	InputChar.resize(5);
	for (int i = 0; i < 5; i++)
	{
		string InputStr{};
		getline(cin, InputStr);
		for (char const elem : InputStr)
		{
			if (elem == ' ')
			{
				break;
			}
			InputChar[i].push_back(elem);
		}
	}

	for (int x = 0; x < 15; x++)
	{
		for (int y = 0; y < 5; y++)
		{
			PrintChar(InputChar, x, y);
		}
	}

	return 0;
}