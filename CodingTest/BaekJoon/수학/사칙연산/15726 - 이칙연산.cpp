/*
 *15726 - ��Ģ����
 *
 *���ϰ� ������ ���� ������ ���ϴ� ��� �ΰ��� �� �̹Ƿ�
 *���� max�� ����Ѵ�.
 *
 *������ ���ǿ� ���� �Ҽ����� ������ ���� ���� �ڷ������� ĳ���� �ߴ�.
 *
 */

#include <iostream>
#define LIMIT 1000000000

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	double A = 0, B = 0, C = 0;
	cin >> A >> B >> C;

	cout << static_cast<int>(max(A * B / C, A / B * C));

	return 0;
}