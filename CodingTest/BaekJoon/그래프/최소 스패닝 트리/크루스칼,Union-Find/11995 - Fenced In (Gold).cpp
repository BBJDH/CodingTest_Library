/*
 *11995 - Fenced In (Gold)
 *
 *다른 방법도 있지만 크루스칼을 통해 풀었다
 *
 *입력 받은 울타리를 기준으로 수직 울타리를 수평의 원소 기준으로 쪼개어 Edge를 만들어 주었다
 *
 *이후 Parent를 만들어 크루스칼을 통해 최소 신장트리를 만든다
 *
 *만들면서 결합되는 Weight를 누적시켜 출력한다.
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
	long long Start;
	long long Dest;
	long long Weight;
};

bool operator>(Edge const& Left, Edge const& Right)
{
	return Left.Weight > Right.Weight;
}
bool operator< (Edge const& Left, Edge const& Right)
{
	return Left.Weight < Right.Weight;
}

vector<long long>Fence_UpLine{};
vector<long long>Fence_RightLine{};
vector<Edge> Edges{};
long long Parent[4004001]{};
long long MaxX = 0, MaxY = 0, N = 0, M = 0;

long long FindParent(long long const Child)
{
	if (Parent[Child] == Child)
		return Child;

	return Parent[Child] = FindParent(Parent[Child]);
}

void Solution()
{
	long long totalWeight = 0;

	for (auto const& elem : Edges)
	{
		long long const parentStart = FindParent(elem.Start);
		long long const parentEnd = FindParent(elem.Dest);
		if (parentStart != parentEnd)
		{
			Parent[parentEnd] = parentStart;
			totalWeight += elem.Weight;
		}
	}
	cout << totalWeight;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	cin >> MaxX >> MaxY >> N >> M;

	Fence_UpLine.push_back(MaxX);
	Fence_RightLine.push_back(MaxY);

	for (int i = 0; i < N; i++)
	{
		long long inputNum = 0;
		cin >> inputNum;
		Fence_UpLine.push_back(inputNum);
	}
	sort(Fence_UpLine.begin(), Fence_UpLine.end());
	for (int i = 0; i < M; i++)
	{
		long long inputNum = 0;
		cin >> inputNum;
		Fence_RightLine.push_back(inputNum);
	}
	sort(Fence_RightLine.begin(), Fence_RightLine.end());


	//번호가 낮은 지역에서 높은지역으로, 위로 뚫고 올라가는 비용 삽입
	for (int y = 0; y < M; y++)
	{
		long long startWeight = 0;

		for (int x = 0; x < Fence_UpLine.size(); x++)
		{
			long long crossUpWeight = Fence_UpLine[x] - startWeight;
			long long start = y * (N + 1) + x;
			long long dest = (y + 1) * (N + 1) + x;
			Edges.push_back({ start ,dest,crossUpWeight });
			startWeight = Fence_UpLine[x];
		}
	}

	//번호가 낮은 지역에서 높은지역으로, 오른쪽으로 뚫고 지나가는 비용 삽입

	for (int x = 0; x < N; x++)
	{
		long long startWeight = 0;
		for (int y = 0; y < Fence_RightLine.size(); y++)
		{
			long long crossRightWeight = Fence_RightLine[y] - startWeight;
			long long start = y * (N + 1) + x;
			long long dest = y * (N + 1) + x + 1;
			Edges.push_back({ start ,dest,crossRightWeight });
			startWeight = Fence_RightLine[y];
		}
	}
	sort(Edges.begin(), Edges.end());

	//Edge 입력 완료

	for (int i = 0; i < (N + 1) * (M + 1); i++)
	{
		Parent[i] = i;
	}
	//부모 배열 초기화
	Solution();
	return 0;
}