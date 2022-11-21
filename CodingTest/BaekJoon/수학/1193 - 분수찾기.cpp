/*
 *1193 - 분수찾기
 *대각선 기준으로 숫자를 깎아나가보자
 *1보다 크다면 해당 수에서 1을 빼고 다음 대각선으로 넘어간다
 *다음 대각에서도 2보다 크다면 2를 빼고 다음 대각으로 넘어간다
 *3보다 크다면 3을 빼고 다음 대각으로 넘어간다
 *.
 *.
 *.
 *각 대각선에는 1에서 해당 대각선을 담당하는 수까지만 표시가 가능해진다
 *
 *각 대각 구간에서 다음대각으로 못넘어갔을때 표시될 수는 다음과 같아 진다
 *1  2  3  4
 *1  2  3
 *1  2
 *1
 *여기에 각 대각의 담당수+1을 빼보자
 *
 *1(1) 2(1) 3(1) 4(1)
 *1(2) 2(2) 3(2)
 *1(3) 2(3)
 *1(4)
 *
 *자 이제 문제와 같은 유사성이 보이기 시작한다
 *이제 지그제그로 바꿔 출력해주면된다
 *
 *방법은 간단하다 각 대각선의 담당 수가 홀/짝에 따라 출력을 갈라준다
 */


#include<iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int inputNum = 0;
	cin >> inputNum;

	int denominator = 1;
	while (inputNum > denominator)
	{
		inputNum -= denominator;
		denominator++;
	}
	if (denominator % 2)
		cout << (denominator + 1) - inputNum << "/" << inputNum;
	else
		cout << inputNum << "/" << (denominator + 1) - inputNum;
	return 0;
}