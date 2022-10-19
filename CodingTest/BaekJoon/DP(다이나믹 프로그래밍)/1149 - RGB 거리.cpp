/*
1149 - RGB 거리

각 턴마다 RGB 색을 고르는 최적의 수를 생각해 보자

N 번째 색을 고른다고 했을 때

N번째에서 R을 칠할 때의 총 비용 = N번째집의 R 비용 + min(이전 집에서 G를 칠한 총 비용, 이전입에서 B를 칠한 총 비용) 
N번째에서 G을 칠할 때의 총 비용 = N번째집의 G 비용 + min(이전 집에서 R를 칠한 총 비용, 이전입에서 B를 칠한 총 비용) 
N번째에서 B을 칠할 때의 총 비용 = N번째집의 B 비용 + min(이전 집에서 R를 칠한 총 비용, 이전입에서 G를 칠한 총 비용)

이 성립한다 이를 DP로 쌓아간 후
마지막 번째 집의 RGB 중에 최소값을 출력한다. 
*/
#include<iostream>

using namespace std;

struct RGB
{
	int R;
	int G;
	int B;
	
};

RGB Colors[1001]{};
RGB DP[1001]{};

int TestCase =0;

void MakeDP()
{
/* 	DP[0].R = min(Colors[0].G,Colors[0].B); 
	DP[0].G = min(Colors[0].R,Colors[0].B); 
	DP[0].B = min(Colors[0].R,Colors[0].G); */
	for (int i=1; i<=TestCase; i++)
	{
		DP[i].R = Colors[i].R + min(DP[i-1].G,DP[i-1].B);
		DP[i].G = Colors[i].G + min(DP[i-1].R,DP[i-1].B);
		DP[i].B = Colors[i].B + min(DP[i-1].R,DP[i-1].G);
	} 
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin>>TestCase;

	for(int i=1; i<=TestCase; i++)
	{
		cin>>Colors[i].R>>Colors[i].G>>Colors[i].B;
	}
	MakeDP();
	int Answer = min(DP[TestCase].R,min(DP[TestCase].G,DP[TestCase].B));
	cout<<Answer;
	return 0;
}	
