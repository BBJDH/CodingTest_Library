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
	int currentTarget = 0;
	int time = 0;
	while (!Houses.empty())
	{
		if (currentTarget == 0)
		{
			//가장 눈이 많은 집 뽑아냄
			currentTarget = Houses.top();
			Houses.pop();
			continue;
		}

		//이웃집 골라서 같이 치우기 시작
		int sideHouse = Houses.top();
		Houses.pop();
		if (currentTarget < sideHouse)
		{
			//치우다가 이웃집눈이 더 많아진다면
			//치우고 남은것 다시 우선순우위 큐에 삽입

			sideHouse -= currentTarget;
			Houses.push(sideHouse);
			time += currentTarget;
			currentTarget = 0;

		}
		else
		{
			currentTarget -= sideHouse;
			time += sideHouse;
			Houses.push(currentTarget);
			currentTarget = 0;
		}
	}
	time += currentTarget;


	if (time > 1440)
		cout << -1;
	else
		cout << time;
	return 0;
}