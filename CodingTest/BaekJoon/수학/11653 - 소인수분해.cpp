/*
 *11653 - 소인수분해
 *
 *반복문 - 2부터 시작, 나눌수 있다면 더이상 나눌 수 없을때까지 나눔, 소수라면 본체 그대로 빠져나옴
 *남은 수가 1보다 크다면 출력
 *
 *재귀 - 임의의수를 받아서 2부터 시작해 나누어진다면 그 수를 출력, 나눈 수로 재귀호출
 *나누어지지 않는다면 그대로 빠져나옴, 1보다 크다면 출력
 */

#include <iostream>

using namespace std;


//반복문

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int inputNum = 0;
	cin >> inputNum;

	for (int i = 2; i * i <= inputNum; i++)
	{
		while (inputNum % i == 0)
		{
			inputNum /= i;
			cout << i << "\n";
		}
	}
	if (inputNum > 1)
		cout << inputNum;

	return 0;
}


//재귀
//int DivideNum(int const &Num)
//{
//	for(int i=2; i<Num; i++)
//	{
//		if(Num%i ==0)
//		{
//			cout << i << "\n";
//			return DivideNum( Num / i);
//		}
//	}
//	return Num;
//}
//
//int main()
//{
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
//
//	int inputNum = 0;
//	cin >> inputNum;
//	if(inputNum!=1)
//		cout << DivideNum(inputNum);
//
//	return 0;
//}
