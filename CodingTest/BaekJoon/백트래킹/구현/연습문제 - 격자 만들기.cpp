/*
 *
 *======================================
 *
 *연습문제 - 격자 만들기
 *
 *백트래킹 및 구현을 통해 풀었다.
 *
 *각 백트래킹에서 0 ~3으로 X범위를 잡아
 *위에서 하나씩 떨어뜨려 새로운 백트래킹한다.
 *
 *떨어뜨릴 위치 y높이 (x는 정해져 있으므로)를 반환하는 함수를 작성해
 *
 *각 x에 대하여 쌓일 위치를 먼저 구하고
 *
 *해당 위치에 지정된 블록을 놓았을때 타겟 vector<string> 과 일치한다면
 *
 *다음 백트래킹을 진행도록한다.
 *
 *성공시 true를 반환하도록 하여 함수를 종료시키며
 *
 *모두 실패하고 함수가 종료된다면 false 반환하도록 하여 1과 0으로 구분하여
 *
 *출력한다.
 *
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;


int GetY(vector<string> const& Current, int X)
{
	int Result = -1;
	for (int y = 3; y >= 0; y--)
	{
		if (Current[y][X] == '-')
		{
			Result = y;
			break;
		}
	}
	return Result;
}

bool BackTracking(vector<string> const& Target, vector<string> &Current, char Block = 'o')
{
	int Result = 0;
	for (int i = 0; i < 4; i++)
	{
		if (Target[i] == Current[i])
		{
			Result++;
		}
	}

	if (Result == 4)
	{
		return true;
	}


	//0~3 순으로 삽입 시도
	bool IsSucceed = false;
	for (int X = 0; X < 4; X++)
	{
		//삽입
		int const Y = GetY(Current, X);

		if (Y == -1)
		{
			continue;
		}

		if (Target[Y][X] == Block)
		{
			Current[Y][X] = Block;
			if (Block == 'o')
			{
				IsSucceed |= BackTracking(Target, Current, 'x');
			}
			else
			{
				IsSucceed |= BackTracking(Target, Current, 'o');
			}
			Current[Y][X] = '-';
		}

	}


	return IsSucceed;
}

vector<int> solution(vector<vector<string>> boards)
{
	vector<int> answer{};
	vector<string> Start = { "----","----" , "----" , "----" };
	for (vector<string> const Board : boards)
	{

		if (BackTracking(Board, Start) == true)
		{
			answer.push_back(1);
		}
		else
		{
			answer.push_back(0);
		}
	}
	for (int const elem : answer)
		cout << elem << " ";
	return answer;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	//solution({ { "----","----" , "----" , "----" } });
	solution({ { "----", "----", "-o--", "-xo-"},{"---o", "---x", "---x", "---o" } });
	//solution({{ "----","----" , "--x-" , "--o-" },
	//	{ "----","----" , "----" , "--oo" }
	//	, { "----","----" , "----" , "x-o-" } });

	//Solution({{ "ooxx","xxxx" , "xxoo" , "oooo" },
	//{ "o---","----" , "----" , "----" }
	//, { "----","----" , "xxxx" , "xoox" } });

	return 0;
}
