/*
 *
 *11943 - ���� �ű��
 *
 *
 */

#include <iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int A = 0, B = 0, C = 0, D = 0;

	cin >> A >> B >> C >> D;

	cout << min(B + C, A + D);

	return 0;
}