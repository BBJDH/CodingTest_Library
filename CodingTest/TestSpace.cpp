/*
 *2022 ��1ȸ ����Ȯ���� A�� - �����ΰ�? ?
 *
 *�Է� ���� k�� ���� ���ʿ��� �����ϴ����� Ȯ�����ָ� �ȴ� ��
 *
 *a (a*k+b) == (c * k + d) �� true��� �ش� �Լ� f(x)�� �����̴�
 *
 *
 */

#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long k = 0;
	long long a = 0, b = 0, c = 0, d = 0;

	cin >> k>>a>>b>>c>>d;

	if((a*k+b) == (c * k + d))
	{
		cout << "Yes"<<" "<< (a * k + b);
	}
	else
	{
		cout << "No";
	}

	return 0;
}