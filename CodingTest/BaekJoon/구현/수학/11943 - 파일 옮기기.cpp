/*
 *
 *11943 - ���� �ű��
 *
 * A B
 * C D  �� �ٱ��ϸ� �����ϸ�
 * 
 * A+D B+C
 * 
 * ���� �밢������ ���Ѱ���� �ΰ����� 
 * 
 * ���� �� �ִ� ��� ����� �� �̴�
 * 
 * �� �� ���� �ּҰ��� ����Ѵ�.
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