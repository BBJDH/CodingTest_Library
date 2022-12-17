/*
 *8983 - ��ɲ�
 *
 *��� �������� ��� ������ ������ ã�°��� �ƴ϶�
 *�ݴ�� ���� ���忡�� ���� �ǰ� �����Ѱ��� �����Ѵ�
 *���� �ִ� y�� ��ǥ��ŭ�� ������ ���� ���� ��ŭ�� �� ��� ��θ� �̺� Ž���Ͽ�
 *��ΰ� �����Ѵٸ� �ش� ������ �ǰݰ����ϴ�.
 *
 *�������
 *�ش� ��ǥ�� 10,3 �̰� �� ����� �����Ÿ��� 4 ��� �Ѵٸ�,
 *
 * 4���� 3�� ���� �¿�� 1��ŭ Ž�� ���������� 10�������� �÷��� ���̳ʽ� 1��ŭ ��θ� Ž���Ѵ�
 * 9~ 11 ���̿� ��ΰ� ���ٸ� �ش� ������ ��Ƴ��´�!
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
int M = 0, AnimalNum = 0, Length = 0;
vector<int> Shooters{};
vector<_int2> Animals{};


bool IsInRange(_int2 const& Pos)
{
	int const searchLength = Length - Pos.Y;

	//0������ ã�� �� �ִ� 
	if (searchLength < 0)
		return false;

	auto iter_start = lower_bound(Shooters.begin(), Shooters.end(), Pos.X - searchLength);

	if (iter_start == Shooters.end())
		return false;

	if (*iter_start > Pos.X + searchLength)
		return false;

	return true;
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> M >> AnimalNum >> Length;

	for (int i = 0; i < M; i++)
	{
		int inputNum = 0;
		cin >> inputNum;
		Shooters.emplace_back(inputNum);
	}
	sort(Shooters.begin(), Shooters.end());
	int count = 0;

	for (int i = 0; i < AnimalNum; i++)
	{
		_int2 inputPos{};

		cin >> inputPos.X >> inputPos.Y;
		if (IsInRange(inputPos))
			count++;
	}

	cout << count;

	return 0;
}