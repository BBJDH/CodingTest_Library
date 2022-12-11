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
	int currentTarget = 0;
	int time = 0;
	while (!Houses.empty())
	{
		if (currentTarget == 0)
		{
			//���� ���� ���� �� �̾Ƴ�
			currentTarget = Houses.top();
			Houses.pop();
			continue;
		}

		//�̿��� ��� ���� ġ��� ����
		int sideHouse = Houses.top();
		Houses.pop();
		if (currentTarget < sideHouse)
		{
			//ġ��ٰ� �̿������� �� �������ٸ�
			//ġ��� ������ �ٽ� �켱������ ť�� ����

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