/*
 *1874 - 스택 수열
 *
 *스택을 한개 생성해두고 여기에 오름차순으로만 삽입한다
 *
 *삽입하는 순서는 1부터 시작해 N까지 Push 한다
 *
 *스택에서 Pop을 한다면 그 수는 수열로 등록된다.
 *
 *즉 수열 4 3 6 8 7 5 2 1 를 만든다면
 *
 *1 2 3 4 순으로 스택에 넣고(+ 네번) 여기서 다시 4 3 을 뽑는다 (-두번)
 *
 *다음 넣어질 수는 5부터이므로 5 6을 넣고(+두번) 다시 여기서 6을 뽑는다 (-)
 *
 *이제 남은 7 과 팔을 push 하고 (+두번) 들어간 숫자는 1 2 5 7 8 로
 *
 *스택의 top인 8부터 쭉 뽑아서 수열로 등록한다.(- 5번)
 *
 *
 *
 *하지만 위의 방법으로 만들 수 없는 경우는 어떤 경우인가?
 *
 *N가지의 번호를 모두 Push 하고도 해당 수열번호를 찾을 수 없는 경우 이다
 *
 *즉 이런경우를 만나면 PushNum이 N을 초과하여 스택안에 삽입되려 한다.
 *
 *때문에 이 경우 NO를 출력하고 프로그램을 종료처리한다.
 *
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;
	vector<int> Sequence{};
	stack<int>Temp{};
	vector<char> Result{};
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int inputNum = 0;
		cin >> inputNum;
		Sequence.push_back(inputNum);
	}

	int index = 0;
	int pushNum = 1;
	while (index < N)
	{
		if (Temp.empty() or Temp.top() != Sequence[index])
		{
			if (pushNum > N)
			{
				cout << "NO";
				return 0;
			}

			Temp.push(pushNum);
			pushNum++;
			Result.push_back('+');
			continue;
		}

		Temp.pop();
		index++;
		Result.push_back('-');


	}

	for (char const elem : Result)
	{
		cout << elem << "\n";
	}


	return 0;
}