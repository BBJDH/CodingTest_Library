/*
 *11403 - 경로 찾기
 *
 *입력 받은 인접 배열을 그대로 사용하여
 *
 *입력받은 정점 개수인 SIze 까지
 *0~ Size 를 시작점으로 각각 DFS를 시행한다.
 *
 *시행하면서 방문하게 되는 곳들을 Visit이중 배열로 처리한다.(Visit[시작점][도달 가능한 지점])
 *(혹은 1차원 배열로 하여 각 DFS종료 후 출력하고 시작시 초기화 해주어도 된다.)
 *
 *이미 방문한 지점을 다시 방문하게 되는 순환이 발생한다면 Visit[시작점][도달 가능한 지점]
 *에서 이미 방문처리가 되었으므로 더이상 탐색을 시행하지 않는다.
 *
 *마지막 Visit를 모두 출력해주고 프로그램을 종료한다.
 *
 *플로이드-워셜을 통해 푸는 방법도 가능하다
 *
 */

#include <iostream>

using namespace std;

int Edges[100][100]{};
int Visit[100][100]{};
int Size = 0;


void DFS(int const CurrentPos, int const& Start)
{
	for (int Dest = 0; Dest < Size; Dest++)
	{
		if (Edges[CurrentPos][Dest] == 1 and Visit[Start][Dest] == 0)
		{
			Visit[Start][Dest] = 1;
			DFS(Dest, Start);
		}
	}
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> Size;

	for (int Src = 0; Src < Size; Src++)
	{
		for (int Dest = 0; Dest < Size; Dest++)
		{
			cin >> Edges[Src][Dest];
		}
	}

	for (int i = 0; i < Size; i++)
	{
		DFS(i, i);
	}

	for (int Src = 0; Src < Size; Src++)
	{
		for (int Dest = 0; Dest < Size; Dest++)
		{
			cout << Visit[Src][Dest] << " ";
		}
		cout << "\n";
	}

	return 0;
}