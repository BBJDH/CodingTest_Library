/*
 *2522 - 별 찍기 - 12
 *
 *문제의 요구사항대로 구현한다.
 *
 *입력받은 N에 대하여 별의 개수를 기준으로 반복문을 작성했다
 *
 *따라서 N-(별의 갯수)만큼 공백의 출력을 먼저 진행하고,
 *이후 별의 갯수만큼 출력한다.
 *
 *이것을 다시 거꾸로 N-1부터 출력한다.
 *
 *
 */

#include <iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N = 0;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{

		for (int Star = N - i; Star > 0; Star--)
		{
			cout << " ";
		}
		for (int Blank = 0; Blank < i; Blank++)
		{
			cout << "*";
		}
		cout << "\n";
	}

	for (int i = N - 1; i > 0; i--)
	{

		for (int Star = N - i; Star > 0; Star--)
		{
			cout << " ";
		}
		for (int Blank = 0; Blank < i; Blank++)
		{
			cout << "*";
		}
		cout << "\n";
	}

	return 0;
}