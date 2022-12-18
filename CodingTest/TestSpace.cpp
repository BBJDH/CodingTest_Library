/*
 *
 *
 *2169 - 로봇 조종하기
 *
 *탐사를 왼쪽에서 오른쪽으로면 진행하는 경우의 최대값과
 *오른쪽에서 왼쪽으로 진행하는 두 가지를 비교해 DP에 최대값만 한줄씩 업데이트 해 나간다.
 *
 *
 * 5 5
 * 10 25 7 8 13
 * 68 24 -78 63 32
 * 12 -69 100 -29 -25
 * -16 -22 -57 -33 99
 * 7 -76 -11 77 15
 *
 *첫 줄 
 * 10 25 7 8 13
 *
 *시작지점은 왼쪽 끝으로 정해져 있으므로 최대값의 업데이트는 무조건 오른쪽 방향으로 진행된다
 *
 *즉 맨 왼쪽에서 오른쪽으로의 누적합을 업데이트 한다
 *
 *즉
 *10 35 42 50 63  의 DP 첫 줄이 완성된다
 *
 *문제는 두번째 줄부터 이다
 *아랫지점에서는 어느 윗지점에서의 시작인지를 고려해봐야 한다
 *
 *하지만 잘생각해보면 결국은 윗 지점의 최대값 + 현재 지점의 값을 시작으로 왼쪽 혹은 오른쪽으로 최대값을 찾으면 된다
 *
 *즉 두번째줄은 왼쪽, 오른쪽으로의 누적합을 진행하고 이 둘중에 큰값을 DP에 업데이트 하기만 하면 된다.
 *
 *왼쪽을 진행하면
 *
 *DP 첫줄은    10 35 42 50 63
 *
 *두 번째 줄 값 68 24 -78 63 32
 *
 *DP 두번째 줄  78 102 24 113 145 (오른쪽 방향)
 *이 된다
 *
 *68입장에서 오른쪽으로의 탐사는 위에서 내려오는방법밖에 없다 따라서 68+10이다
 *
 *24입장에서는 위에서 내려오는것과 왼쪽에서 오는것이다 즉 DP의 왼쪽과 위쪽 둘중 큰값을 골라 현재값과 더한다
 *왼쪽은 78, 위쪽의 최대값은 35로 78이 채택되어 24와 더해진다 ->102
 *
 *이런직으로 오른쪽 끝까지 채워나간다
 *
 *
 *이번에는 왼쪽으로 탐사만을 고려한 최대값을 동일하게 구해나간다
 *
 *그 결과는,
 *DP 두번째 줄  172 104 80 158 95 (왼쪽 방향)
 *
 *이 둘중 최대값만을 DP에 기록한다
 *
 *-> DP 두번째 줄 172 104 80 158 145
 *
 *이런 방법으로 맨 마지막 까지 진행하고 도착지인 N행 M열의 수를 출력한다
 *
 */

#include<iostream>

using namespace std;

struct _int2
{
	int X;
	int Y;
};


int Map[1000][1000]{};
int DP[1000][1000]{};

_int2 Size{};


void MakeDP()
{
	//첫줄 누적합 만들기
	int sum = 0;
	for (int x = 0; x < Size.X; x++)
	{
		sum += Map[0][x];
		DP[0][x] = sum;
	}

	for (int y = 1; y < Size.Y; y++)
	{
		//오른쪽 탐사 업데이트
		for (int x = 0; x < Size.X; x++)
		{
			if (x == 0)
			{
				DP[y][x] = DP[y - 1][x] + Map[y][x];
				continue;
			}
			DP[y][x] = max( DP[y - 1][x], DP[y][x-1]) + Map[y][x];
		}

		//왼쪽 탐사 업데이트
		//같은 라인 왼쪽 DP가 이미 존재하기 때문에 임시 배열 생성

		int tempDP[1000]{};
		for (int x = Size.X-1; x >= 0; x--)
		{
			
			if (x == Size.X - 1)
			{
				tempDP[x] = DP[y - 1][x] + Map[y][x];
				DP[y][x] = max(DP[y][x], tempDP[x]);
				continue;
			}
			tempDP[x] = max(DP[y - 1][x], tempDP[x+1]) + Map[y][x];
			DP[y][x] = max(DP[y][x], tempDP[x]);
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> Size.Y >> Size.X;

	for(int y =0; y< Size.Y; y++)
	{
		for(int x=0; x< Size.X; x++)
		{
			cin >> Map[y][x];
		}
	}

	MakeDP();
	cout << DP[Size.Y - 1][Size.X - 1];
	return 0;
}