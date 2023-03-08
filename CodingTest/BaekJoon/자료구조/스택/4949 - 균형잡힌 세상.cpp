/*
 *4949 - 균형잡힌 세상
 *
 *문제를 대충읽고 괄호의 카운트 수만 맞춰주면 되는것으로 착각했었다.
 *
 *스택을 이용해 괄호를 넣고 반대 괄호가 나온다면 top과 대조한 후 삭제한다.
 *
 *만약 top과 일치하지 않거나 .을 만났는데 스택에 괄호가 남아있다면 no를 출력한다.
 *
 *입력을 라인단위로 받을줄 안다면 문제가 굉장히 수월해진다.
 *
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	while (true)
	{
		string InputStr{};
		int SizeOfStr = 0;
		stack<char> Brackes{};

		getline(cin, InputStr);
		if (InputStr.size() == 1 and InputStr[0] == '.')
		{
			return 0;
		}
		for (char const elem : InputStr)
		{
			if (elem == '.')
			{
				if (Brackes.empty())
				{
					cout << "yes\n";
				}
				else
				{
					cout << "no\n";
				}
				break;
			}
			SizeOfStr++;

			if (elem == '(' or elem == '[')
			{
				Brackes.push(elem);
			}

			if (elem == ')' or elem == ']')
			{
				if (Brackes.empty() or (Brackes.top() == '[' and elem != ']') or (Brackes.top() == '(' and elem != ')'))
				{
					cout << "no\n";
					break;
				}
				Brackes.pop();
			}
		}
	}

	return 0;
}