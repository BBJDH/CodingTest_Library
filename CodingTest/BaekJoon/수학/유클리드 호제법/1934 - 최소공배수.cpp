/*
 *1934 - �ּҰ����
 *
 *
 *�־��� �� A�� B�� ���Ͽ� �ִ� ������� G��� �� ��,
 *
 *A�� G�� ���� ���� a, B �� G�� ���� ���� b��� �Ѵٸ�
 *
 *�ּҰ���� L = G x a x b �� �������� �˰� ������ �����ؾ� �Ѵ�.
 *
 *
 *��Ŭ���� ȣ�������� �� ���� �ּҰ������ ���� ���ϰ� a�� b�� ���� ��
 *
 *�� �� ���ڸ� ���Ͽ� �ּҰ������ ����Ѵ�.
 *
 */


#include <iostream>
#include <algorithm>

using namespace std;


int GCD(int const Bigger, int const Smaller)
{
	if (Smaller == 0)
	{
		return Bigger;
	}
	return GCD(Smaller, Bigger % Smaller);
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int TestCase = 0;
	cin >> TestCase;

	while (TestCase--)
	{
		int NumberOfInputs[2]{};
		for (int i = 0; i < 2; i++)
		{
			cin >> NumberOfInputs[i];
		}
		sort(NumberOfInputs, &NumberOfInputs[1]);

		int G = GCD(NumberOfInputs[1], NumberOfInputs[0]);
		int a = NumberOfInputs[0] / G;
		int b = NumberOfInputs[1] / G;
		cout << G * a * b << "\n";
	}

	return 0;
}