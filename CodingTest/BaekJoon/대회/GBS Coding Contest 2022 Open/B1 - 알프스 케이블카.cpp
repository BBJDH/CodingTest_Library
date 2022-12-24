
/*
 *B1번 - 알프스 케이블카
 *
 *
 *각 정상당의 인접 정상까지의 거리가 최단거리이므로
 *
 *이 거리를 누적시켜 출력한다.
 *
 *
 */

#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;

	cin >> N;
	long long sum = 0;
	long long prev = 0;
	for (int i = 0; i < N; i++)
	{
		long long inputNum = 0;

		cin >> inputNum;

		if (i == 0)
		{
			prev = inputNum;
			continue;
		}

		sum += abs(inputNum - prev) * abs(inputNum - prev) + (prev + inputNum) * (prev + inputNum);
		prev = inputNum;
	}

	cout << sum;

	return 0;
}
