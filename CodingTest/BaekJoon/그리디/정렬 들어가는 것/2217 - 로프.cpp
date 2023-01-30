/*
 *2217 - 로프
 *
 *규칙을 찾아보면,
 *15, 10, 9, 8, 3 인 로프들이 주어졌을 때,
 *가장 긴 로프순으로 갯수에 맞추어 최대 중량을 확인한다. 즉
 *15로 들수 있는 무게는 15
 *15, 10으로 들 수 있는 무게는 20
 *15, 10, 9로 들 수 있는 무게는 27
 *15, 10, 9, 8로 들 수 있는 무게는 32
 *15, 10, 9, 8, 3로 들 수 있는 무게는 15
 *
 *이 무게중 가장 높은 값은 32로,
 *4개의 로프로 들 수 있는 32이다
 *
 *즉 정리하면,
 *주어진 로프들을 내림차순으로 정렬하고
 *가장 긴 로프와 해당 갯수의 곱으로 max 계산을 하면 된다.
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> Rope{};
	int N = 0, MaxResult = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int inputRope = 0;
		cin >> inputRope;
		Rope.push_back(inputRope);
	}
	sort(Rope.begin(), Rope.end(), greater<>());

	for (int i = 0; i < N; i++)
	{
		MaxResult = max(MaxResult, Rope[i] * (i + 1));
	}
	cout << MaxResult;

	return 0;
}