#include<iostream>
#include<queue>
using namespace std;

/*
9095 - 1, 2, 3 더하기
모든 수를 123의 합으로 더하는 방법의 총 갯수를 찾는다

방법
최초 123을 큐에 넣음
큐가 빌때 까지
만약 큐에서 뺀 수가 만들어낼 수라면 Count++
수를 초과했다면 그냥 pop
수 미만이라면 다시 123을 각각 더해서 넣음
종료후
count 프린트
*/
queue<int> MakeNums{};
void Push(int const SrcNum)
{
	MakeNums.push(SrcNum + 1);
	MakeNums.push(SrcNum + 2);
	MakeNums.push(SrcNum + 3);
}
void Solution(int const TargetNum)
{
	int count = 0;

	Push(0);
	while (!MakeNums.empty())
	{
		int CurrentNum = MakeNums.front();
		MakeNums.pop();
		if (CurrentNum == TargetNum)
			count++;
		else if (CurrentNum < TargetNum)
			Push(CurrentNum);
	}
	cout << count << "\n";

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int TestCase = 0;
	cin >> TestCase;

	while (TestCase--)
	{
		int InputNum = 0;
		cin >> InputNum;
		Solution(InputNum);
	}

	return 0;
}