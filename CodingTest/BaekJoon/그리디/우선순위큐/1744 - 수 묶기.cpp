/*
 *1744 - 수 묶기
 *
 *우선순위 큐 두개를 이용해 그리디로 풀었다.
 *
 *음수가 두개 이상 존재한다면 서로 곱하여 양수를 만들 수 있다.
 *또는 음수가 1개만 남았을 때 0이 존재한다면 두 수를 곱하여 0을 만들수 있다.
 *음수끼리 곱하는 경우 가장 작은 음수끼리 곱해야 가장 큰 양수를 만들어 더할 수 있다.
 *그리고 최후에 0과 곱해지거나 홀로 더해질 음수는 가장 큰 음수이어야 가장 큰 합을 만들 수 있다.
 *
 *따라서 0과 음수를 포함하여 가장 작은 수부터 뽑혀나오는 우선순위 큐를 작성한다.
 *그리고 순차적으로 두수씩 묶어나가며 곱을 합하고 마지막 하나남은 요소를 더하면 된다.
 *
 *
 *양수의 경우 다른 예외가 존재한다
 *
 *위와 비슷한 원리로 우선순위큐로 작성하되, 가장 큰 수부터 빠져나오도록 작성한다.
 *
 *이 때, 2 1 1 로 뽑혀나오는 경우에 주의하자
 *1을 포함하여 수를 묶는다면 1만큼 최대값이 깎여나간다
 *
 *따라서 두 수를 묶을때 둘 중 하나라도 1이라면 두 수 모두 묶지않고 합한다.
 *
 *위의 절차를 모두 진행하며 누적된 Result를 출력한다.
 *
 */


#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	priority_queue<int, vector<int>, greater<>> MinusFirst{};
	priority_queue<int > PlusFirst{};
	int Size = 0;
	int Result = 0;
	cin >> Size;
	while (Size--)
	{
		int InputNum = 0;
		cin >> InputNum;
		if (InputNum <= 0)
		{
			MinusFirst.push(InputNum);
			continue;
		}
		PlusFirst.push(InputNum);
	}



	while (not MinusFirst.empty())
	{
		if (MinusFirst.size() > 1)
		{
			int const FirstNum = MinusFirst.top();
			MinusFirst.pop();
			int const SecondNum = MinusFirst.top();
			MinusFirst.pop();
			Result += FirstNum * SecondNum;
			continue;
		}

		Result += MinusFirst.top();
		MinusFirst.pop();
	}

	while (not PlusFirst.empty())
	{
		if (PlusFirst.size() > 1)
		{
			int const FirstNum = PlusFirst.top();
			PlusFirst.pop();
			int const SecondNum = PlusFirst.top();
			PlusFirst.pop();

			if (FirstNum == 1 or SecondNum == 1)
			{
				Result += FirstNum;
				Result += SecondNum;
				continue;
			}

			Result += FirstNum * SecondNum;
			continue;
		}

		Result += PlusFirst.top();
		PlusFirst.pop();
	}
	cout << Result;
	return 0;
}
