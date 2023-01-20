/*
 *11719 - 그대로 출력하기 2
 *
 *문제의 요구사항을 그대로 구현했다
 *최대 100줄이고 공백을 포함하므로
 *getline으로 100번 문자열을 라인단위로 받아 출력시킨다.
 *출력후 초기화처리는 필수, 다음 입력이 없을 수 있다.
 *
 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string inputStr{};

	for (int i = 0; i < 100; i++)
	{
		getline(cin, inputStr);
		//if (inputStr.empty())
		//	break;

		cout << inputStr << "\n";
		inputStr.clear();
	}


	return 0;
}