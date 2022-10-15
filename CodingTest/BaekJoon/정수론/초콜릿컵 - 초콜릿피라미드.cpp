#include<iostream>
#include<queue>
#include<vector>
using namespace std;

/*

������ ���ݸ� ������ ���غ���
White : RC + (R-1)(C-1)
Dark : (R-1)C + R(C-1)
�� ������ ������ �ȴ�

���� �� ����,

White : 2RC - R - C + 1;
Dark : 2RC - R - C;
�� ���� W �� D�� ���� ��ø�ȴ�
���� ������ �����ָ� �ٸ����ʵ� ���� ���� �� �ִ�.

R�� C�� ���� ���� �׾� �ø���, R �Ǵ� C�� 1�� �� ���� ���� ���� ���� ���ϸ� �ȴ�
���� R �� C�� �Ѱ��� ������ �ΰ�, �ñ׸������� ���غ���

R�� C �� R�� ū ���� �����ϸ�,
d = (R-C) �� ���������� R = C+d �� �ȴ� ���� ���� �ٽ� �����ϸ� 
Black �� 2(C+d)C - (C+d) -C �� �����ȴ�.
�����ϸ� 2C^2+2dC -2C-d => 2C^2 + 2(d-1)C -d�� �ȴ� �̰��� �ñ׸��� �����ϸ�

sigma(1~C) Dark : C * (C + 1) * (2 * C + 1) / 3 + (diff - 1) * C * (C + 1) - diff * C
sigma(1~C) White : C * (C + 1) * (2 * C + 1) / 3 + (diff - 1) * C * (C + 1) - diff * C +C
���� �� �� �ִ�.

*/

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long R = 0;
	long long C = 0;


	int TestCase = 0;
	cin >> TestCase;
	while (TestCase--)
	{
		cin >> R >> C;

		if (R < C)
			swap(R, C);
		long long diff = R - C;
		long long Dark = C * (C + 1) * (2 * C + 1) / 3 + (diff - 1) * C * (C + 1) - diff * C;
		long long White = Dark + C;

		cout << White << " " << Dark << "\n";

	}
	return 0;
}
