/*
 *
 *10773 - 제로
 *
 *두 개의 스택을 이용해 풀었다.
 *
 *하나는 입력받아서 뽑아 쓰는 스택으로,
 *
 *남은 하나는 0을 보존하는 제로스택으로 사용한다
 *
 *입력받은 스택에서 0이라면 0으로 저장
 *
 *자연수가 나온다면 제로스택이 비어있을때만 수를 합산한다.
 *
 *제로스택이 비어있지 않다면 pop을 시행한다.
 *
 */

#include <iostream>
#include <stack>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	stack<int> InputStack{};
	stack<int>ZeroStack{};
	int N = 0, Result = 0;;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int inputNum = 0;
		cin >> inputNum;
		InputStack.push(inputNum);
	}
	while (!InputStack.empty())
	{
		int Current = InputStack.top();
		InputStack.pop();
		if (Current == 0)
		{
			ZeroStack.push(Current);
			continue;
		}
		if (!ZeroStack.empty())
		{
			ZeroStack.pop();
			continue;
		}
		Result += Current;
	}
	cout << Result;

	return 0;
}