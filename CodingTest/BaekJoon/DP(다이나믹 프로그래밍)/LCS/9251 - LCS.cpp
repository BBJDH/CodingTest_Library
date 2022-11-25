/*
 *9251 - LCS
 *
 *DP로 최장 부분수열의 길이를 저장한다고 생각해보자
 *각 열을 알파벳으로 매칭하여 각 알파펫을 비교한다.
 *DP로 매 행에서 N번째 문자까지 체크한 최대 부분 수열의 길이를 기록한다.
 *DP의 기록 케이스는 둘로 나뉜다
 *각 i번째의 문자를 두번째문자열의 j번째 문자에서 비교할때
 *두 문자가 일치하는 경우, 그렇지 않은 경우 두가지로 나뉜다
 *
 *두 문자가 일치하는 경우 이전 문자에서의 최장길이에 +1해준다, 즉
 *DP[i][j] = DP[i-1][j-1]+1 으로 길이를 하나 늘려 업데이트 해준다
 *DP[i-1][j-1]는 가장 최근 업데이트된 바로 이전문자까지의 최대 길이를 의미한다.
 *
 *두 문자가 일치하지 않는 경우 위의경우를 통해 업데이트된 현재 업데이트 버전의 이전 문자 정보와
 *현재 문자의 이전 업데이트 버전을 비교하여 둘중 큰 수를 기록한다
 *즉 DP[i][j] = max(DP[i-1][j], DP[i][j-1]) 이다
 *
 *이렇게 서로 다른 문자열 길이 만큼 DP를 기록해나간 후
 *맨마지막 DP[size][size]에 가장 큰 부분 수열의 길이가 들어있다.
 */


#include <iostream>
#include <string>
using namespace  std;


int DP[1001][1001]{};


void LCS(string const& First, string const& Second)
{
	for (int i = 0; i < First.size(); i++)
	{
		for (int j = 0; j < Second.size(); j++)
		{
			if (First[i] == Second[j])
				DP[i + 1][j + 1] = DP[i][j] + 1;
			else
				DP[i + 1][j + 1] = max(DP[i + 1][j], DP[i][j + 1]);
		}
	}
	cout << DP[First.size()][Second.size()];
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string firstStr{};
	string secondStr{};

	cin >> firstStr >> secondStr;

	LCS(firstStr, secondStr);

	return 0;
}