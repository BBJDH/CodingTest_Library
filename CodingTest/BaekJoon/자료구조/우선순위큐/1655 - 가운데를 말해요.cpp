/*
 *1655 - 가운데를 말해요
 *
 *수를 입력받으면서 정렬하여 가운데수를 출력하는 방식은 시간초과가 발생한다
 *
 *정해는 우선순위 큐 두개를 사용해서 작은 수의 집합과 큰수의 집합을 나누어 큐에 할당하고
 *양쪽의 균형을 맞추며 매 입력값을 넣어주면 된다.
 *
 *작은 수를 우선 출력하도록 문제가 요구하므로 작은그룹의 top을 출력토록 구성했다.
 *
 */

#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<>> Upper{};
priority_queue<int, vector<int>> Lower{};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int inputCount = 0;

	cin >> inputCount;

	for (int i = 0; i < inputCount; i++)
	{
		int inputNum = 0;
		cin >> inputNum;

		if (Upper.size() == 0)
		{
			Upper.push(inputNum);
			cout << Upper.top();
		}
		else
		{
			if (inputNum <= Upper.top())
				Lower.push(inputNum);
			else
				Upper.push(inputNum);

			if (abs(static_cast<int>(Lower.size() - Upper.size())) == 2 or Upper.size() > Lower.size())
			{
				if (Lower.size() > Upper.size())
				{
					Upper.push(Lower.top());
					Lower.pop();
				}
				else
				{
					Lower.push(Upper.top());
					Upper.pop();
				}
			}
			cout << Lower.top();
		}
		cout << "\n";
	}


	return 0;
}