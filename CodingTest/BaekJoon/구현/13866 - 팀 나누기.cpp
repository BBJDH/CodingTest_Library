/*
 *13866 - 팀 나누기
 *
 *팀을 가장 벨런스맞게 나누는 방법은 1등과 4등이 팀을 짜고,
 *2등과 3등이 팀을 짜는 방법으로 규칙이 정해진다.
 *
 *따라서 입력받는 수들의 Min과 Max를 따로 분류하여 팀을 짜고
 *
 *남은 둘을 팀으로 계산해주는 코드를 작성한다.
 *
 *이 두팀중 어느팀이 더 강한팀인지 알수가 없다.
 *
 *따라서 이 둘의 차는 절대값으로 계산한다.
 *
 *수의 범위가 0~ 10000으로 국한되므로 이를 감안해 Min과 Max를 초기화한다.
 *
 *
 */
#include<iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int NumberOfMin = 100000;
	int NumberOfMax = -1;
	int Sum = 0;
	for (int i = 0; i < 4; i++)
	{
		int NumOfInput = 0;
		cin >> NumOfInput;
		NumberOfMin = min(NumberOfMin, NumOfInput);
		NumberOfMax = max(NumberOfMax, NumOfInput);
		Sum += NumOfInput;
	}
	int Team1 = (NumberOfMin + NumberOfMax);
	int Team2 = Sum - Team1;
	cout << abs(Team1 - Team2);


	return 0;
}