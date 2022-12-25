/*
 *12789 - 도키도키 간식드리미
 *
 *입력 받은 번호표를 스택 Line에 삽입
 *
 *이후 스택 Dest에 삽입 가능하다면 삽입 (0부터 시작해 +1과 같다면)
 *
 *마찬가지로 Hall에서 Dest에 삽입 가능하다면 삽입
 *
 *더 이상 삽입이 불가능하다면 Line에서 Hall에 삽입
 *
 *현재 hall의 top보다 line의 top이 더 크다면 실패!
 *
 *dest의 top이 1에 무사히 도달한다면 성공으로 처리한다.
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