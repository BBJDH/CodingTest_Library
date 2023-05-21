/*
 *
 *10813 - 공 바꾸기
 *
 *
 * 1 2 3 4 5
 *
 * 2 1 3 4 5
 * 2 1 4 3 5
 * 3 1 4 2 5
 *
 *바구니를 1차원 배열로 미리 만들어 각 인덱스에 해당 번호를 초기화해둔다
 *
 *이후 입력받는 CountOfSwap에 대해 바구니의 원소를 서로 교환한다.
 *
 *모두 교환 후 1번부터 Size 만큼 모든 바구니의 원소들을 출력한다.
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