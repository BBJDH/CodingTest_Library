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
	�Է¹޾Ҵ� ���� �� �޼����� �����ؼ� �ش� �������Ͽ�
	�ݺ��� ������ ��(������ ����ִ��� üũ)
	������� �����鼭 ������ top�� ���� ������ �۰ų� ���ٸ� �������̾Ƴ�
	������ top�� Ȯ��, ������ top�� ���� ������ ũ�ٸ�
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
		RightBiggerNums�� top�� Ȯ��. ����ִٸ� -1 �ƴϸ� Top�� ��¹迭�� ����
		*/
	}

	while (!StackResult.empty())
	{
		cout << StackResult.top() << " ";
		StackResult.pop();
	}
	return 0;
}