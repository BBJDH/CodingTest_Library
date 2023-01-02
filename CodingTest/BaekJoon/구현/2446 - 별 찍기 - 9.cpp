/*
 *2446 - �� ��� - 9
 *
 *�� �Ƕ�̵带 ����ϴ� �ڵ带 �ۼ��ϰ�
 *�̰��� �ݺ��� �ȿ��� �𷡽ð��� �߰��� �����ϸ�
 *�������� ���ڸ� ����Ͽ� �ٽ� �Ƕ�̵带 ����ϵ��� �����ߴ�.
 *
 */


#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	int n = 0;
	cin >> n;

	int direction = 1;

	for (int i = n; i > 0 and i <= n; i -= direction)
	{
		for (int blank = 0; blank < n - i; blank++)
			cout << " ";
		for (int star = 0; star < i * 2 - 1; star++)
			cout << "*";
		cout << "\n";
		if (i == 1)
			direction *= -1;
	}

	return 0;
}