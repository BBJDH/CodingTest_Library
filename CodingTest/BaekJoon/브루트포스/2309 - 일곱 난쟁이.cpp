/*
 *2309 - 일곱 난쟁이
 *
 *
 *난쟁이의 수는 9명 고정이고 이중 두명을 골라내면 된다
 *
 *입력을 받을때 미리 모든 난장이들의 키의 합을 구해두고,
 *
 *위의 총합에서 임의의 난쟁이 둘의 키의 합을 빼서비교한다.
 *
 *9*9 인 N^2으로 모두 확인해서(브루트 포스) 조건에 부합하면
 *
 *둘을 제외한 난쟁이들을 출력하고 종료한다.
 *
 *출력조건에 맞추어 입력 받은 배열을 정렬해주어야 한다.
 *
 *
 *
 */

#include <iostream>
#include <algorithm>

using namespace std;


void PrintWithoutTwoElem(int const Index1, int const Index2, int const* const PrintArr)
{
	for (int i = 0; i < 9; i++)
	{
		if (i == Index1 or i == Index2)continue;;

		cout << PrintArr[i] << "\n";
	}
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int Dwarf[9]{};

	int Sum = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> Dwarf[i];
		Sum += Dwarf[i];
	}
	sort(&Dwarf[0], &Dwarf[9]);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (Sum - (Dwarf[i] + Dwarf[j]) == 100)
			{
				PrintWithoutTwoElem(i, j, Dwarf);
				return 0;
			}
		}
	}


	return 0;
}