/*
 *�ܿ� ���� �ʴ�
 *
 *
 *A�� - �� ġ���
 *
 *���� ū ���� ��� �״��� ū���� ��� ���� ġ���,
 *���� ���� ���� �켱���� ť�� �־� ó���ϸ� �ȴ�
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
			//���� ���� ���� �� �̾Ƴ�
			firstNum = Houses.top();
			Houses.pop();
			continue;
		}

		//�̿��� ��� ���� ġ��� ����
		int secondNum = Houses.top();
		Houses.pop();
		time += secondNum;
		Houses.push(firstNum- secondNum);
		firstNum = 0;
		//if (currentTarget < sideHouse)
		//{
		//	//ġ��ٰ� �̿������� �� �������ٸ�
		//	//ġ��� ������ �ٽ� �켱������ ť�� ����

		//	sideHouse -= currentTarget;
		//	Houses.push(sideHouse);
		//	time += currentTarget;
		//	currentTarget = 0;

		//}
		//else
		//{
		//	currentTarget -= sideHouse;
		//	time += sideHouse;
		//	Houses.push(currentTarget);
		//	currentTarget = 0;
		//}
	}
	time += firstNum;


	if (time > 1440)
		cout << -1;
	else
		cout << time;
	return 0;
}