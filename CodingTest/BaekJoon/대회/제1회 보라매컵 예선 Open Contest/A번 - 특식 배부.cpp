
/*
 *제1회 보라매컵 예선 Open Contest
 *A번 - 특식 배부
 *
 *답은 간단하게 입력 받은 N 혹은 ABC에 대하여 더 작은 수를 합하여 출력한다.
 *
 */

#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;
	int A = 0, B = 0, C = 0;
	cin >> N >> A >> B >> C;

	cout << min(N, A) + min(N, B) + min(N, C);

	return 0;
}