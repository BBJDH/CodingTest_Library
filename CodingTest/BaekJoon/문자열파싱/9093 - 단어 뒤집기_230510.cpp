/*
 *9093 - �ܾ� ������_230510
 *
 *�ܾ� �ϳ��� ������ ����ϴ� ���� �����ϴ�.
 *
 *������ �������� �Է¹޾� ���� ������ �ܾ ������ ����ؾ� �ϴ� ���̴�.
 *
 *���� ������ ������ ����ϴ� �Ͱ�,
 *�ܾ� ������ �ڸ��°� �� ���� ������ ó���Ѵ�.
 *
 *���� getline�� ���� ������ string�� �Է¹ް�,
 *�̰��� stream���� ������ ' '������ ���� string�� �ٽ� �����Ѵ�.
 *
 *�̷��Ե� string�� �ϳ��� Word�μ� �Ųٷ� ������ֱ⸸ �ϸ� �ȴ�.
 *
 *���� ������ TestCase �� ��ŭ �ݺ��Ѵ�.
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