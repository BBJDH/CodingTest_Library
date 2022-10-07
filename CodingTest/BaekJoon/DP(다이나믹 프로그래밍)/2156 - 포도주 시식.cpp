/*
포도주 시식
DP 문제다 또다시 거꾸로 끝에서 생각해보자

포도주는 세번 연속 마실 수없다 가장 끝에서 먹는 경우의수가 몇개 없다
.... OOX
.... OXO
.... XOO
의 경우의 수 뿐이다
다시 정리하면
.... OOX n-1
.... OXO n-2 + n번째잔
.... XOO n-3 + n-1번째, n번째 잔

DP[0] = 0 0개를 마시는 경우는 0
DP[1] = 1
DP[2] = 2
DP[3] =

*/

#include<iostream>
#include<algorithm>

using namespace std;

int DP[10001]{};
int Wines[10001]{};

int GlassesNum = 0;


void Solution()
{
	DP[1] = Wines[1];
	DP[2] = Wines[1] + Wines[2];
	// 3부터 적용

	/*
	.... OOX n-1
	.... OXO n-2 + n번째잔
	.... XOO n-3 + n-1번째, n번째 잔

	DP[n-1] 과
	DP[n-2]+Wines[n],
	DP[n-3]+Wines[n-1]+Wines[n]
	이 셋중에 가장 큰것을 DP[n]으로 함


	*/

	for (int i = 3; i <= GlassesNum; i++)
	{
		int MaxVal = max(DP[i - 1], DP[i - 2] + Wines[i]);
		MaxVal = max(MaxVal, DP[i - 3] + Wines[i - 1] + Wines[i]);
		DP[i] = MaxVal;
	}
}

int main()
{

	scanf("%d", &GlassesNum);

	for (int i = 1; i <= GlassesNum; i++)
	{
		int InputNum = 0;
		scanf("%d", &InputNum);
		Wines[i] = InputNum;
	}
	Solution();
	printf("%d", DP[GlassesNum]);

	return 0;
}
