/*

10768 - Ư���� ��

���� ���� ������ ����ü�� ����� ������ �����ε��� ���� �����ߴ�.

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