/*
1904 - 01타일
1 - 1	-1
2 - 00, 11	-2
3 - 001 100 111	-3
4 - 0000 0011 1100 1111 1001	-5
5 - 00001 00111 11001 11111 10011 10000 11100 00100	-8
6 - 000011 001111 110011 111111 100111 100001 111001 001001
	100001 110000 111100 100100 001100	-13
n = (n-1) + (n-2)  규칙을 가진다
*/
#include<iostream>

using namespace std;

int DP[1000001]{};

void Solution()
{
	DP[1] = 1;
	DP[2] = 2;

	for (int i = 3; i < 1000001; i++)
		DP[i] = (DP[i - 2] + DP[i - 1]) % 15746;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int TargetNum = 0;
	cin >> TargetNum;
	Solution();
	printf("%d", DP[TargetNum]);

	return 0;
}