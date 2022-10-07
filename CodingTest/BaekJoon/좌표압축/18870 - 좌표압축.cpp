
/*
수를 정렬 후  unique를 통해 중복없는 수의 정렬로 바꾸고,
lowerbound를 통해 해당 수의 인덱스를 반환

*/
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> InputNums{};
vector<int> InputNum_ToSort{};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int NumSize = 0;

	cin >> NumSize;
	while (NumSize--)
	{
		int InputNum = 0;
		cin >> InputNum;
		InputNums.push_back(InputNum);
		InputNum_ToSort.push_back(InputNum);
	}
	sort(InputNum_ToSort.begin(), InputNum_ToSort.end());
	//unique는 연속된 수를 쓰레기값으로 만들어 뒤로 보냄, 따라서 정렬이 필요하다
	auto const end = unique(InputNum_ToSort.begin(), InputNum_ToSort.end());

	for (auto const& Elem : InputNums)
		cout << lower_bound(InputNum_ToSort.begin(), end, Elem) - InputNum_ToSort.begin() << " ";


	return 0;
}
