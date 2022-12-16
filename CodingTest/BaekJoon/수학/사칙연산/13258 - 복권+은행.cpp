/*
 *13258 - 복권+은행
 *
 *해당 문제는 골드 4로 배정되어 있으나
 *
 *단순 사칙연산으로 풀이 사능하다
 *
 *실제로 풀어보면 단순 총 잔고량은 티켓장수의 총량이 되고
 *내가 가진 잔고량 만큼 티켓을 보유하는데,
 *그 중 한 장만이 뽑혀서 지정된 이자만큼을 지급 받는다
 *
 *따라서 기대 보유 잔고량은
 *
 *주인공의 보유 잔고량 + (주인공의 보유 잔고량 * 지난일수 * 이자)/총 잔고량
 *
 *난이도 하향건의 (브론즈 3)
 *
 */


#include <iostream>

using namespace std;


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	double n = 0;
	double interest = 0;
	double day = 0;
	double total = 0;
	double first = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		double inputNum = 0;

		cin >> inputNum;

		if (i == 0)
			first = inputNum;

		total += inputNum;
	}
	cin >> interest >> day;

	printf("%.10f", first + (first * day * interest) / total);

	return 0;
}