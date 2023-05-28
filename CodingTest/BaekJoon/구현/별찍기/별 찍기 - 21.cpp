/*
 *10996 - 별 찍기 - 21
 *
 * 규칙을 풀어보면
 *
 * 입력받은 수 InputNum에 대하여 2N 만큼 라인을 출력한다
 * (1인경우 2라인으로 공백이 출력되지만 백준은 빈공백과 개행문자 한번은
 * 무시하고 정답처리된다.)
 *
 *그리고 각 라인번호가 홀수라면 홀수 번째에 별을,
 *짝수라면 짝수 번째에 별을 출력한다.
 *
 * 위의 기능을 하는 함수를 작성하고,
 *
 * 입력받은 InputNum*2 만큼의 라인에 대해
 * 함수를 호출한다.
 *
 *
 */

#include <iostream>

using namespace std;

void PrintStar(int const Num, int const LineNum)
{
	for (int i = 1; i <= Num; i++)
	{
		if (i % 2 == LineNum % 2)
		{
			cout << "*";
		}
		else
		{
			cout << " ";
		}
	}
}


int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int InputNum = 0;
	cin >> InputNum;

	for (int i = 0; i < InputNum * 2; i++)
	{
		PrintStar(InputNum, i + 1);
		cout << "\n";
	}

	return 0;
}