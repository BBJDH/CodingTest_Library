/*
 *25305 - 커트라인
 *
 *std::sort를 통해 내림차순으로 정렬 후 입력받은 인덱스로 접근하여 출력한다.
 *
 *
 *
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, k = 0;
	vector<int> Nums{};
	cin >> N >> k;

	for (int i = 0; i < N; i++)
	{
		int elem = 0;
		cin >> elem;
		Nums.push_back(elem);
	}

	sort(Nums.begin(), Nums.end(), greater<>());

	cout << Nums[k - 1];

	return 0;
}