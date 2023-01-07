/*
 *
 *11058 - 크리보드
 *
 *네가지 경우의 수를 간단하게 표현하면,
 *현재수 +1 (비용 1)
 *현재수 복사 (복사본 업데이트) (비용 2)
 *복산 된 수 붙여넣기 +복사본만큼 수 증가 (비용 1)
 *
 *
 *
 *버튼을 6번 누르는 경우 까지는 DP[N] = N이 성립한다. (7부터 복붙을 해야 9로 커짐)
 *
 *그리고 복사 붙여넣는 경우를 가장 아랫수까지 잘라서 시행하는 경우를 비교해 최대 수를 DP로 저장한다.
 *(복사 붙여넣기의 최소비용은 2+1로 3이다, 붙여넣기 한번 기준)
 *
 *크기가 int를 넘어가므로 long long으로 DP를 만든다.
 *
 */


#include<iostream>

using namespace std;

int Result = 0;

long long DP[101]{};


//topdown 반복문
void MakeDP()
{
	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 3;
	DP[4] = 4;
	DP[5] = 5;
	DP[6] = 6;

	for (int i = 7; i < 101; i++)
	{
		for (int copy = 1; copy + 2 < i; copy++)
		{
			DP[i] = max(DP[i], DP[i - 2 - copy] * (copy + 1));
		}
	}
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;

	cin >> N;
	MakeDP();
	cout << DP[N];
	return 0;
}