/*
 *10886 - 0 = not cute / 1 = cute
 *
 *
 *0의 개수와 1의 개수를 담을 1차원 배열을 미리 만들고
 *
 *사람수 만큼 입력받아 배열에 누적합산한다.
 *
 *모두 입력받은 후 인덱스 0과 1로 접근한 누적 대답 수를 비교하여 결과를 출력한다.
 *
 */

#include <iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int CountOfPeople = 0;
	int CuteOrNot[2]{};
	cin >> CountOfPeople;

	while (CountOfPeople--)
	{
		int Input = 0;
		cin >> Input;
		CuteOrNot[Input]++;
	}

	if (CuteOrNot[0] > CuteOrNot[1])
	{
		cout << "Junhee is not cute!";
	}
	else
	{
		cout << "Junhee is cute!";
	}

	return 0;
}