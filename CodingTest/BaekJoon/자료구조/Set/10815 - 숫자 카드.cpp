/*
 *10815 - 숫자 카드
 *
 *수의 범위가 크므로 배열로 매핑하여 체크할수는 없다.
 *
 *때문에 균형이진트리를 유지하는 set를 이용하여 수를 검색하게 한다.
 *
 */

#include<iostream>
#include <set>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	set<int> CheckNums{};
	int N = 0, M = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int CheckNum = 0;
		cin >> CheckNum;
		CheckNums.insert(CheckNum);
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int InputNum = 0;
		cin >> InputNum;
		if (CheckNums.find(InputNum) != CheckNums.end())
		{
			cout << "1 ";
			continue;
		}
		cout << "0 ";
	}

	return 0;
}