/*
 *
 *2003 - 수들의 합 2
 *
 *누적합을 이용해 풀었다.
 *
 *입력받는 동시에 누적합을 배열로 저장한다.
 *
 *이후 이 배열을 모든 구간에 대하여 TargetNum이 되는 합 구간을 브루트포스로 탐색한다.
 *
 *일치한 ResultCount를 출력하고 종료한다.
 *
 *
 */


#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	vector<int> Sequence{};

	int SizeOfSequence = 0, TargetNum = 0;
	int Sum = 0, ResultCount = 0;
	cin >> SizeOfSequence >> TargetNum;
	Sequence.push_back(0);
	for (int i = 0; i < SizeOfSequence; i++)
	{
		int InputNum = 0;
		cin >> InputNum;
		Sum += InputNum;
		Sequence.push_back(Sum);
	}

	for (int i = 0; i < Sequence.size(); i++)
	{
		for (int j = i + 1; j < Sequence.size(); j++)
		{
			if ((Sequence[j] - Sequence[i]) == TargetNum)
			{
				ResultCount++;
			}
		}
	}

	cout << ResultCount;

	return 0;
}