/*
 *6603 - 로또
 *
 *한달만에 백트래킹문제를 풀게됐다.
 *
 *평소라면 Limit에 도달했을때 Visit 처리된 것을 1부터 순서대로
 *
 *true만 출력해도 되지만,
 *
 *이번에는 백트래킹 함수에 동적 배열을 전달하여 추가 제거를 통해 출력하고 싶었다.
 *
 *이렇게 하면 뽑아진 동적배열 원소 6개에 대한 퀵소트를 해야 하므로 nlogn 즉 약 18정도의 비용이 들고
 *
 *Visit을 쓴다면 정렬은 필요없지만 50크기를 n으로 완전 탐색하는 비용이 든다.
 *
 *다만 동적배열의 추가/제거를 반복하며 소비되는 비용이 드므로 둘중 상황에 따라 편한것을 쓰게될 것 같다.
 *
 */



#include<iostream>
#include <vector>
#include <algorithm>
#define Limit 6

bool Visit[50]{};

using namespace std;

void BackTracking(vector<int> const& Lotto, vector<int> Print, int Index = 0)
{
	for (int i = Index; i < Lotto.size(); i++)
	{
		int newElem = Lotto[i];
		if (Visit[newElem] == false)
		{
			Visit[newElem] = true;
			Print.push_back(newElem);
			if (Print.size() == Limit)
			{
				sort(Print.begin(), Print.end());
				for (int const printElem : Print)
					cout << printElem << " ";
				cout << "\n";

			}
			BackTracking(Lotto, Print, i + 1);
			Visit[newElem] = false;
			Print.erase(Print.end() - 1);
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true)
	{
		int size = 0;
		cin >> size;
		if (size == 0)
			return 0;
		vector<int> inputNums{};
		for (int i = 0; i < size; i++)
		{
			int inputNum = 0;
			cin >> inputNum;
			inputNums.push_back(inputNum);
		}
		vector<int> Print{};
		BackTracking(inputNums, Print);
		cout << "\n";

	}

	return 0;
}