/*
 *10610 - 30
 *
 *처음에는 모든 수에 대해서 작은수로부터 수를 만들어가며 완전탐색하고자 하였다.
 *하지만 입력 받는 수의 갯수는 10의5승으로  10만개이다 시간복잡도도 상당하고
 *10만개자릿수를 담아 정수로 생성할 수도 없다.
 *
 *때문에 어떤 규칙이 있을까 생각해보다가 결국 규칙을 찾아보게 되었다..
 *
 *결론은 30의 배수가 가능한 명확한 조건이 존재한다.
 *
 *먼저 문자열속에 0이 한개라도 존재해야 하며,
 *각 모든 자릿수의 합이 3의 배수여야 한다
 *
 *해당 조건이 만족한다면 이 숫자들을 내림차순 정렬하여 30의 배수를 만들 수 있다.
 *(위키 백과의 배수 판정법을 참고하자.)
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string inputStr{};
	bool IsInZero = false;
	int Sum = 0;
	vector<int>Nums{};
	cin >> inputStr;

	for (char const elem : inputStr)
	{
		if (elem == '0')
			IsInZero = true;

		int parseNum = elem - '0';
		Sum += parseNum;
		Nums.push_back(parseNum);
	}

	if (IsInZero == false or Sum % 3 != 0)
	{
		cout << -1;
		return 0;
	}
	sort(Nums.begin(), Nums.end(), greater<>());

	for (int const elem : Nums)
	{
		cout << elem;
	}

	return 0;
}