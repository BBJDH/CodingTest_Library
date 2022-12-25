/*
 *12789 - ��Ű��Ű ���ĵ帮��
 *
 *�Է� ���� ��ȣǥ�� ���� Line�� ����
 *
 *���� ���� Dest�� ���� �����ϴٸ� ���� (0���� ������ +1�� ���ٸ�)
 *
 *���������� Hall���� Dest�� ���� �����ϴٸ� ����
 *
 *�� �̻� ������ �Ұ����ϴٸ� Line���� Hall�� ����
 *
 *���� hall�� top���� line�� top�� �� ũ�ٸ� ����!
 *
 *dest�� top�� 1�� ������ �����Ѵٸ� �������� ó���Ѵ�.
 *
 *
 *
 */


#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> inputNums{};
	stack<int> stack_Dest{};
	stack<int> stack_Hall{};
	stack<int> stack_Line{};

	int N = 0;
	cin >> N;
	stack_Dest.push(0);
	stack_Hall.push(N + 1);
	for (int i = 0; i < N; i++)
	{
		int inputNum = 0;
		cin >> inputNum;
		inputNums.push_back(inputNum);
	}

	for (int i = static_cast<int>(inputNums.size()) - 1; i >= 0; i--)
	{
		stack_Line.push(inputNums[i]);
	}

	while (true)
	{
		if (stack_Dest.top() == N)
		{
			cout << "Nice";
			break;
		}

		if (not stack_Line.empty() and stack_Line.top() == stack_Dest.top() + 1)
		{
			stack_Dest.push(stack_Line.top());
			stack_Line.pop();
			continue;
		}

		if (stack_Hall.top() == stack_Dest.top() + 1)
		{
			stack_Dest.push(stack_Hall.top());
			stack_Hall.pop();
			continue;
		}

		if (not stack_Line.empty() and stack_Line.top() >= stack_Hall.top())
		{
			cout << "Sad";
			break;
		}

		stack_Hall.push(stack_Line.top());
		stack_Line.pop();
	}

	return 0;
}