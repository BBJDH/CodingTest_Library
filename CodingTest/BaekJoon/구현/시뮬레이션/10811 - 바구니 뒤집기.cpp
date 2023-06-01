
/*
 *10811 - 바구니 뒤집기
 *
 *1 2 3 4 5
 *
 *2 1 3 4 5
 *2 1 4 3 5
 *3 4 1 2 5
 *
 *배열의 크기는 101로 고정하여 입력받은 뒤집기 From에서 To 까지 Swap을 통해 바구니 요소를 교환한다.
 *
 *From에서 To를 입력받아
 *
 *i=0으로 시작하여 (To-From)/2 까지 커지면서 From+i와 To-i를 교체해 나간다.
 *
 *
 *교훈 std::reverse 라는게 있었다... 이거 쓰면 편하다..
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