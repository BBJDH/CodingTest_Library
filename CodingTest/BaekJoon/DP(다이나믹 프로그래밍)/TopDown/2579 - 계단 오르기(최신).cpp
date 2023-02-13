/*
 * 2579 - 계단 오르기
 *
 *백트래킹으로 모든 조합을 시행하고 최대값을 도출하려고 시도했으나,
 *시간초과로 실패했다
 *
 *따라서 DP를 이용해 시간을 단축하기로 결정했다
 *
 *BottomUp으로 푼다면
 *DP[1] 에서의 최대값 = 계단 하나 밟았을 때
 *DP[2] 에서의 최대값 = 계단 두개 밟았을 때
 *DP[3] 에서의 최대값 = max(DP[i-2],DP[i-1]) + Stair[i]
 *DP[4] 에서의 최대값 = max(DP[i-2],DP[i-1]) + Stair[i]
 *...
 *이런 식으로 풀어나가게 된다.
 *
 *하지만 오랜만에 TopDown으로 풀어보기로 했다.
 *
 *게다가 시작점 0으로부터의 호출이 아닌 N으로 부터 호출로 TopDown을 풀어본다.
 *
 *TopDown의 도착조건, 이미 계산된 값의 반환, 경우의 수 처리를 해야함을 기억하자
 *
 *계단의 -1 까지 접근하므로 점수가 0인 계단을 한개 넣어주고 시작한다.
 *(시작점에서 바로 앞 계단을 밟게 되는 경우)
 *
 *
 */

#include<iostream>
#include <vector>

using namespace std;

vector<int> Stairs{};
int DP[301]{};
int MaxScore = 0;
int N = 0;

//현재 누적점수, 시작 지점
int MakeDP(int Pos)
{
	//탈출조건
	if (Pos < 1)
	{
		return 0;
	}
	//이미 계산된값이 있다면 반환
	if (DP[Pos] != 0)
	{
		return DP[Pos];
	}

	//1칸 건너 뛰는 경우
	DP[Pos] = max(DP[Pos], MakeDP(Pos - 2) + Stairs[Pos]);
	//연속으로 밟는 경우
	DP[Pos] = max(DP[Pos], MakeDP(Pos - 3) + Stairs[Pos - 1] + Stairs[Pos]);

	return DP[Pos];
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	Stairs.push_back(0);

	for (int i = 0; i < N; i++)
	{
		int input = 0;
		cin >> input;
		Stairs.push_back(input);
	}
	MakeDP(N);
	cout << DP[N];
	return 0;
}

