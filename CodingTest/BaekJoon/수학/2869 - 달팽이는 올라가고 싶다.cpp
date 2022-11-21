/*
 *2869 - 달팽이는 올라가고 싶다
 *
 *정상에 도달하면 더이상 미끄러지지않으므로, 거꾸로생각해보면
 *정상-올라가는 높이 를 올라가는높이-떨어지는 높이 만큼 하루에 올라간다고 생각하면 된다
 *나누기연산을하면 나머지가 버려지므로 유의하자
 *나머지인 높이도 하루를 써서 올라가줘야한다(mod 연산으로 처리)
 *
 *
 */


#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int climbHeght = 0, fallheght = 0, goalHeight = 0;


	cin >> climbHeght >> fallheght >> goalHeight;

	goalHeight = goalHeight - climbHeght;

	int dayCount = goalHeight / (climbHeght - fallheght);
	if (goalHeight % (climbHeght - fallheght))
		dayCount++;
	dayCount++;


	cout << dayCount;
	return 0;
}