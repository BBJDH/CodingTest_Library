/*
 *1021 - 회전하는 큐
 *
 *
 *그리디를 이용해 풀었다
 *
 * 1 2 3 4 5 6 7 8 9 10		- 0번
 * 2 3 4 5 6 7 8 9 10 1    - 1번
 * 3 4 5 6 7 8 9 10 1    - 1번
 * 1 3 4 5 6 7 8 9 10    - 2번
 * 10 1 3 4 5 6 7 8 9    - 3번
 * 9 10 1 3 4 5 6 7 8    - 4번
 * 10 1 3 4 5 6 7 8    - 4번
 * ...
 * 5 6 7 8 10 1 3 4    - 8번
 *
 *
 *정리해보면 입력된 수대로 + -해주어 결과를 계산해나가면 된다.
 *
 * 1 2 3 4 5 6 7 8 9 10
 * 2번째 수 필요, 앞으로 2-1번 혹은 뒤로 (10-2)+1번
 * 앞으로 1번을 선택 2, 9, 5 에서 2는 뽑혀나가고 나머지 수들은 1번+1 만큼 감소 즉 7,5
 * 3 4 5 6 7 8 9 10 1	- 1번
 * 7번째 수 필요, 앞으로 7-1번 혹은 뒤로 (9-7)+1번
 * 뒤로 3번을 선택 7, 3에서 7번재 수가 뽑혀나가고 다음 뽑아야할 3번째 수에 3-1만큼 증가
 * 10 1 3 4 5 6 7 8	- 4번(7번째 수 필요, 앞으로 7-1번 혹은 뒤로 (9-7)+1번)(7, 3)
 *
 * 하나씩 PopNum을 기준으로 Result를 계산하고 남은 PopNum들을 움직인만큼 조작한다.
 * PopNum들을 조작시 음수가 되거나 큐의 사이즈를 넘어가는 경우에 대한 예외처리를 해줘야 한다.
 *
 *요구사항대로 덱을 구성해 풀이도 가능하다.
 *
 */

#include <iostream>
#include <vector>


using namespace std;

void MoveNums(vector<int>& PopNum, int const Index, int const MoveAmount, int& Size)
{
	if (MoveAmount >= 0)
	{

		for (int i = Index; i < PopNum.size(); i++)
		{
			PopNum[i] = (PopNum[i] + MoveAmount) % Size;
		}
	}
	else
	{
		for (int i = Index; i < PopNum.size(); i++)
		{
			PopNum[i] = (PopNum[i] + MoveAmount);
			if (PopNum[i] < 0)
			{
				PopNum[i] = Size + PopNum[i];
			}
		}
	}
	Size--;
};

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int SizeOfQueue = 0, CountOfPop = 0;
	int Result = 0;
	vector<int> PopNum{};
	cin >> SizeOfQueue >> CountOfPop;
	for (int i = 0; i < CountOfPop; i++)
	{
		int InputNum = 0;
		cin >> InputNum;
		PopNum.push_back(InputNum);
	}

	for (int i = 0; i < PopNum.size(); i++)
	{
		if (PopNum[i] - 1 < (SizeOfQueue - PopNum[i]) + 1)
		{
			//왼쪽 이동이 더 작음
			Result += PopNum[i] - 1;
			MoveNums(PopNum, i + 1, -PopNum[i], SizeOfQueue);
		}
		else
		{
			//오른쪽 이동이 더 작음
			Result += SizeOfQueue - PopNum[i] + 1;
			MoveNums(PopNum, i + 1, SizeOfQueue - PopNum[i], SizeOfQueue);
		}
	}
	cout << Result;
	return 0;
}