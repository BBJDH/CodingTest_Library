/*
 *1427 - 소트인사이드
 *
 *입력받은 수들을 10으로 나눈 나머지로 배열에 삽입한다
 *삽입한 배열을 내림차순으로 정렬 후 출력
 *마찬가지로 띄어쓰기는 생략한다.
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
	vector<int> Nums{};
	int inputNum = 0;
	cin >> inputNum;

	while (inputNum)
	{
		int Num = inputNum % 10;
		inputNum /= 10;
		Nums.push_back(Num);
	}
	sort(Nums.begin(), Nums.end(), greater<>());

	for (auto const& elem : Nums)
		cout << elem;
	return 0;
}