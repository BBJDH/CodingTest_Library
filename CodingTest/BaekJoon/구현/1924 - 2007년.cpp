/*
 *
 * 1924 - 2007��
 *
 * �����ϰ� �������� Ǯ����
 *
 * �� ������ ���ڿ� �迭�� �����ϰ�
 * �̸� ����ϱ����� �� �������� �������� ���� ���ڿ� ���ο� �ٰ��Ͽ� ����� �д�
 *
 * ������ 7���ֱ�� �ݺ��ǹǷ� %7�� �̿��Ͽ� �ε����� ���ε� ���ڿ��� ������ش�.
 *
 * ����Ҷ� �ش� ���� ���۳�¥�� ���ԵǹǷ� %7 ���� -1 ���־�� �Ѵ�.
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