/*
 *
 * 1100 - 하얀 칸
 *
 *
 *체스판의 크기가 8X8로 미리 흰색과 검은색이 칠해진 체스판을 만들고
 *모두 비교해보는 방법도 가능하다.
 *
 *하지만 좀 더 규칙을 찾아 풀어본다면, 다음과 같은 규칙을 찾을 수 있다.
 *
 *01234567
 *1
 *2
 *3
 *4
 *5
 *
 *O가 흰색, X가 검은색이라고 한다면
 *
 *OXOXOXOX
 *XOXOXOXO
 *OXOXOXOX
 *XOXOXOXO
 *
 *짝수 줄은 짝수 (0 2 4 6 8...)
 *홀수 줄은 홀수 인덱스에서 (1 3 5 7 9...) 흰색이 색칠된다.
 *
 *위의 규칙에 따라 흰색인지를 판별하는 함수를 작성,
 *이를 이용해 흰색 위에 말이 놓여있는지 8x8 탐색한다.
 *
 *
 */


#include<iostream>
#include <string>
#include <vector>

using namespace std;

bool IsWhite(int const X, int const Y)
{
	if (Y % 2 == X % 2)
	{
		return true;
	}
	return false;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	vector<string> Board{};


	//입력
	for (int i = 0; i < 8; i++)
	{
		string InputStr{};
		cin >> InputStr;
		Board.push_back(InputStr);
	}

	//8X8 확인 시작
	int Result = 0;

	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			if (IsWhite(x, y) == true and Board[y][x] == 'F')
			{
				Result++;
			}
		}
	}

	cout << Result;


	return 0;
}