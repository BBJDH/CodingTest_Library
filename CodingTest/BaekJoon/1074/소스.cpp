#include<stdafx.h>
#pragma warning(disable:4996) 
//#include<stdio.h>
//#include<cmath>
using namespace std;

int sum=0;
//void Calc(int N, int row, int col)
//{
//	if (N== 0)
//		return;
//	//2^(n-1)으로 나눈 몫으로 계산
//
//	int const current_mul = pow(4, N-1); // 0 ~3의 배수가 될 원소
//	int const binery_row = row / static_cast<int>(pow(2, N - 1));
//	int const binery_col = col / static_cast<int>(pow(2, N - 1));
//	sum += current_mul * (binery_row * 2 + binery_col);
//	Calc(N-1, row % static_cast<int>(pow(2, N - 1)), col % static_cast<int>(pow(2, N - 1)));
//}
//void Calc(int N, int row, int col) //step 2
//{
//	if (N == 0)
//		return;
//	//2^(n-1)으로 나눈 몫으로 계산
//
//	int const current_mul = pow(2, 2 * (N - 1)); // 0 ~3의 배수가 될 원소
//	int const binery_row = row >> (N - 1);
//	int const binery_col = col >> (N - 1);
//	sum += current_mul * ((binery_row << 1) + binery_col);
//	Calc(N - 1, row % static_cast<int>(pow(2, N - 1)), col % static_cast<int>(pow(2, N - 1)));
//}

//void Calc(int N, int row, int col) //step 3
//{
//	if (N == 0)
//		return;
//	int const current_mul = pow(2, 2*(N - 1)); // 0 ~3의 배수가 될 원소
//	sum += current_mul * ((row >> (N - 1) << 1) + (col >> (N - 1)));
//	Calc(N - 1, row % static_cast<int>(pow(2, N - 1)), col % static_cast<int>(pow(2, N - 1)));
//}
void Calc(int N, int row, int col) //step 4
{
	if (N == 0)
		return;
	sum += (1 << 2 * (N - 1)) * ((row >> (N - 1) << 1) + (col >> (N - 1)));
	Calc(N - 1, row % (1<<(N - 1)), col % (1 << (N - 1)) );
}

int main()
{
	int row, col, N = 0;

	scanf("%d %d %d", &N, &row, &col);

	Calc(N, row, col);
	printf("%d", sum);
	//scanf("%d", &N);
	//printf("%d", 4 << (N-1));

	return 0;
}