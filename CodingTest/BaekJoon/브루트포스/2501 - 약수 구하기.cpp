/*
 *
 *2501 - 약수 구하기
 *
 *입력받을 수 N이 만 이하이므로 브루트포스로 풀이 가능하다
 *
 *1부터 시작하여 N까지 나누어지는 수를 모두 구해 배열에 넣는다
 *
 *이후 입력반은 K번째 수를 출력, 만약 K가 전체 약수 배열보다 크다면 0을 출력한다.
 *
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N = 0, K = 0;
	vector<int> Factors{};

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		if (N % i == 0)
		{
			Factors.push_back(i);
		}
	}

	if (K > Factors.size())
	{
		cout << 0;
	}
	else
	{
		cout << Factors[K - 1];
	}



	return 0;
}