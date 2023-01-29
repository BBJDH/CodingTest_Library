/*
 * 제 2회 고려대학교 MatKor Cup : 2023 Winter Open Contest
 *
 * A번 - 몇개고?
 *
 * 문제의 요구사항대로 구현한다.
 *
 * 간단한 구현문제, 조건문 구성을 간소화하는 노력을 해보자
 */
#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int Time = 0, WithAlcole = 0;

	cin >> Time >> WithAlcole;

	if (WithAlcole == 1)
	{
		cout << 280;
		return 0;
	}
	if (Time >= 12 and Time <= 16)
	{
		cout << 320;
		return 0;
	}
	cout << 280;

	return 0;
}