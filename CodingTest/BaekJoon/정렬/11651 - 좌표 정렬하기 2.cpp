/*
 *11651 - ��ǥ �����ϱ� 2
 *
 *������ �䱸���� �״��
 *�ε�ȣ ������ �����ε��� �̿��� �������ְ�
 *���� �� ����Ѵ�.
 *
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct _int2
{
	int X;
	int Y;
};
bool operator>(_int2 const& Left, _int2 const& Right)
{
	if (Left.Y == Right.Y)
		return Left.X > Right.X;
	return Left.Y > Right.Y;
}

bool operator<(_int2 const& Left, _int2 const& Right)
{
	if (Left.Y == Right.Y)
		return Left.X < Right.X;
	return Left.Y < Right.Y;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;
	vector<_int2> Coordinates{};
	cin >> N;
	while (N--)
	{
		_int2 Input{};
		cin >> Input.X >> Input.Y;
		Coordinates.push_back(Input);
	}
	sort(Coordinates.begin(), Coordinates.end());

	for (_int2 const& elem : Coordinates)
	{
		cout << elem.X << " " << elem.Y << "\n";
	}

	return 0;
}