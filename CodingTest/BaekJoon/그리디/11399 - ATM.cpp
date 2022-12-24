/*
 *11399 - ATM
 *
 *가장 작은 수부터 기다리는 것이 최단시간 이므로
 *
 *입력 받은 수들을 오름차순으로 정렬,
 *
 *이 누적값들의 총합을 출력한다.
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> inputNums{};

	int N = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int inputNum = 0;
		cin >> inputNum;

		inputNums.push_back(inputNum);
	}

	sort(inputNums.begin(), inputNums.end());

	int sum = 0;
	int result = 0;
	for (int i = 0; i < inputNums.size(); i++)
	{
		sum += inputNums[i];
		result += sum;
	}
	cout << result;
	return 0;
}