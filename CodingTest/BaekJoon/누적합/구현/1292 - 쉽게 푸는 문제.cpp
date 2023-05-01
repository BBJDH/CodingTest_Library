/*
 * 1292 - 쉽게 푸는 문제
 *
 * 누적합을 이용해 풀었다.
 *
 * 주어진 규칙에 따라 수를 더해 배열에 저장한다.
 *
 * 1000까지 모든 배열을 만든 후 주어진 구간에 대해
 * SumFromZero[Dest] - SumFromZero[Start - 1] 를 반환한다.
 *
 * 한번 배열을 만들면 위의 배열을 이용해 어떤 구간이든 구간합을 반환 가능해진다.
 *
 *
 * 또는 단순 구현을 통해서도 구현 가능하다
 *
 * 위의 합산과정중에 Start ~ Dest 구간에 해당하는 경우에만 Sum을 합산하여 출력한다.
 * 문제에서 입력은 한번만 주어지므로 위의 누적합 방식보다 더 비용이 적다.
 *
 *
 */


#include<iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int SumFromZero[1001]{};
	int Sum = 0;
	int Num = 1;
	int Count = 0;
	for (int i = 1; i < 1001; i++)
	{
		Sum += Num;
		Count++;
		SumFromZero[i] = Sum;
		if (Count == Num)
		{
			Count = 0;
			Num++;
		}
	}

	//입력
	int Start = 0, Dest = 0;
	cin >> Start >> Dest;
	cout << SumFromZero[Dest] - SumFromZero[Start - 1];

	return 0;
}