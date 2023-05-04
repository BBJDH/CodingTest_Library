/*
 *10819 - 차이를 최대로
 *
 *수의 제한이 8까지 이므로 8!만큼 모든 경우의 수를 시도해볼 수 있다.
 *
 *하지만 중복되는 수는 허용되지 않으므로 방문처리에 사용할 bool 배열을 사용한다.
 *
 *모든 수에 대해서 배열에 삽입 시도를 하고 방문처리를 통해 기존에 삽입된 수는 넣지 않는다.
 *
 *계속 삽입하여 배열크기가 지정 크기만큼 도달한다면 |A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]| 계산한다.
 *
 *현재 계산된값을 기존의 최대값이랑 비교하여 업데이트 후 함수는 종료된다.
 *
 *위의 절차를 백트래킹으로 진행, 모든 경우의 수를 시도한다.
 *
 */


#include <iostream>
#include <vector>

using namespace std;

int Size = 0;
int MaxDiff = 0;
bool visit[8]{};


void BackTracking(vector<int> const& InputNums, int Start, vector<int>& CurrentSequence)
{
	if (CurrentSequence.size() == Size)
	{
		int CurrentResult = 0;
		for (int i = 1; i < CurrentSequence.size(); i++)
		{
			CurrentResult += abs(CurrentSequence[i] - CurrentSequence[i - 1]);
		}
		MaxDiff = max(MaxDiff, CurrentResult);

		return;
	}

	for (int i = 0; i < Size; i++)
	{
		if (visit[i] == false)
		{
			CurrentSequence.push_back(InputNums[i]);
			visit[i] = true;
			BackTracking(InputNums, Start, CurrentSequence);
			CurrentSequence.pop_back();
			visit[i] = false;
		}
	}
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	vector<int>InputNums{};

	cin >> Size;

	for (int i = 0; i < Size; i++)
	{
		int InputNum = 0;
		cin >> InputNum;
		InputNums.push_back(InputNum);
	}
	vector<int>Temp{};
	BackTracking(InputNums, 0, Temp);

	cout << MaxDiff;
	return 0;
}