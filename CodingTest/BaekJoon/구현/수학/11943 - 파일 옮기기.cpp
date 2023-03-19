/*
 *
 *11943 - 파일 옮기기
 *
 * A B
 * C D  로 바구니를 묘사하면
 * 
 * A+D B+C
 * 
 * 서로 대각선으로 더한경우의 두가지가 
 * 
 * 나올 수 있는 모든 경우의 수 이다
 * 
 * 이 두 값중 최소값을 출력한다.
 * 
 *
 */

#include <iostream>

using namespace std;

struct Aa
{
	int a;
	char i;
};

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int A = 0, B = 0, C = 0, D = 0;

	cin >> A >> B >> C >> D;

	cout << min(B + C, A + D);

	Aa a;
	a.a = 10;

	printf("%d",sizeof(a));

	return 0;
}