
/*
 *10811 - �ٱ��� ������
 *
 *1 2 3 4 5
 *
 *2 1 3 4 5
 *2 1 4 3 5
 *3 4 1 2 5
 *
 *�迭�� ũ��� 101�� �����Ͽ� �Է¹��� ������ From���� To ���� Swap�� ���� �ٱ��� ��Ҹ� ��ȯ�Ѵ�.
 *
 *From���� To�� �Է¹޾�
 *
 *i=0���� �����Ͽ� (To-From)/2 ���� Ŀ���鼭 From+i�� To-i�� ��ü�� ������.
 *
 *
 *���� std::reverse ��°� �־���... �̰� ���� ���ϴ�..
 *
 */

#include <iostream>

using namespace std;

int Basket[101]{};
int Size = 0, ReverseCount = 0;

void ReverseBasket(int const From, int const To)
{
	for (int i = 0; i <= (To - From) / 2; i++)
	{
		swap(Basket[From + i], Basket[To - i]);
	}
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);


	for (int i = 1; i < 101; i++)
	{
		Basket[i] = i;
	}

	cin >> Size >> ReverseCount;

	while (ReverseCount--)
	{
		int From = 0, To = 0;
		cin >> From >> To;

		ReverseBasket(From, To);

	}

	for (int i = 1; i <= Size; i++)
	{
		cout << Basket[i] << " ";
	}

	return 0;
}