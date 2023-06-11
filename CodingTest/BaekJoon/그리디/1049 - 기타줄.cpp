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
 *
 *
 * 23.06.11  개선 내용
 *
 *각 입력 받은 세트 가격과 한 가격은 브랜드와 상관없이
 *가장 낮은 세트가격과 가장 낮은 한개 가격만이 필요하다.
 *
 *따라서  min을 통해 위의 두값만을 취하여
 *
 *남은 구매 갯수가 6개 이상이라면 세트 가격과 한개가격 * 6 을  비교하여 구매하고
 *남은 구매 갯수가 6개 미만이라면 세트 가격과 한개가격 * 구매갯수 를 비교하여 반복문을 통해 계산한다. 
 *
 */




#include <iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int NumOfPurchases = 0;
	int BrandNum = 0;
	cin >> NumOfPurchases >> BrandNum;

	int PriceOfSet = 1001;
	int PriceOfOne = 1001;

	while (BrandNum--)
	{
		int InputSet = 0, InputOne = 0;
		cin >> InputSet >> InputOne;

		PriceOfSet = min(PriceOfSet, InputSet);
		PriceOfOne = min(PriceOfOne, InputOne);
	}

	int Result = 0;

	while ((NumOfPurchases < 6 and PriceOfSet < PriceOfOne * NumOfPurchases) or (NumOfPurchases >= 6 and PriceOfSet < PriceOfOne * 6))
	{
		Result += PriceOfSet;
		NumOfPurchases -= 6;
	}
	if (NumOfPurchases > 0)
	{
		Result += NumOfPurchases * PriceOfOne;
	}

	cout << Result;

	return 0;
}





/*
 *
 * 개선 전 코드
 */
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int N = 0, M = 0;
//vector<int> PricePackage{};
//vector<int> PriceAnItem{};
//
//int main()
//{
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
//	int Result = 0;
//
//	cin >> N >> M;
//	for (int i = 0; i < M; i++)
//	{
//		int package = 0, anItem = 0;
//		cin >> package >> anItem;
//		PricePackage.push_back(package);
//		PriceAnItem.push_back(anItem);
//	}
//	sort(PricePackage.begin(), PricePackage.end());
//	sort(PriceAnItem.begin(), PriceAnItem.end());
//
//	Result += (N / 6) * PricePackage[0];
//
//	Result += min((N % 6) * PriceAnItem[0], PricePackage[0]);
//
//	if (N * PriceAnItem[0] > Result)
//		cout << Result;
//	else
//		cout << N * PriceAnItem[0];
//
//
//	return 0;
//}