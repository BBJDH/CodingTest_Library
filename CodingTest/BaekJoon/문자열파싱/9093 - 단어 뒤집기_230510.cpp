/*
 *9093 - 단어 뒤집기_230510
 *
 *단어 하나를 뒤집어 출력하는 것은 간단하다.
 *
 *관건은 문장으로 입력받아 띄어쓰기 단위로 단어를 뒤집어 출력해야 하는 것이다.
 *
 *따라서 문제를 뒤집어 출력하는 것과,
 *단어 단위로 자르는것 두 가지 문제로 처리한다.
 *
 *먼저 getline을 통해 한줄을 string에 입력받고,
 *이것을 stream으로 저장해 ' '단위로 끊어 string에 다시 저장한다.
 *
 *이렇게된 string은 하나의 Word로서 거꾸로 출력해주기만 하면 된다.
 *
 *위의 과정을 TestCase 수 만큼 반복한다.
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int TestCase = 0;
	cin >> TestCase;
	cin.ignore();
	while (TestCase--)
	{
		string InputLine{};
		getline(cin, InputLine);

		stringstream SS(InputLine);
		vector<string> Words{};
		string Word{};
		while (getline(SS, Word, ' '))
		{
			for (int i = static_cast<int>(Word.size() - 1); i >= 0; i--)
			{
				cout << Word[i];
			}
			cout << " ";
		}


		cout << "\n";
	}

	return 0;
}