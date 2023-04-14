/*
 *1094 - 막대기
 *
 *[11047 - 동전 0] 과 유사한 문제다
 *
 *가장 큰 막대기인 64부터 시작해 크기 비교를 통해
 *현재 내가 가진 막대가 더 작다면 하나씩 더해나간다.
 *
 *내가 가진 막대가 더 커졌고 아직 TargetLength가 남아있다면
 *내가 가진 막대를 반으로 나누어 다시 TargetLength가 0이 될때 까지 진행한다
 *
 *최종 내가 가진 막대는 길이가 1이 되므로 반드시 정해에 도달하게 된다.
 *
 */

#include <iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int TargetLength = 0;
	cin >> TargetLength;
	int Result = 0;
	int CurrentStickLength = 64;
	while (TargetLength != 0)
	{
		if (TargetLength >= CurrentStickLength)
		{
			TargetLength = TargetLength - CurrentStickLength;
			Result++;
			continue;
		}
		CurrentStickLength /= 2;
	}
	cout << Result;
	return 0;
}