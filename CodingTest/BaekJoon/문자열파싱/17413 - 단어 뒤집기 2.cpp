/*
 *17413 - 단어 뒤집기 2
 *
 *
 *string으로 받아서 한 줄을 배열로 처리한다
 *
 *태그 안에 띄어쓰기가 존재하므로 태그를 먼저 처리했다
 *이후 띄어쓰기와 <가 등장하면 단어가 끊어져 역전시키는 처리를 진행하면 된다
 *
 *
 */


#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string inputStr{};
	string token{};
	string result{};
	bool IsInTag = false;

	getline(cin, inputStr);

	for (int i = 0; i < inputStr.size(); i++)
	{
		//< 진입
		if (IsInTag)
		{
			token += inputStr[i];

			if (inputStr[i] == '>')
			{
				IsInTag = false;
				result += token;
				token.clear();
			}
			continue;
		}
		//> 종료
		if (inputStr[i] == '<' and token.empty())
		{
			token += inputStr[i];
			IsInTag = true;
			continue;
		}

		if (inputStr[i] == ' ' or inputStr[i] == '<')
		{
			for (int j = 0; j < token.size() / 2; j++)
			{
				char temp = token[j];
				token[j] = token[token.size() - j - 1];
				token[token.size() - j - 1] = temp;
			}
			result += token;
			if (inputStr[i] == ' ')
				result += ' ';
			if (inputStr[i] == '<')
			{
				IsInTag = true;
				token.clear();
				result += '<';
				continue;
			}
			token.clear();
			continue;
		}

		token += inputStr[i];
	}
	if (not token.empty())
	{
		for (int j = 0; j < token.size() / 2; j++)
		{
			char temp = token[j];
			token[j] = token[token.size() - j - 1];
			token[token.size() - j - 1] = temp;
		}
		result += token;
	}
	cout << result;


	return 0;
}