/*
 *11655 - ROT13
 *
 *현재 문자TargetChar와 StartChar(대문자 혹은 소문자 A) 를 입력받아
 *
 * TargetChar - StartChar 가 13 이상이라면
 *
 *TargetChar - 13 인 문자를 반환하고
 *
 *이외에는 TargetChar + 13인 문자를 반환하는 함수를 작성한다.
 *
 *
 *문제의 입력을 getline을 통해 줄을 통째로 입력 받아
 *
 *알파벳일 경우에만 위의 함수를 호출하며 문자를 교체한다.
 *
 *모든문자가 교체된 후  바뀐 문자열을 출력한다.
 *
 */


#include<iostream>
#include <string>

using namespace std;

char GetCharNum(char const& TargetChar, char const& StartChar)
{
	if ((TargetChar - StartChar) >= 13)
	{
		return (TargetChar - 13);
	}
	return (TargetChar + 13);
}

void ROT13(string& InputStr)
{
	for (char& Elem : InputStr)
	{
		if (('A' <= Elem and Elem <= 'Z'))
		{
			Elem = GetCharNum(Elem, 'A');
		}
		if ('a' <= Elem and Elem <= 'z')
		{
			Elem = GetCharNum(Elem, 'a');
		}
	}
}


int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string InputStr{};

	getline(cin, InputStr);

	ROT13(InputStr);

	cout << InputStr;

	return 0;
}