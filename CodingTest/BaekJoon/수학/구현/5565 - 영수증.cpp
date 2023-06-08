/*
 *5565 - 영수증
 *
 *총 금액 합계에서 9권의 가격을 빼내어 남은 한권의 책 가격을 출력한다.
 *
 *요구사항대로 구현한다.
 *
 */

#include<iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int Money = 0;
	cin >> Money;

	for (int i = 0; i < 9; i++)
	{
		int InputNum = 0;
		cin >> InputNum;
		Money -= InputNum;
	}
	cout << Money;
	return 0;
}