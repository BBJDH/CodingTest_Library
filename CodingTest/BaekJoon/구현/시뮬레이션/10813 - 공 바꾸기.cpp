/*
 *
 *10813 - �� �ٲٱ�
 *
 *
 * 1 2 3 4 5
 *
 * 2 1 3 4 5
 * 2 1 4 3 5
 * 3 1 4 2 5
 *
 *�ٱ��ϸ� 1���� �迭�� �̸� ����� �� �ε����� �ش� ��ȣ�� �ʱ�ȭ�صд�
 *
 *���� �Է¹޴� CountOfSwap�� ���� �ٱ����� ���Ҹ� ���� ��ȯ�Ѵ�.
 *
 *��� ��ȯ �� 1������ Size ��ŭ ��� �ٱ����� ���ҵ��� ����Ѵ�.
 *
 */

#include <iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);


	int Basket[101]{};
	int Size = 0, CountOfSwap = 0;

	cin >> Size >> CountOfSwap;

	for (int i = 1; i <= Size; i++)
	{
		Basket[i] = i;
	}

	while (CountOfSwap--)
	{
		int From = 0, To = 0;
		cin >> From >> To;

		swap(Basket[From], Basket[To]);
	}

	for (int i = 1; i <= Size; i++)
	{
		cout << Basket[i] << " ";
	}

	return 0;
}