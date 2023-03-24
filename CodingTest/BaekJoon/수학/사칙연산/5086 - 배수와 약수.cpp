/*
 *5086 - 배수와 약수
 *
 * 배수와 약수를 코드로 어떻게 식별해야하는지 물어보는 문제였다
 *
 * %연산자를 이용해 배수와 약수를 판별한다.
 * 만약 양쪽 다 아니라면 해당 입력에 대하여 neither를 출력
 *
 */

#include <iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int FirstNumOfInput = -1, SecondNumOfInput = -1;


	while (true)
	{
		cin >> FirstNumOfInput >> SecondNumOfInput;

		if (FirstNumOfInput == 0 and SecondNumOfInput == 0)
		{
			break;
		}

		if (SecondNumOfInput % FirstNumOfInput == 0)
		{
			cout << "factor\n";
			continue;
		}
		if (FirstNumOfInput % SecondNumOfInput == 0)
		{
			cout << "multiple\n";
			continue;
		}

		cout << "neither\n";
	}

	return 0;
}