/*
 *1032 - 명령 프롬프트
 *
 *
 *단순 구현으로 풀이 가능하다.
 *
 *입력 받는 CountOfDir이 자연수이므로 최소한 한개이상 입력받는 것을 이용한다.
 *
 *미리 Result에 Dir를 저장해두고
 *
 *입력받은 전체 Dir들과 Result를 비교하여 하나라도 다른 문자가 등장한다면
 *
 *Result의 해당 인덱스의 문자를 '?'로 교체한다.
 *
 *반복문 통과후 Result를 출력한다.
 *
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int CountOfDir = 0;
	vector<string> Dir{};
	string Result{};
	cin >> CountOfDir;

	while (CountOfDir--)
	{
		string InputDir{};
		cin >> InputDir;
		if (CountOfDir == 0)
		{
			Result = InputDir;
		}
		Dir.push_back(InputDir);
	}


	for (int i = 0; i < Dir[0].size(); i++)
	{
		for (int j = 0; j < Dir.size(); j++)
		{
			if (Result[i] != Dir[j][i])
			{
				Result[i] = '?';
			}

		}
	}
	cout << Result;

	return 0;
}