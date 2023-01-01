/*

10768 - 특별한 날

월과 일을 가지는 구조체를 만들고 연산자 오버로딩을 통해 구현했다.

*/

#include <iostream>

using namespace std;


struct MMDD
{
	int Month;
	int Day;
};

bool operator> (MMDD const& Left, MMDD const& Right)
{
	if (Left.Month == Right.Month)
		return Left.Day > Right.Day;

	return Left.Month > Right.Month;
}
bool operator< (MMDD const& Left, MMDD const& Right)
{
	if (Left.Month == Right.Month)
		return Left.Day < Right.Day;

	return Left.Month < Right.Month;
}
bool operator== (MMDD const& Left, MMDD const& Right)
{
	return Left.Month == Right.Month and Left.Day == Right.Day;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	MMDD input{};
	MMDD target{ 2,18 };
	cin >> input.Month >> input.Day;

	if (input == target)
		cout << "Special";
	else if (input > target)
		cout << "After";
	else
		cout << "Before";


	return 0;
}