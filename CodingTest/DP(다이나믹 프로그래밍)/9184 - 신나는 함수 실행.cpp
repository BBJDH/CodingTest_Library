
/*
9184 - 신나는 함수 실행

지정된 조건으로 함수호출이 아닌 배열에 미리 기록해둔다

해당함수의 조건이 항상 기존 번호보다 하위 번호를 호출함을 이용하여
for문 아래에서 위로 올라가면서 호출될 수 있는 모든 경우의 수를 모두 계산

51 * 51 * 51 = 132651 만큼의 연산을 완료하면
모든 답을 기록가능하다

예외사항:
음수가 들어온다면 조건에 따라 1을 출력해주면된다
*/
#include<iostream>

using namespace std;

int Results[21][21][21]{};

int FindDP(int A, int B, int C)
{
	if (A <= 0 or B <= 0 or C <= 0)
		return 1;

	if (A < B and B < C)
		return Results[A][B][C - 1] + Results[A][B - 1][C - 1] - Results[A][B - 1][C];

	return Results[A - 1][B][C] + Results[A - 1][B - 1][C] + Results[A - 1][B][C - 1] - Results[A - 1][B - 1][C - 1];
}

void DP()
{

	for (int A = 0; A < 21; A++)
	{
		for (int B = 0; B < 21; B++)
		{
			for (int C = 0; C < 21; C++)
			{
				Results[A][B][C] = FindDP(A, B, C);
			}
		}
	}
}

/*
출력형식을 지켜주기위해 편한 printf를 사용한다
	ios_base::sync_with_stdio(false); 구문을 선언했기에
printf cout의 싱크가 맞지 않는다 혼용사용하지 않도록 주의하자
*/

//void Solution(int A, int B, int C)
//{
//	printf("w(%d, %d, %d) = ", A, B, C);
//	if (A <= 0 or B <= 0 or C <= 0)
//	{
//		printf("%d\n", 1);
//		return;
//	}
//	if (A <= 20 and B <= 20 and C <= 20)
//	{
//		printf("%d\n",Results[A][B][C]);
//		return;
//	}
//	printf("%d\n", Results[20][20][20]);
//}
void Solution(int A, int B, int C)
{
	printf("w(%d, %d, %d) = ", A, B, C);
	//cout << "w(" << A << ", " << B << ", " << C << ") = ";
	if (A <= 0 or B <= 0 or C <= 0)
	{
		cout << 1 << "\n";
		return;
	}
	if (A <= 20 and B <= 20 and C <= 20)
	{
		cout << Results[A][B][C] << "\n";
		return;
	}
	cout << Results[20][20][20] << "\n";
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	DP();
	while (true)
	{
		int A = 0, B = 0, C = 0;
		cin >> A >> B >> C;

		if (A == -1 and B == -1 and C == -1)
			break;
		Solution(A, B, C);
	}
	return 0;
}
