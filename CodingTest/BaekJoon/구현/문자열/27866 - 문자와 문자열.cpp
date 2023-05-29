/*
 * 27866 - 문자와 문자열
 *
 * 문자열을 다루는 아주 간단한 문제
 *
 * string으로 입력 받아 입력받은 InputNum-1 번째 인덱스의 문자를 출력한다.
 *
 *
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string InputStr{};
	int InputNum = 0;


	cin >> InputStr >> InputNum;

	cout << InputStr[InputNum - 1];

	return 0;
}