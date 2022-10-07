/*
6064 - 카잉 달력

10 12 3 9

10으로 3이 나오는 경우
3 13 23 33 ...

12으로 9가 나오는 경우
9 21 33 .. 공통이 33이 답

13 11 5 6

13으로 5가 나오는 경우
5 18 31 44 57 70 83 96
11로 6이 나오는 경우
6 17 28 39 50 61 72 83
83이 공통이므로 83 출력

두 임의의 연도 M과 N의 최소공배수는 이 달력의 종말의 날이 된다

때문에 M이나 N 중 하나를 기준으로 하여 X 또는 Y를 시작년도로 하고
X면 M, Y면 N을 더해가며 XY 해가 나오는지 탐색한다
종말의날을 지나도 못찾았다면 -1을 출력

*/
#include<iostream>
#include<set>

using namespace std;


int M = 0, N = 0, X = 0, Y = 0;
set<int> M_List{};

int GCD(int Bigger, int Smaller)
{
	while (Smaller != 0)
	{
		int NextSmaller = Bigger % Smaller;
		Bigger = Smaller;
		Smaller = NextSmaller;
	}
	return Bigger;
}

int MakeYear(int Year, int ModYear)
{
	int result = Year % ModYear;
	if (result == 0)
		result = ModYear;
	return result;
}

void Solution()
{
	int const Max = max(M, N);
	int const Min = min(M, N);
	int const EndYear = M * N / GCD(Max, Min);

	int CheckYear = X;
	int Year_N = MakeYear(CheckYear, N);
	while (Year_N != Y)
	{
		CheckYear += M;
		if (CheckYear > EndYear)
		{
			cout << -1 << "\n";
			return;
		}
		Year_N = MakeYear(CheckYear, N);
	}

	cout << CheckYear << "\n";

}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	int TestCase = 0;
	cin >> TestCase;
	while (TestCase--)
	{
		cin >> M >> N >> X >> Y;
		Solution();
	}
	return 0;
}
