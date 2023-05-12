/*
 * 10810 - 공 넣기
 *
 * 바구니를 배열로 생성한다.
 * 지정구간에 연속으로 바구니를 채우는 함수
 * FillBasket을 작성한다.
 *
 * 입력받는 M(CountOfFill) 개수만큼 바구니를 담는 명령에 따라
 *
 * FillBasket을 호출하여 바구니에 공을 담는다.
 *
 * 위의 반복문 종료 후 만들어진 바구니를 출력한다.
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