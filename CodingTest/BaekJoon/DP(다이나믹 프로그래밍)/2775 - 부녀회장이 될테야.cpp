/*
 *2775 - �γ�ȸ���� ���׾�
 *
 *0���� �ʱⰪ i ���� �־��ְ�
 *DP�� ����� ��� ������ش�
 *�׽�Ʈ���̽��� �����Ƿ� DP�� ��� ����� �̸� ����صξ� �ð��� �����Ѵ�
 *
 */



#include <iostream>

using namespace std;

int DP[15][15]{};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int floor = 0; floor < 15; floor++)
	{
		int Sum = 0;
		for (int room = 0; room < 15; room++)
		{

			if (floor == 0)
				DP[0][room] = room;
			else
			{
				Sum += DP[floor - 1][room];
				DP[floor][room] = Sum;
			}
		}
	}


	int testCase = 0;
	cin >> testCase;

	while (testCase--)
	{
		int floorNum = 0;
		int roomNum = 0;

		cin >> floorNum >> roomNum;

		cout << DP[floorNum][roomNum] << "\n";
	}

	return 0;
}