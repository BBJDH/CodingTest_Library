/*
 *10162 - 전자레인지
 *
 *거스름돈계산과 풀이 방식이 동일하다.
 *
 *입력받은 시간은 초단위 이므로
 *
 *각 A버튼 B버튼 C버튼을 300,60,10 초로 매핑하여 생각한다.
 *
 *그리고 주어진 수를 300, 60, 10 순으로 나누어나간다
 *
 *만약 10까지 빼고도 남은 초수가 0이 아니라면 -1
 *
 *0이라면 위에서 뺴내진 각 버튼 카운트 총합을 출력
 *
 *
 *
 *개선된 방안
 *
 *생각해보니 버튼 누르는 작업을 while문으로 한번씩 뺄필요가 없었다.
 *
 *그냥 조건문으로 버튼에 해당하는 초보다 크다면
 *몫을 구하고 그만큼 기록해주면 된다.
 *
 */

#include <iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int Button[3] = { 300,60,10 };
	int Count[3] = {};


	int inputTime = 0;
	cin >> inputTime;
	for (int i = 0; i < 3; i++)
	{
		if (inputTime >= Button[i])
		{
			int mul = inputTime / Button[i];
			inputTime -= mul * Button[i];
			Count[i] = mul;
		}
	}

	if (inputTime != 0)
	{
		cout << -1;
		return 0;
	}


	cout << Count[0] << " " << Count[1] << " " << Count[2];


	return 0;
}