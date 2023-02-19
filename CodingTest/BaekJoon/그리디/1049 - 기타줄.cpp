/*
 *1049 - 기타줄
 *
 *가장 낮은 패키지가격과 낱개 가격을 이용해
 *최적해를 구해나가는 문제이다
 *
 *테스트케이스에는 없지만 패키지를 구매하는경우보다
 *낱개로 구매하는게 더 싼 경우가 존잰한다.
 *
 *N을 6으로 나눈 몫만큼을 패키지 가격으로 구매하고
 *낱개로 사는경우와 패키치 한번의 가격을 비교해 최저가를 구한다
 *
 *마지막으로 낱개로만 구매하는경우가 더 싼 경우도 존재하므로
 *이를 비교해 출력한다.
 *
 *정렬하지않고 vector도 필요없이 min값만을 취하여 패키지와 낱개구매의
 *최소가격만 가지고 계산하는것이 현명하다.
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0, M = 0;
vector<int> PricePackage{};
vector<int> PriceAnItem{};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Result = 0;

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int package = 0, anItem = 0;
		cin >> package >> anItem;
		PricePackage.push_back(package);
		PriceAnItem.push_back(anItem);
	}
	sort(PricePackage.begin(), PricePackage.end());
	sort(PriceAnItem.begin(), PriceAnItem.end());

	Result += (N / 6) * PricePackage[0];

	Result += min((N % 6) * PriceAnItem[0], PricePackage[0]);

	if (N * PriceAnItem[0] > Result)
		cout << Result;
	else
		cout << N * PriceAnItem[0];


	return 0;
}