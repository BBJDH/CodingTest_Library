/*
 * 10810 - �� �ֱ�
 *
 * �ٱ��ϸ� �迭�� �����Ѵ�.
 * ���������� �������� �ٱ��ϸ� ä��� �Լ�
 * FillBasket�� �ۼ��Ѵ�.
 *
 * �Է¹޴� M(CountOfFill) ������ŭ �ٱ��ϸ� ��� ��ɿ� ����
 *
 * FillBasket�� ȣ���Ͽ� �ٱ��Ͽ� ���� ��´�.
 *
 * ���� �ݺ��� ���� �� ������� �ٱ��ϸ� ����Ѵ�.
 *
 *
 */

#include <iostream>
#include <vector>

using namespace std;

void FillBasket(int const Start, int const End, int const Elem, vector<int>& Basket)
{
	for (int i = Start; i <= End; i++)
	{
		Basket[i] = Elem;
	}
}


int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int SizeOfBasket = 0;
	int CountOfFill = 0;
	vector<int> Basket{};

	cin >> SizeOfBasket >> CountOfFill;
	Basket.resize(SizeOfBasket);

	while (CountOfFill--)
	{
		int Start = 0, End = 0, Elem = 0;
		cin >> Start >> End >> Elem;
		FillBasket(Start - 1, End - 1, Elem, Basket);
	}

	for (int const Elem : Basket)
	{
		cout << Elem << " ";
	}


	return 0;
}