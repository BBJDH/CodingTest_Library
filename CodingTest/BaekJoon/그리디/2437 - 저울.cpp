/*
 *2437 - 저울
 *
 *입력받은 추들을 오름차순으로 정렬한 후
 *작은 수 부터 누적합을 만들어나가며 여태까지 만들어온 누적합+1이
 *다음에 올라올 무게추보다 작다면 현재 누적합+1을 출력한다.
 *
 * 7
 * 3 1 6 2 7 30 1
 * 1 1 2 3 6 7 30
 *
 * 누적합
 * 1 2 4 7 13 20
 *            여기서 20 + 1 은 다음 추인 30보다 작으므로 21을 출력
 *
 */


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> Nums{};
vector<int> DP{};

void Solution()
{
	sort(Nums.begin(), Nums.end());


	int sum = 0;

	for (int i = 0; i < Nums.size(); i++)
	{
		if (sum + 1 < Nums[i])
		{
			cout << sum + 1;
			return;
		}
		sum += Nums[i];
	}
	cout << sum + 1;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int inputNum = 0;
		cin >> inputNum;

		Nums.push_back(inputNum);
	}

	Solution();


	return 0;
}