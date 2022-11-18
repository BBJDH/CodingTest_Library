/*
 * 10942 - 펠린드롬?
 *
 * 브루트포스로 1~2000 * 1~2000 를 돌리면서 펠린드롬을 검사한 결과를 저장한다면 시간초과가 발생한다
 *
 *펠린드롬 규칙을 이용해 DP를 만들자
 *
 *예를들어  1, 2, 1, 3, 1, 2, 1 에서
 *
 *간격이 0 즉, 자기자신 숫자 1, 2, 3, ... 은 펠린드롬 수이다
 *간격이 1 이번에는 1, 2 의경우는 두 수가 같아야 펠린드롬이 성립한다
 *간격이 2 부터는 규칙이 생성된다 start+1 end-1이 펠린드롬이면서 start와 end가 같다면 펠린드롬이다
 *둘중 하나의 조건이라도 만족하지 못한다면 펠린드롬이 아니다
 *
 *메모이제이션이 될 수 있게 이 연산을 간격이 작은것부터 시작해 모두 DP에 저장한다
 *(큰것부터 한다면 작은DP를 참조할 수 없다)
 *
 *이후 들어오는 질문에 따라 출력만해주면 된다.
 *
 *
 */


#include <iostream>
#include <vector>

using namespace std;

vector<int> Sequence{};
int DP[2001][2001]{};

void MakeDP()
{
	for (int gap = 0; gap < Sequence.size(); gap++)
	{
		for (int start = 0; start + gap < Sequence.size(); start++)
		{
			int end = start + gap;
			if (gap == 0)
				DP[start][end] = 1;
			else if (gap == 1 and Sequence[start] == Sequence[end])
				DP[start][end] = 1;
			else
			{
				if (DP[start + 1][end - 1] == 1 and Sequence[start] == Sequence[end])
					DP[start][end] = 1;
				else
					DP[start][end] = 0;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int inputCount = 0;

	cin >> inputCount;

	while (inputCount--)
	{
		int inputNum = 0;
		cin >> inputNum;
		Sequence.emplace_back(inputNum);

	}
	MakeDP();

	cin >> inputCount;
	while (inputCount--)
	{
		int start = 0;
		int end = 0;
		cin >> start >> end;

		cout << DP[start - 1][end - 1] << "\n";
	}



	return 0;
}