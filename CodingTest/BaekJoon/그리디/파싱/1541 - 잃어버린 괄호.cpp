/*
 * 1541 - �Ҿ���� ��ȣ
 *
 *�����غ��� �����ϴ� ������ �ִ��� ���� ���ָ� �ּҰ��� �ȴ�.
 *
 *����ϸ� �ִ��� ���� �� ������?
 *
 * ���̳ʽ� ���� ���Ŀ� ������ ������ ��� ���ָ� �ȴ�.
 *
 * ���̳ʽ� ���Ŀ� ��� +�� �����ص�, -���� -�� �����ص� ���ι����� �Ǳ⶧����
 *
 *���̳ʽ� ���� +�� -�� � ��ȣ�� �͵� ��� �������� ���� �� �ִ�.
 *
 *���� -�� �������� substr�Ͽ� �� ���� ��ȯ�Ѵ�.
 *
 *���� - �� ���°��� ��ü ���� ���� ��ȯ�ϸ� �ȴ�.
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
