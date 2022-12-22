/*
 *11056 - 두 부분 문자열
 *
 *두 문자열을 LCS 한 결과의 길이를
 *비교하는 두번째 문자열 길이 - 부분 문자열 길이 만큼을 구해
 *
 *원본 문자열 길이에 더한 값을 출력한다.
 *
 *예제를 통해 풀어본다면
 *
 *
 *LCS 과정 설명
 *
 *2중 포문을 수행하며 각 문자에대한 비교를 시행
 *
 *문자가 일치한다면 이전 최장길이 부분수열의 위치를 나타내는
 *왼쪽 대각선의 누적값+1을 기록하고
 *
 *문자가 일치하지 않는다면 왼쪽과 오른쪽 누적값의 최대값을 보존한다
 *
 *이렇게 문자열 끝까지 비교를 완료한 후 제일 우측 하단의 누적값이
 *
 *두 문자열의 최장길이 부분 수열이다.
 *
 *LCS 결과
 *
 *    b a e k j o o n
 *  0 1 2 3 4 5 6 7 8
 *h 0 0 0 0 0 0 0 0 0
 *o 1 0 0 0 0 0 1 1 1
 *n 2 0 0 0 0 0 1 1 2
 *g 3 0 0 0 0 0 1 1 2
 *j 4 0 0 0 0 1 1 1 2
 *u 5 0 0 0 0 1 1 1 2
 *n 6 0 0 0 0 1 1 1 2
 *
 *가 나오므로 최장길이 부분수열의 길이는 2이다
 *
 *문제의 요구사항은 두 문자열을 포함하는 최소 길이의 문자열이 필요하므로
 *
 *원본인 baekjoon 에 lcs에서 구한 2의 길이는 포함되어 있고,
 *hongjun의 길이 7에서 2를 뺀 다섯개 만큼의 문자를 baekjoon에 순서에 맞춰 끼워넣는다면,
 *
 *문제가 요구하는 가장 짧은 길이의 S가 된다
 *
 *즉 baekjoon의 길이 8에 7-2를 더해 13이 답이 된다.
 *
 *
 *
 *
 *
 *
 */


#include <iostream>

using namespace std;

int LCS_Arr[1001][1001]{};
string SrcStr{};
string CmpStr{};

void LCS()
{
	for (int y = 0; y < CmpStr.size(); y++)
	{
		for (int x = 0; x < SrcStr.size(); x++)
		{
			if (SrcStr[x] == CmpStr[y])
			{
				LCS_Arr[y + 1][x + 1] = LCS_Arr[y][x] + 1;
				continue;
			}
			LCS_Arr[y + 1][x + 1] = max(LCS_Arr[y][x + 1], LCS_Arr[y + 1][x]);
		}
	}
}

int main()
{
	cin.tie(NULL);

	ios_base::sync_with_stdio(false);

	cin >> SrcStr >> CmpStr;

	LCS();

	cout << SrcStr.size() + CmpStr.size() - LCS_Arr[CmpStr.size()][SrcStr.size()];

	return 0;
}