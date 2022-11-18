/*
 * 2342 - Dance Dance Revolution
 *
 *시작점인 00 상태에서 모든 DDR 스텝을 진행하고 난 모든 경우의 수를 생각해보자
 *재귀 호출을 통해 모든 경우의 수를 미리 열어볼 수 있다
 *다음과 같이 모든 경우의 수가 존재한다
 *
 *입력  1	2	2		4		3
 *								34
 *				22(X)	42	---	13
 *				12	---	14	---	34
 *			12					13
 *			20  20		40
 *				22(X)	24
 *		10
 *00	01				41
 *				21		24
 *			21	22(X)
 *			02	22(X)
 *				02		42
 *						04
 *
 *이제 DP를 만들어보자
 * DP[DDR 진행번호][왼발위치][오른발위치]
 * 여기서 유의할 점은 DP는 현재까지 지나온 비용을 적는것이 아니라,
 * 앞으로 필요햔 비용을 기록하는 것이다
 * 예를 들어 DP[4번째 스텝][왼발4][오른발2] 는 마지막 3을 밟기위해 왼발 3 오른발 4, 왼발1 오른발3  두가지 경우의 수가 존재한다
 * 이 둘중에 최소인 비용(사실 이경우는 둘다 3으로 같다)으로 갱신한다. 이외의 다른 경우의 수는 없으므로 다시 계산할 필요가 없다.
 * 이렇게 Top Down으로 맨 끝에서부터 DP를 쌓아오고나서
 * DP[0][0][0]을 열어보면 00에서 맨 마지막 발판을 밟는 최소비용이 들어있다
 *
 *
 * 같은 지점은 밟으면 안된다. 이 경우는 무한대로 min 연산에서 제외되도록 만든다(00 제외)
 * 재귀함수의 종료시점을 명시해야한다
 * DP != 0 즉 값이 이미 계산되었다면 해당 분기는 더이상 진행할 필요가 없다(메모이제이션)
 *
 *
 */

#include <iostream>
#include <vector>
#define INF 500000
using namespace std;

vector<int> DDR{};

int DP[100001][5][5]{};

int Cost[5][5]{};


void CallDP(int const CurrentStep, int const Left, int const Right)
{
	if (CurrentStep + 1 == DDR.size()) return;
	if (Left == Right and Left != 0)
	{
		DP[CurrentStep][Left][Right] = INF;
		return;
	}
	if (DP[CurrentStep][Left][Right] != 0) return;

	int NextStep = DDR[CurrentStep + 1];
	//경우의 수 분기
	CallDP(CurrentStep + 1, NextStep, Right);
	CallDP(CurrentStep + 1, Left, NextStep);

	//앞선 분기값을 min으로 갱신
	DP[CurrentStep][Left][Right] = min
	(
		DP[CurrentStep + 1][NextStep][Right] + Cost[Left][NextStep],
		DP[CurrentStep + 1][Left][NextStep] + Cost[Right][NextStep]
	);

}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int inputNum = -1;
	DDR.emplace_back(0);
	while (true)
	{
		cin >> inputNum;
		if (inputNum == 0) break;
		DDR.emplace_back(inputNum);
	}
	for (int i = 1; i < 5; i++)
	{
		Cost[0][i] = 2;
		Cost[i][i] = 1;
	}

	//1(2,4), 2(1,3), 3(2,4) 4(1,3)
	Cost[1][2] = Cost[1][4] = Cost[2][1] = Cost[2][3] = Cost[3][2] = Cost[3][4] = Cost[4][1] = Cost[4][3] = 3;

	//(1,3), (2,4) (3,1) (4,2)
	Cost[1][3] = Cost[2][4] = Cost[3][1] = Cost[4][2] = 4;
	CallDP(0, 0, 0);
	cout << DP[0][0][0];
	return 0;
}