/*
 *3053 - �ý� ������
 *
 *��Ŭ���� �������� �츮�� �ƴ� �Ϲ����� ���� ���� ������ �����Ͽ� ����Ѵ�.
 *
 *�ý� �����п����� ���� ������ ������� �����ȴ�
 *
 *�� �Է� ���� r �� �� �밢������ �ϴ� �������̹Ƿ�
 *�� �������� ���̸� ���ؼ� ������ָ� �ȴ�. R = 2r �̹Ƿ� 2r*2r/2 =4r^2/2 = 2r^2 �̴�
 *
 *
 */

#include <iostream>
#include <math.h>
using namespace std;
#define PIE atan(1)*4

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout << fixed;
	cout.precision(6);
	double r = 0;
	cin >> r;

	cout << r * r * PIE << "\n";
	cout << r * r * 2;

	return 0;
}