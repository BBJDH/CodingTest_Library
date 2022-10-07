

/*
구조체 정의 및 비교함수를 정의한 후 set에 삽입
*/

#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

struct StrTable
{
	string Text;
	int Size;
};
struct Compare
{
	bool operator()(StrTable const& Bigger, StrTable const& Smaller) const
	{
		if (Bigger.Size == Smaller.Size)
			return   Bigger.Text < Smaller.Text;
		return Bigger.Size < Smaller.Size;
	}
};

set<StrTable, Compare> Texts{};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int TestCase = 0;

	cin >> TestCase;

	while (TestCase--)
	{
		string InputStr{};

		cin >> InputStr;

		Texts.insert({ InputStr, static_cast<int>(InputStr.size()) });
	}
	for (auto const& Elem : Texts)
		cout << Elem.Text << "\n";

	return 0;
}