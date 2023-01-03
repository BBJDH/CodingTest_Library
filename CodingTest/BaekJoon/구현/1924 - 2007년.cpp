/*
 *
 * 1924 - 2007년
 *
 * 간단하게 구현으로 풀었다
 *
 * 각 요일을 문자열 배열로 매핑하고
 * 이를 사용하기위해 매 월마다의 시작일을 위의 문자열 매핑에 근거하여 기록해 둔다
 *
 * 요일은 7일주기로 반복되므로 %7을 이용하여 인덱스로 매핑된 문자열을 출력해준다.
 *
 * 계산할때 해당 월의 시작날짜가 포함되므로 %7 전에 -1 해주어야 한다.
 *
 */


#include <iostream>
#include <string>

using namespace std;

string Day[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
int MonthStart[12] = { 1,4,4,0,2,5,0,3,6,1,4,6 };

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int month = 0;
	int day = 0;

	int dayIndex = 0;

	cin >> month >> day;
	dayIndex = (day + MonthStart[month - 1] - 1) % 7;

	cout << Day[dayIndex];

	return 0;
}