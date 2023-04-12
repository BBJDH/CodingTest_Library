/*
 *10988 - 팰린드롬인지 확인하기
 *
 *
 *문제의 요구사항대로 입력받은 문자열이 좌우 대칭인지 확인한다.
 *
 *가운데에 있는 문자는 확인할 필요가 없으므로
 *
 *입력받은 문자열 [0번인덱스] == [끝인덱스-0]
 *입력받은 문자열 [1번인덱스] == [끝인덱스-1]
 *
 *를 비교해 준다.
 *
 *비교도중 다른경우가 발생한다면 0을 출력하고 종료
 *반복문을 사이즈의 반까지 모두 돌았다면 1을 출력하고 종료한다.
 *
 *
 *
 */

#include<iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	string InputStr{};

	cin >> InputStr;

	for (int i = 0; i < InputStr.size() / 2; i++)
	{
		if (InputStr[i] != InputStr[InputStr.size() - i - 1])
		{
			cout << 0;
			return 0;
		}
	}
	cout << 1;

	return 0;
}