/*
11650 - ��ǥ �����ϱ�
�⺻���� ���� �켱������ Ŀ���� �ϴ� ����

*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct _int2
{
	int X;
	int Y;
};

vector<_int2> Points{};

bool Compare(_int2 const& First, _int2 const& Second)
{
	if (First.X == Second.X)
		return First.Y < Second.Y;
	return First.X < Second.X;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int InputCount = 0;
	cin >> InputCount;

	while (InputCount--)
	{
		_int2 InputPoint{};
		cin >> InputPoint.X >> InputPoint.Y;
		Points.push_back(InputPoint);
	}
	sort(Points.begin(), Points.end(), Compare);
	for (size_t i = 0; i < Points.size(); i++)
	{
		cout << Points[i].X << " " << Points[i].Y << "\n";
	}

	return 0;
}
