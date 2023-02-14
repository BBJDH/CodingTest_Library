/*
 *
 *10773 - ����
 *
 *�� ���� ������ �̿��� Ǯ����.
 *
 *�ϳ��� �Է¹޾Ƽ� �̾� ���� ��������,
 *
 *���� �ϳ��� 0�� �����ϴ� ���ν������� ����Ѵ�
 *
 *�Է¹��� ���ÿ��� 0�̶�� 0���� ����
 *
 *�ڿ����� ���´ٸ� ���ν����� ����������� ���� �ջ��Ѵ�.
 *
 *���ν����� ������� �ʴٸ� pop�� �����Ѵ�.
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