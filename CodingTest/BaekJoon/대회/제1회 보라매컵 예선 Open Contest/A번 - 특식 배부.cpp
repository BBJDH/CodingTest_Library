
/*
 *��1ȸ ������� ���� Open Contest
 *A�� - Ư�� ���
 *
 *���� �����ϰ� �Է� ���� N Ȥ�� ABC�� ���Ͽ� �� ���� ���� ���Ͽ� ����Ѵ�.
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