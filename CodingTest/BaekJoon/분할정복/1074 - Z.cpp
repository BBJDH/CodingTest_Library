#include<stdio.h>
#include<cmath>
using namespace std;

int sum = 0;
void Calc(int N, int row, int col)
{
	if (N == 0)
		return;
	//2^(n-1)으로 나눈 몫으로 계산

	int const current_mul = pow(4, N - 1); // 0 ~3의 배수가 될 원소
	int const binery_row = row / static_cast<int>(pow(2, N - 1));
	int const binery_col = col / static_cast<int>(pow(2, N - 1));
	sum += current_mul * (binery_row * 2 + binery_col);
	Calc(N - 1, row % static_cast<int>(pow(2, N - 1)), col % static_cast<int>(pow(2, N - 1)));

}

int main()
{
	int row = 0;
	int col = 0;
	int N = 0;

	scanf("%d %d %d", &N, &row, &col);

	Calc(N, row, col);
	printf("%d", sum);

	return 0;
}