/*
 *2775 - 부녀회장이 될테야
 *
 *0층에 초기값 i 명을 넣어주고
 *DP로 명수를 모두 기록해준다
 *테스트케이스가 많으므로 DP로 모든 결과를 미리 기록해두어 시간을 단축한다
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