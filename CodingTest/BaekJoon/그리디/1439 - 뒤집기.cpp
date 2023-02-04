/*
 *1439 - 뒤집기
 *
 *01 2 1
 *010 3 1
 *0101 4 2
 *01010 5 2
 *010101 6 3
 *
 *0과 1이 연속해서 있는 갯수를 카운트하고
 *
 *이것의 1/2을 출력한다.
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
	cin >> inputStr;

	char CurrChar = inputStr[0];
	int Count = 1;

	for (char const elem : inputStr)
	{
		if (CurrChar != elem)
		{
			CurrChar = elem;
			Count++;
		}
	}

	cout << (Count / 2);
	return 0;
}