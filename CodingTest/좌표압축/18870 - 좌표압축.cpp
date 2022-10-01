
/*
���� ���� ��  unique�� ���� �ߺ����� ���� ���ķ� �ٲٰ�,
lowerbound�� ���� �ش� ���� �ε����� ��ȯ

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
	//unique�� ���ӵ� ���� �����Ⱚ���� ����� �ڷ� ����, ���� ������ �ʿ��ϴ�
	auto const end = unique(InputNum_ToSort.begin(), InputNum_ToSort.end());

	for (auto const& Elem : InputNums)
		cout << lower_bound(InputNum_ToSort.begin(), end, Elem) - InputNum_ToSort.begin() << " ";


	return 0;
}
