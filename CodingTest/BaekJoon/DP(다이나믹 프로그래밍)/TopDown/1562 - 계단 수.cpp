/*
 *1562 - 계단수
 *

 BottomUp도 좋고 TopDown도 풀리지만
 이문제는 TopDown이 편하다

기본 DP를[길이][현재 번호][방문 비트]로 기록한다
여기서 주의할 점은 비트는 두개만 있으면 된다는 것이다
문제의 조건인 0~ 9를 모두 방문한 수열이 필요하므로
0번과 9번을 방문한 두개의 비트만 있으면 된다.

그리고 완전탐색으로 재귀를 돌리고 예외는 제거,  중복은 return으로 메모이제이션 해준다(return DP[Size][CurrentNum][Bit];)
이 후에 수열이 완성되었는지를 검사해준다
즉 최종 길이에 도달했는지와 0번과 9번을 방문했다면
규칙에 따라 +1 -1 방문을 시키므로 수열이 완성됨이 보장된다 (+1)
(0과 9의 경우 -1과 10의 예외를 0으로 리턴하도록 제외한다)
이 모든것을 합쳐서 다시 원점으로 돌아온다 Size 0번 배열로 누적됨

마지막 0번 배열의 1~9번호시작에 해당하는 값들을 모두 누적하여 출력한다
(문제는 번호 0 시작은 제외하였으므로 1부터 시작시킨다)

각 합산에서 Mod 연산을 꼭 처리해주자

 *
 */
 //TopDown
#include <iostream>

using namespace std;

#define LIMIT 1000000000

int DP[101][10][4]{};
int N = 0;



int MakeDP(int const& Size, int const& CurrentNum, int Bit)
{

	//DP[Size][CurrentNum][Bit] 를 찾겠다
	//길이가 Size이고 현재 방문번호가 CurrentNum이며 방문비트는 Bit인 상태에서 골까지 가는 비용을 구하겠다.
	if (CurrentNum < 0 or CurrentNum>9) return 0;

	//메모이제이션
	if (DP[Size][CurrentNum][Bit] != 0)
		return DP[Size][CurrentNum][Bit];
	//보존해줄 비트 업데이트
	if (CurrentNum == 0)
		Bit = Bit | 1;
	else if (CurrentNum == 9)
		Bit = Bit | 1 << 1;

	if (Size == N - 1)	//길이 끝에 도달
	{
		if (Bit == 3) return 1;// 성립하면 1 수열 하나가 나왔다는 뜻
		else return 0;
	}

	return DP[Size][CurrentNum][Bit] = (MakeDP(Size + 1, CurrentNum - 1, Bit) + MakeDP(Size + 1, CurrentNum + 1, Bit)) % LIMIT;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	int Sum = 0;
	for (int i = 1; i < 10; i++) //시작 번호
	{
		Sum = (Sum + MakeDP(0, i, 0)) % LIMIT;
	}
	cout << Sum;
	return 0;
}

//BottomUp
//마찬가지로 0는 0, 이외는 1을 넣어주고 끝까지 도달한 번호만 마지막에 합산한다

//#include <iostream>
//using namespace std;
//
//# define LIMIT  1000000000
//int DP[101][10][1024]{};
//
//int N = 0;
//
//int main()
//{
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
//
//	cin >> N;
//
//	for (int i = 1; i < 10; i++)
//		DP[1][i][static_cast<int>(1 << i)] = 1;
//
//
//	for(int i=1; i<=N;i++)
//	{
//		//i 길이
//		for(int num=0; num<10; num++)
//		{
//			//마지막번호 num 갱신 시작
//			//0은 이전 마지막수 1만이 필요하고  9는 마지막수 8만 필요함
//			//나머지 1~ 8 업데이트는 각각 +-1이 필요함
//
//			for(int bit=0; bit<1024; bit++)
//			{
//				//방문처리 bit는 이전 방문데이터이므로 새롭게 Num를 or 연산
//				int sum = 0;
//				if (num == 0)
//					sum = DP[i - 1][1][bit];
//				else if(num == 9)
//					sum = DP[i - 1][8][bit];
//				else
//				{
//					sum += DP[i - 1][num-1][bit];
//					sum = (sum +DP[i - 1][num+1][bit]) %LIMIT;
//
//				}
//				//if(sum>=1 and i>2)
//					DP[i][num][bit | 1<<num] = (DP[i][num][bit | 1 << num]+ sum) %LIMIT ;
//			}
//			
//		}
//	}
//	int Answer = 0;
//
//	for (int i = 0; i < 10; i++)
//	{
//		Answer = (Answer+DP[N][i][1023])%LIMIT;
//	}
//
//	cout << Answer;
//	return 0;
//}