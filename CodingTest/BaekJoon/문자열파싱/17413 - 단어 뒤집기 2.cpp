/*
 *17413 - �ܾ� ������ 2
 *
 *
 *string���� �޾Ƽ� �� ���� �迭�� ó���Ѵ�
 *
 *�±� �ȿ� ���Ⱑ �����ϹǷ� �±׸� ���� ó���ߴ�
 *���� ����� <�� �����ϸ� �ܾ ������ ������Ű�� ó���� �����ϸ� �ȴ�
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
		//< ����
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
		//> ����
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