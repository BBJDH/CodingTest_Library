/*
 *10974 - 모든 순열
 *
 *백트래킹을 이용해 모든 경우의 수를 탐색한다.
 *
 *1부터 N까지 방문처리를 하며 차례대로 숫자를 넣고
 *재귀적으로 현재 문자열을 전달해가며 N크기의 수열을 만든다
 *수열 길이가 N에 도달한다면 출력처리 한다.
 */


#include <iostream>
#include <vector>

using namespace std;

bool Visit[9]{};

void BackTracking(int N, vector<int> Sequence)
{
	if (Sequence.size() == N)
	{
		for (int const elem : Sequence)
			cout << elem << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++)
	{
		if (Visit[i] == false)
		{
			Sequence.push_back(i);
			Visit[i] = true;
			BackTracking(N, Sequence);
			Visit[i] = false;
			Sequence.pop_back();
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;
	cin >> N;

	BackTracking(N, {});

	return 0;
}