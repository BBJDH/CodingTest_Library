/*
2098 - 외판원 순회

그냥 브루트포스로 풀면 시작점 제외 (N-1)! 비용이 나온다

문제의 요점은 중복을 어떻게 제거해 나가느냐는 것이다

다음과 같은 중복 상태를 보자

1 - 2 - 3 - 4 - 5
1 - 3 - 2 - 4 - 5
=>4-5 라인이 중복

위와 같은 상황이 16개의 정점이라면 무수히 많이 발생할 것이다,
이것을 어떻게 중복 제거할 수 있을까?

정답은 거꾸로 DP를 기록하는것이다, 즉 DP[현재노드][방문상태] = 앞으로 더 가야할 최소 비용

각 끝점에서 모두 방문한상태일때 더 필요한 비용은 반드시 정해져있다(각 점으로부터 시작점으로 돌아가는 비용)

이번엔 방문할 곳이 한곳만 남은경우, (예를들어 4) 남은 최소비용은 4->5 비용과 5정점에서 계산된 최소비용(시작점으로 돌아가는비용 5->1)이다 즉,
DP[4][5만남은 상태] = Map[4][5] + DP[5][모든방문상태];  의 수식이 성립된다.

자 이제 다시 위의 경우를 살펴보자
오름차순으로 백트래킹한다면 다음과 같은 연산을 따를것이다. (시작점은 1로 한다.)

1 - 2 - 3 - 4 - 5   (여기가 선행된다.)
1 - 3 - 2 - 4 - 5
=>4-5 라인이 중복

1 - 2 - 3 - 4 - 5
이 과정에서 이미 DP[5][모든방문] 과 DP[4][5만 방문하지 않은 상태]는 확정적으로 최소비용이 기록된다

때문에
1 - 3 - 2 - 4 - 5
여기서는
DP[4][5만 방문하지 않은 상태] 를 다시 구하지 않아도 된다.(DP[4][5만 방문하지 않은 상태] 안에는 DP[5][모든방문]이 합산되어있다)


이번에는 1 2 3의 입장에서 생각해보자,
여기서 4 - 5, 5 - 4 두 경로중 어디가 더 빠를지는 어떻게 판단할까?
(3에서 4로가는비용 + dp[4][5만 남은상태]) (3에서 5로가는 비용 + dp[5][4만 남은 상태]) 둘중 가장 작은 값을 넣어주면 된다
즉 방문하지 않은 수들에 해당하는 dp중, 최소값과 그곳으로 향하는 비용을 더해 업데이트하여 거꾸로 돌아가면 되는것이다.


정리해보면,
DP를 현재 정점, 현재 방문상태(정수 비트마스킹)로 기록하고 값은 앞으로 더 가야할 최소비용으로 기록한다
이것을 백트래킹으로 계산하고 이미 계산된값(즉, 초기값인 INF가 아닌경우)인경우 가져다 쓰면 중복을 제거 가능하다

그리고 마지막에 DP[시작점][시작점 방문상태]를 열어보면 최소값이 들어있다.

최초 시작점을 정하고 시작하므로 시작점을 방문처리 할 필요가 없다.


시작점을 정하는 이유는 문제의 전제를 참고하자, 반드시 모든 도시를 방문 가능하므로 어느 정점을 시작점으로 잡아도 상관없다.
링의 어디를 시작으로 잡아도 링의 둘레는 변하지 않는것과 같다.

*/

#include <iostream>


using namespace std;

#define INF 20000000

int Map[16][16]{};
int DP[16][1 << 16]{};

int Size = 0;
int VisitAllBit = 0;

void Solution(int Current, int VisitBit)
{
	//값이 존재하면 탈출
	if (DP[Current][VisitBit] != 0) return;
	if (VisitBit == VisitAllBit)
	{
		//끝지점 비용 입력
		DP[Current][VisitBit] = Map[Current][0];
		return;
	}

	//DP 계산 시작
	int MinWeight = INF;
	for (int i = 1; i < Size; i++)
	{
		//길이 없거나 이미 방문상태는 제외
		if (Map[Current][i] != INF and ((1 << i) & VisitBit) == 0)
		{
			//새로운 방문상태 newVisitBit
			int newVisitBit = VisitBit | (1 << i);
			//호출순서에 유의해야한다 우리는 끝까지 파고들어간 다음 맨 뒤에서부터 거꾸로 DP를 기록할 것이다.
			Solution(i, newVisitBit);
			// 다른 정점에서 더 작을 수 있으니 이를 고려하여 min으로 갱신
			MinWeight = min(MinWeight, Map[Current][i] + DP[i][newVisitBit]);
		}
	}
	//DP 갱신,
	DP[Current][VisitBit] = MinWeight;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> Size;
	VisitAllBit = (1 << Size) - 1;
	for (int y = 0; y < Size; y++)
	{
		for (int x = 0; x < Size; x++)
		{
			int InputNum = 0;
			cin >> InputNum;

			if (InputNum == 0)
				InputNum = INF;

			Map[y][x] = InputNum;
		}
	}
	Solution(0, 1);
	cout << DP[0][1];
	return 0;
}
