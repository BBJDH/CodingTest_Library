
/*
1213 - 펠린드롬 만들기

그냥 입력 받은대로 알파벳 수를 카운팅해주고
홀수인 알파벳이 1개를 초과한다면 그 문자열은 대칭을 만들 수 없다. I'm Sorry!
가능하다면 갯수2만큼 정순, 홀수문자가있다면 가운데에 출력해주고, 역순 이렇게 출력해주자

*/

#include<iostream>

using namespace std;

int AlphabetNum[26]{};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string InputStr{};

	cin >> InputStr;

	for (int i = 0; i < InputStr.size(); i++)
	{
		int Index = InputStr[i] - 'A';
		AlphabetNum[Index] ++;
	}

	int Count = 0;
	int OddAlphabet = 0;
	for (int i = 0; i < 26; i++)
	{
		if (AlphabetNum[i] % 2)
		{
			OddAlphabet = i;
			Count++;
		}
		AlphabetNum[i] /= 2;
	}
	if (Count > 1)
		cout << "I'm Sorry Hansoo";
	else
	{
		for (int i = 0; i < 26; i++)
		{
			for (int j = 0; j < AlphabetNum[i]; j++)
				cout << static_cast<char>(i + 'A');
		}
		if (Count == 1)
			cout << static_cast<char>(OddAlphabet + 'A');
		for (int i = 25; i >= 0; i--)
		{
			for (int j = 0; j < AlphabetNum[i]; j++)
				cout << static_cast<char>(i + 'A');
		}
	}

	return 0;
}
