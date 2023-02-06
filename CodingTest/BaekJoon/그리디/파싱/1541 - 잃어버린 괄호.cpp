/*
 * 1541 - 잃어버린 괄호
 *
 *정리해보면 등장하는 수들을 최대한 많이 빼주면 최소값이 된다.
 *
 *어떻게하면 최대한 빼줄 수 있을까?
 *
 * 마이너스 등장 이후에 나오는 수들을 모두 빼주면 된다.
 *
 * 마이너스 이후에 모두 +가 등장해도, -이후 -가 등장해도 따로묶으면 되기때문에
 *
 *마이너스 이후 +든 -는 어떤 기호가 와도 모두 뺄셈으로 계산될 수 있다.
 *
 *따라서 -를 기준으로 substr하여 그 차를 반환한다.
 *
 *물론 - 가 없는경우는 전체 수의 합을 반환하면 된다.
 *
 */

#include <iostream>
#include <string>

using namespace std;

int GetSum(string const& Str)
{
	int result = 0;
	string token{};

	for (char const elem : Str)
	{
		if (elem == '-' or elem == '+')
		{
			result += stoi(token);
			token = "";
			continue;
		}
		token += elem;
	}

	return result + stoi(token);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int Index = 0, Plus = 0, Minus = 0;
	string InputStr{};

	cin >> InputStr;

	if (string::npos == InputStr.find('-'))
	{
		cout << GetSum(InputStr);
		return 0;
	}
	unsigned long long index = InputStr.find('-');
	cout << GetSum(InputStr.substr(0, index)) - GetSum(InputStr.substr(index + 1, InputStr.size() - (index + 1)));

	return 0;
}
