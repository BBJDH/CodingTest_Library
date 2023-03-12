/*
 *10953 - A+B - 6
 *
 *문자열 파싱을 통해 사칙연산을 수행하는 문제이다
 *
 *문자열을 입력받아 이것을 stringstream에 넣어 파싱한다.
 *getline을 통해 stringstream을 지정 문자로 잘라 string에 넣는다
 *이 string을 stoi를 통해 정수로 파싱하여 합산한 결과를 출력한다.
 *
 */

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string InputStr{};
		string Token{};
		cin >> InputStr;
		stringstream SS_InputStr(InputStr);
		int Result = 0;
		while (getline(SS_InputStr, Token, ','))
		{
			Result += stoi(Token);
		}
		cout << Result << "\n";
	}

	return 0;
}