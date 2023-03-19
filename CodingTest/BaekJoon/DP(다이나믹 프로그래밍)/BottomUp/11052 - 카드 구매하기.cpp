/*
 *11052 - 카드 구매하기
 *
 *
 *처음은 가격/카드갯수 의 기준으로 정렬하여 풀어보았으나
 *
 *테스트 케이스는 모두 통과하고
 *
 *다음 테스트 케이스에서는 오답이 제출됨을 알게되었다.
 *
 * 12
 * 1 1 6 8 11 1 1 1 1 1 1 1
 * Ans: 25
 *
 * 정렬로 풀면 24가 출력되며 실제는
 * 6 8 11로 3개 4개 5개를 구매해야 한다.
 *
 * 때문에 다이나믹 프로그래밍을 통해 카드 장수 기준을 1로 시작해
 * 메모이제이션 하는 방법을 선택했다
 *
 * 배열을 DP[구매할 카드장 수] = 최대 가격
 *
 * 으로 정하여 먼저 순서대로 카드 묶음을 DP에 입력하고
 *
 * DP[1] = 입력 받은 값 (더 이상 다른 조합이 없다)
 * DP[2] = {DP[2], DP[1]+DP[1]} 중의 최대값
 * DP[3] = {DP[3], DP[2]+DP[1], DP[1]+DP[1]+DP[1]} 중의 최대값
 *
 *	...
 *
 *	의 방식으로 DP배열을 메모이제이션 한다.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//[NumOfCard]
int DP[1000]{};

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int TotalNum = 0;
	cin >> TotalNum;

	for (int i = 1; i <= TotalNum; i++)
	{
		cin >> DP[i];
	}

	for (int NumOfCards = 1; NumOfCards <= TotalNum; NumOfCards++)
	{
		for (int i = 1; i <= NumOfCards; i++)
		{
			DP[NumOfCards] = max(DP[NumOfCards], DP[NumOfCards - i] + DP[i]);
		}
	}

	cout << DP[TotalNum];

	return 0;
}