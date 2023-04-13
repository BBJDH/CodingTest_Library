/*
 * 11404 - 플로이드
 *
 * 플로이드의 기본 점화식
 * MinDistance[Start][Dest] = min(MinDistance[Start][Dest], MinDistance[Start][Mid] + MinDistance[Mid][Dest]);
 * 를 사용한다.
 *
 * 이를 위해 이차원 배열 MinDistance[Start][Dest]를 구성한다.
 * 입력 받는 Edges의 Start Dest 에 따라 Distance를 입력해준다.
 *
 * 이때 입력받지 못한 MinDistance의 요소들을 INF로 입력한다
 * 모든 City와의 min 연산을 할 것이기 때문에 INF를 미리 넣어주어야 한다.
 * 또한 Start와 Dest가 같은 경우는 비용이 0이므로 이것도 미리 같이 초기화한다.
 *
 * 이후
 * MinDistance[Start][Dest] = min(MinDistance[Start][Dest], MinDistance[Start][Mid] + MinDistance[Mid][Dest]);
 * 점화식 계산을 위한 Mid Start Dest 순의 3중 포문을 돌아 최소거리 갱신을 시행한다
 * (시간 복잡도 O(N^3))
 *
 * 지정된 Mid를 잡아 다른 Start에서부터 Dest까지의 비용을 Min 연산을 해나가는 것이 기본 골자이다.
 *
 * 문제에서 요구하는
 * Start Dest로 가는 Edges가 여러개 일 수 있다는점을 유의하자
 * 이를 위해 처음 MinDistance에 Edge를 입력할 때도 min연산을 해야한다.
 *
 * 또한 INF는 0으로 출력하도록 해야함을 주의한다.
 *
 */


#include <iostream>
#include <vector>
#define INF 10000000

using namespace std;


int MinDistance[101][101]{};
int NumOfCity = 0;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int NumOfEdges = 0;
	cin >> NumOfCity >> NumOfEdges;

	for (int i = 1; i <= NumOfCity; i++)
	{
		fill_n(MinDistance[i], NumOfCity + 1, INF);
		MinDistance[i][i] = 0;
	}
	//Edges 입력
	while (NumOfEdges--)
	{
		int Start = 0, Dest = 0, Distance = 0;
		cin >> Start >> Dest >> Distance;
		MinDistance[Start][Dest] = min(MinDistance[Start][Dest], Distance);
	}

	//플로이드-워셜 시작
	for (int Mid = 1; Mid <= NumOfCity; Mid++)
	{
		for (int Start = 1; Start <= NumOfCity; Start++)
		{
			for (int Dest = 1; Dest <= NumOfCity; Dest++)
			{
				MinDistance[Start][Dest] = min(MinDistance[Start][Dest], MinDistance[Start][Mid] + MinDistance[Mid][Dest]);
			}
		}
	}

	//출력
	for (int Start = 1; Start <= NumOfCity; Start++)
	{
		for (int Dest = 1; Dest <= NumOfCity; Dest++)
		{
			if (MinDistance[Start][Dest] == INF)
			{
				cout << 0;
			}
			else
			{
				cout << MinDistance[Start][Dest];
			}
			cout << " ";
		}
		cout << "\n";
	}

	return 0;
}