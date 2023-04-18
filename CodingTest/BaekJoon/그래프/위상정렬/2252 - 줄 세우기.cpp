/*
 *
 *2252 - 줄 세우기
 *
 *위상정렬로 풀이 가능하다.
 *
 *입력받는 Edges와 함께 진입차수 InDegree를 기록해둔다.
 *
 *이후 진입차수가 0인 시작점들을 큐에 삽입한다.(스택을 이용해도 된다.)
 *
 *이후 뽑혀져 나오는 첫 노드에서 연결된 다음 노드들의 진입차수들을 -1 해준다
 *
 *-1 이후 새롭게 진입차수가 0이된 노드들을 큐에 삽입한다.
 *
 *위의 과정을 반복해 N개의 노드가 뽑혀저 나온다면 정렬이 성공한 것이고,
 *
 *그 전에 큐가 빈다면 순환이 발생한 것이다.
 *
 *큐 대신 스택을 사용한다면 예제와 같은 결과를 얻을 수 있다.
 *
 */

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<int> InDegree{};
vector<vector<int>> Edges{};
int Size = 0;

void Solution()
{
	//stack<int> ZeroInDegree{};	//스택 사용
	queue<int> ZeroInDegree{};
	for (int i = 1; i < InDegree.size(); i++)
	{
		if (InDegree[i] == 0)
		{
			ZeroInDegree.push(i);
		}
	}

	//정렬이 완전히 수행되려면 정확히 N개의 노드가 빠져나와야 함
	for (int i = 0; i < Size; i++)
	{

		if (ZeroInDegree.empty())
		{
			cout << "순환발생\n";
			break;
		}
		//출력
		//int const NumToPrint = ZeroInDegree.top();	//스택 사용
		int const NumToPrint = ZeroInDegree.front();
		ZeroInDegree.pop();
		cout << NumToPrint << " ";
		for (int const elem : Edges[NumToPrint])
		{
			InDegree[elem]--;
			if (InDegree[elem] == 0)
			{
				ZeroInDegree.push(elem);
			}
		}
	}
}


int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int CountOfEdges = 0;
	cin >> Size >> CountOfEdges;
	Edges.resize(Size + 1);
	InDegree.resize(Size + 1);
	while (CountOfEdges--)
	{
		int Start = 0, Dest = 0;

		cin >> Start >> Dest;
		Edges[Start].push_back(Dest);
		InDegree[Dest]++;
	}

	Solution();


	return 0;
}