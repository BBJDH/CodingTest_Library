
/*
 *4976 - ķ��
 *
 *�ް��ȿ� ķ������ �ѹ��� ���°��� �ƴ϶�
 *
 *������ ����� ������ �ް���¥ �ȿ� �ִ��� ķ������
 *����Ҽ� �ִ� �ϼ��� ���ϴ°��� �䱸�����̴�.
 *
 *������ ������ �ް��ϼ� V�ȿ��� ��밡���� �� P�� �����ŭ ����ϰ�
 *���� �ϼ��� ���� �� P�� �����Ͽ� ���ӵǴ� ����� L�μ� ����Ѵ�
 *(�� P�� ����� ���� �������ϼ��� L�� ���Ͽ� �� ���� �ϼ��� �ջ��Ѵ�.)
 *
 *
 */

#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int L = 0, P = 0, V = 0;
	int TestCase = 0;
	while (true)
	{
		cin >> L >> P >> V;
		if (V == 0)
			return 0;
		TestCase++;
		int mul = V / P;
		int mod = min(L, V - (mul * P));
		int result = mul * L + mod;
		cout << "Case " << TestCase << ": " << result << "\n";
	}


	return 0;
}