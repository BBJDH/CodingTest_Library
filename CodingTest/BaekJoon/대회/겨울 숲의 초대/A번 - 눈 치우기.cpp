/*
 *겨울 숲의 초대
 *
 *
 *A번 - 눈 치우기
 *
 *가장 큰 집을 골라서 그다음 큰집을 잡아 눈을 치우고,
 *남은 눈의 양을 우선순위 큐에 넣어 처리하면 된다
 *
 *
 */


#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> Houses{};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int houseNum = 0;

	cin >> houseNum;

	for (int i = 0; i < houseNum; i++)
	{
		int inputNum = 0;
		cin >> inputNum;
		Houses.push(inputNum);
	}
	int firstNum = 0;
	int time = 0;
	while (!Houses.empty())
	{
		if (firstNum == 0)
		{
			//가장 눈이 많은 집 뽑아냄
			firstNum = Houses.top();
			Houses.pop();
			continue;
		}

		//이웃집 골라서 같이 치우기 시작
		int secondNum = Houses.top();
		Houses.pop();
		time += secondNum;
		Houses.push(firstNum - secondNum);
		firstNum = 0;
	}
	time += firstNum;


	if (time > 1440)
		cout << -1;
	else
		cout << time;
	return 0;
}