
/*
1676 - 팩토리얼 0의 개수
5의 제곱수로 나누어지는 만큼 더하면 된다
*/
#include<iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int InputNum = 0;
	int Count = 0;
	cin >> InputNum;

	cout << InputNum / 5 + InputNum / 25 + InputNum / 125;
	return 0;
}
