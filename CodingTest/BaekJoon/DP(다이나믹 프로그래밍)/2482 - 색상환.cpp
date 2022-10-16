
/*

2482 - 색상환

인접한 두색은 사용하지 않는다
어떤 인접한 두 색을 선택하지 않고 K개의 색을 선택하는 경우의 수를 골라라

예시
5색의 두개 추출
OXOXX
OXXOX
XOXOX
XOXXO
XXOXO

6 2
OXXXOX
OXXOXX
OXOXXX
XOXOXX
XOXXOX
XOXXXO
XXOXOX
XXOXXO
XXXOXO

구하는 방법

범위가 최대 1000*1000 까지이므로 배열로 지정해 DP로 접근 가능하다
N개의 색상환에서 K개의 색을 칠한다고 했을때를 나누어 생각해보면,
X[....]XO 이렇게 제일 끝에 칠한 경우의 수 와
[]X 반대로 제일 끝을 칠하지 않은 경우의 수로 나누어 생각할 수있다

[]안을 생각해보면, 양옆이 X로 되어있으므로 []의 양끝에 색을 칠할 수 있다
따라서 []안은 선형으로 생각해서 마음대로 뽑을 수 있는 경우의 수 이다

[]에 들어갈 색상의 경우의 수를 골라보자

예시
3개에서 2개를 뽑는 경우
OXO

4개에서 2개를 뽑는 경우
OXOX
OXXO
XOXO

[]안을 다시 나누어 생각해 보면

{N-2}XO  와 같이 끝을 하나 색칠한 경우와,			(N-2)에서 K-1개를 선형으로 색칠하는 경우의 수
{N-1 }X	와 같이 끝이 색칠되어 있지 않은 경우이다   (N-1)에서 K개를 선형으로 색칠하는 경우의 수

따라서 []안의 경우의 수 Linear_DP[N][K] = Linear_DP[N-2][K-1] + Linear_DP[N-1][K] 가 성립된다
DP[N][0]은 한가지 뿐이고 (색을 아무것도 칠하지 않는 경우의 수)
DP[N][1]은 N을 만족하므로, 이를 통해 위의 식으로 Linear_DP를 구성한다

이후 다시 색상환으로 돌아오면,
X[N-3]XO 이렇게 제일 끝에 칠한 경우의 수		=>	Linear_DP[N-3][K-1]
[N-1]X 반대로 제일 끝을 칠하지 않은 경우의 수		=>	Linear_DP[N-1][K]

즉 색상환 N개에서 K개를 뽑을 경우의 수는 Linear_DP[N-3][K-1] + Linear_DP[N-1][K] 가 성립한다.

연산 후 10억3의 나머지로 빼서 저장하는것, 잊지말자.
*/
#include<iostream>

using namespace std;

int Linear_DP[1001][1001]{};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 1001; i++)
	{
		Linear_DP[i][0] = 1;
		Linear_DP[i][1] = i;
	}
	for (int n = 2; n < 1001; n++)
	{
		for (int k = 2; k < 1001; k++)
		{
			Linear_DP[n][k] = (Linear_DP[n - 2][k - 1] + Linear_DP[n - 1][k]) % 1000000003;
		}
	}

	int N = 0; int K = 0;

	cin >> N >> K;

	cout << (Linear_DP[N - 3][K - 1] + Linear_DP[N - 1][K]) % 1000000003;

	return 0;
}
