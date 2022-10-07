/*
6064 - ī�� �޷�

10 12 3 9

10���� 3�� ������ ���
3 13 23 33 ...

12���� 9�� ������ ���
9 21 33 .. ������ 33�� ��

13 11 5 6

13���� 5�� ������ ���
5 18 31 44 57 70 83 96
11�� 6�� ������ ���
6 17 28 39 50 61 72 83
83�� �����̹Ƿ� 83 ���

�� ������ ���� M�� N�� �ּҰ������ �� �޷��� ������ ���� �ȴ�

������ M�̳� N �� �ϳ��� �������� �Ͽ� X �Ǵ� Y�� ���۳⵵�� �ϰ�
X�� M, Y�� N�� ���ذ��� XY �ذ� �������� Ž���Ѵ�
�����ǳ��� ������ ��ã�Ҵٸ� -1�� ���

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
