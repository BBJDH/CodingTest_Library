/*
 *4949 - �������� ����
 *
 *������ �����а� ��ȣ�� ī��Ʈ ���� �����ָ� �Ǵ°����� �����߾���.
 *
 *������ �̿��� ��ȣ�� �ְ� �ݴ� ��ȣ�� ���´ٸ� top�� ������ �� �����Ѵ�.
 *
 *���� top�� ��ġ���� �ʰų� .�� �����µ� ���ÿ� ��ȣ�� �����ִٸ� no�� ����Ѵ�.
 *
 *�Է��� ���δ����� ������ �ȴٸ� ������ ������ ����������.
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