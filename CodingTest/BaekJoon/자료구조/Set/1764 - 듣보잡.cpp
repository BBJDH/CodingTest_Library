/*
 *1764 - 듣보잡
 *
 *입력받는 두 문자열 집합의 교집합을 사전순으로 정렬하여 출력하는 문제이다.
 *
 *먼저 입력받는 듣도 못한 사람들을 set으로 저장한다.
 *(value는 필요없고 Key로 조회할 예정이므로 map은 쓰지 않는다.)
 *
 *다음 입력받은 보지도 못한 사람들을 위에서 입력받은 set을통해 찾는다
 *찾아진 문자열을 vector에 저장하여 저장 후 출력한다.
 *
 */

#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	set<string> NeverHeard{};
	vector<string> Result{};
	int SizeOfNeverHeard = 0, SizeOfNeverMet = 0;
	cin >> SizeOfNeverHeard >> SizeOfNeverMet;

	for (int i = 0; i < SizeOfNeverHeard; i++)
	{
		string InputStr{};
		cin >> InputStr;
		NeverHeard.insert(InputStr);
	}
	for (int i = 0; i < SizeOfNeverMet; i++)
	{
		string InputStr{};
		cin >> InputStr;
		if (NeverHeard.find(InputStr) != NeverHeard.end())
		{
			Result.push_back(InputStr);
		}
	}
	sort(Result.begin(), Result.end());

	cout << Result.size() << "\n";
	for (string const& elem : Result)
	{
		cout << elem << "\n";
	}

	return 0;
}