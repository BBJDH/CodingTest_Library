/*
 * 1365 - 꼬인 전깃줄
 *
 *선을 하방으로 연결해도, 상방으로 연결해도
 *
 *입력 받은 수들은 증가하는 부분 수열을 가지게 된다.
 *
 *이 중 증가하지 않는 수들이 꼬인 전깃줄 이므로
 *
 *증가하는 부분수열의 최장길이를 구하고 이것을 N에서 뺀값이 답으로 출력된다.
 *
 *
 */



#include <iostream>
#include <vector>

using namespace std;


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;
	cin >> N;
	vector<int> Sequence{};

	for (int i = 0; i < N; i++)
	{
		int inputNum = 0;
		cin >> inputNum;

		if (i == 0)
		{
			Sequence.emplace_back(inputNum);
			continue;
		}

		if (inputNum > Sequence[Sequence.size() - 1])
		{
			Sequence.emplace_back(inputNum);
		}
		else
		{
			//문제에서 두개이상 같은 전봇대에 연결되어 있지 않으므로
			//else는 부분수열의 제일 큰수 보다 inputNum이 작은 경우 이다.

			auto iter = lower_bound(Sequence.begin(), Sequence.end(), inputNum);
			*iter = inputNum;
		}
	}

	int const result = N - static_cast<int>(Sequence.size());
	cout << result;

	return 0;
}