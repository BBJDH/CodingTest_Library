/*
 *2231 - 분해합
 *
 *입력이 백만까지의 자연수로 제한되므로
 *
 *브루트포스로 풀이 가능하다.
 *
 *1부터 시작해 백만까지 생성자로서 입력받은 수가 만들어지는지 검사한다.
 *
 *만약 생성에 성공한다면 해당 수를 출력 후 종료
 *
 *백만까지 탐색에 실패했다면 0을 출력 후 종료한다.
 *
 *
 */

#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0, Result = 0;
	cin >> N;

	for (int i = 1; i <= 1000000; i++)
	{
		int MakeNum = i;
		int Candidate = i;
		while (Candidate)
		{
			MakeNum += Candidate % 10;
			Candidate /= 10;
		}
		if (MakeNum == N)
		{
			cout << i;
			return 0;
		}
	}
	cout << 0;
	return 0;
}