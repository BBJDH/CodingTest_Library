/*
 *2455 - 지능형 기차
 *
 *요구사항대로 구현한다.
 *
 *입력 받는 4개의 정류장의 승차, 하차수대로 현재 인원을 계산한다.
 *
 *이후 미리 준비된 Result와 비교하여 최대수를 Result에 업데이트 한다
 *
 *모든 4개의 역을 통과한 후 마지막 결과를 열차의 최대 인원인 10000과 비교하여
 *작은 수를 출력한다.
 *
 *
 */


#include <iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int Result = 0;
	int NumOfPeple = 0;
	for (int i = 0; i < 4; i++)
	{
		int NumOfGetOff = 0;
		int NumOfGetOn = 0;

		cin >> NumOfGetOff >> NumOfGetOn;

		NumOfPeple -= NumOfGetOff;
		NumOfPeple += NumOfGetOn;
		Result = max(Result, NumOfPeple);
	}

	cout << min(Result, 10000);
	return 0;
}