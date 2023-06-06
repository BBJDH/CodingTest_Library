/*
 *1297 - TVũ��
 *
 *��Ÿ��� ������ �̿��� ���� C�� ���Ѵ�.
 *
 *���� �밢���� ���̸� ���ߴ� C�� ������ ������ ���ϰ�
 *
 *�ش� ������ �غ��� ���� A B�� ���� ����Ѵ�.
 *
 */

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	double TargetC = 0;
	double A = 0, B = 0, C = 0;
	double Mul = 0;
	cin >> TargetC >> A >> B;

	C = sqrt(A * A + B * B);
	Mul = TargetC / C;
	cout << static_cast<int>(A * Mul) << " " << static_cast<int>(B * Mul);

	return 0;
}