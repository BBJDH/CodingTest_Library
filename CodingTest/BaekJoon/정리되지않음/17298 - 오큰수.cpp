#include<iostream>
#include<stack>

using namespace std;

stack<int>InputNums{};
stack<int>RightBiggerNums{};
stack<int>StackResult{};

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
		InputNums.push(InputNum);
	}
	/*
	입력받았던 수의 맨 뒷수부터 시작해서 해당 수에대하여
	반복문 안으로 들어감(스택이 비어있는지 체크)
	비어있지 않으면서 스택의 top이 현재 수보다 작거나 같다면 스택을뽑아냄
	스택의 top을 확인, 스택의 top이 현재 수보다 크다면
	*/
	while (!InputNums.empty())
	{
		int CurrentNum = InputNums.top();
		InputNums.pop();

		while (!RightBiggerNums.empty() and CurrentNum >= RightBiggerNums.top())
			RightBiggerNums.pop();
		if (RightBiggerNums.empty() == true)
			StackResult.push(-1);
		else
			StackResult.push(RightBiggerNums.top());

		RightBiggerNums.push(CurrentNum);
		/*
		RightBiggerNums의 top을 확인. 비어있다면 -1 아니면 Top을 출력배열에 삽입
		*/
	}

	while (!StackResult.empty())
	{
		cout << StackResult.top() << " ";
		StackResult.pop();
	}
	return 0;
}