/*
 *2587 - 대표값2
 *
 *앞서 퀵소트를 직접 구현하여 문제를 풀었지만,
 *
 *사실은 algorithm에서 제공되는 퀵소트 함수를 사용하면 쉽게 해결 가능하다.
 *
 *
 */

#include<iostream>
#include <algorithm>

using namespace std;


int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int Nums[5]{};
	int Sum = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> Nums[i];
		Sum += Nums[i];
	}
	sort(Nums, &Nums[5]);
	cout << Sum / 5 << "\n" << Nums[2];

	return 0;
}