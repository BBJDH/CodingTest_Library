#include<iostream>
#include<math.h>
using namespace std;

int Marked_Nums[1000001]{};
void Mark_Multiple()
{
	//배열을 2부터 확인 시작
	// 배열원소가 1이라면 넘어감
	// 0인경우는 소수가된다
	// 그리고 이 소수에 대해서 배수인수를 모두 1로 마킹 해준다
	// 다음배열 수를 탐색
	// 수는 1,000,000까지 이지만 1000까지 하면 된다
	//
	int Max_Num = sqrt(1000001);
	Marked_Nums[1] = 1;
	for (int i = 2; i < Max_Num; i++)
	{
		if (Marked_Nums[i] == 1)
		{
		}
		else
		{
			for (int j = i * i; j < 1000001; j += i)
			{
				Marked_Nums[j] = 1;
			}
		}
	}

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	int Start_Num = 0;
	int End_Num = 0;

	cin >> Start_Num >> End_Num;

	Mark_Multiple();

	for (int i = Start_Num; i <= End_Num; i++)
	{
		if (Marked_Nums[i] == 0)
			cout << i << "\n";
	}
	return 0;
}