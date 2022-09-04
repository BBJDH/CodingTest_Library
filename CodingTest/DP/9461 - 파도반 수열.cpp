/*
9461 - 파도반 수열
 { 0,1,1,1,2,2,3,4,5,7,9 } 까지는 규칙을 찾을수 없다, 점화식으로 사용한다
 이후로는 n = n-1 + n-5 의관계가 성립한다

 주의할사항 : 숫자가 9천억 가까이 올라간다(100번째 삼각형 8천8백만) 저장할 데이터를 맞춰주자
*/
#include<iostream>

using namespace std;

long long DP[101] = { 0,1,1,1,2,2,3,4,5,7,9 };

void MakeDP()
{
	for (int i = 11; i < 101; i++)
		DP[i] = DP[i - 1] + DP[i - 5];
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int TestCase = 0;

	MakeDP();

	cin >> TestCase;
	while (TestCase--)
	{
		int InputNum = 0;
		cin >> InputNum;
		cout << DP[InputNum] << "\n";
	}


	return 0;
}