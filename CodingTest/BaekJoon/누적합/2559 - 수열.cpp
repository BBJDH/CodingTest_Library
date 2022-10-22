/*
2559 - 수열

누적합 문제이다
주어진 온도들을 순차적으로 더해지는 값을 DP 배열로 저장해 둔다
온도 : 3 -2 -4 -9  0    3   7   13   8  -3 (n개 배열)
DP :  0 3  1 -3 -12 -12  -9  -2   11  19  16 (n+1개 배열)

즉 DP[n]은 n일차 까지의 온도 누적값과 같다.

DP의 앞에 0을 추가 한 이유는 다음과 같다

지정된 구간의 온도를 구하기 위한식을 구해보자
더해지는 온도구간의 시작점을 start, 끝점은 end로 한다
start ~ end의 구간합 :  DP[end] - DP[start-1] 을 의미한다.
start ~ end는 start와 start+1... end 까지의 온도들의 누적합 이므로
start 이전의 누적 온도를 빼주는 것이다.

예를 들어 3일째부터 5일째까지의 누적 온도는 DP[5] - DP[2] 와 같다.
이 경우 start-1에서 index가 -1이 될 가능성을 고려하여 앞에 0을 추가해 준다
이로써 1일차의 누적합은 DP[1] - DP[0] = 3으로 DP[-1]접근을 방지 할 수 있다.

*/



#include<iostream>
#include<vector>

using namespace std;

vector<int> Temporature{};
vector<int> Temporature_DP{};

int InputCase = 0;
int K = 0;

void MakeDP()
{
	Temporature_DP.emplace_back();
	int Sum = 0;
	for (int i = 1; i <= Temporature.size(); i++)
	{
		Sum += Temporature[i - 1];
		Temporature_DP.emplace_back(Sum);
	}
}
void FindMax()
{
	int StartIndex = 0;
	int EndIndex = StartIndex + K;
	int Max = -10000000;
	while (EndIndex < Temporature_DP.size())
	{
		int Sum = Temporature_DP[EndIndex] - Temporature_DP[StartIndex];
		Max = max(Max, Sum);
		StartIndex++;
		EndIndex++;
	}
	cout << Max;
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> InputCase;
	cin >> K;

	while (InputCase--)
	{
		int InputTemp{};

		cin >> InputTemp;
		Temporature.emplace_back(InputTemp);
	}
	MakeDP();
	FindMax();
	return 0;
}