/*
 *
 *7568 - ��ġ
 *
 *������ �ΰ�¥�� ����ü�� ���� ��
 *
 *������ �䱸���׿� �°� ������ �����ε��� ���ش�
 *
 *���� �ش� ����������� N^2���� Ž���Ͽ�
 *
 *�ش� ������� ū����� �����ϴ� ����ŭ ī��Ʈ�Ͽ�
 *+1��ŭ ����Ѵ�.
 *
 *
 */

#include<iostream>
#include <vector>

using namespace std;

struct _int2
{
	int Kg;
	int Height;
};

bool operator>(_int2 const & Left, _int2 const& Right)
{
	return Left.Height > Right.Height and Left.Kg > Right.Kg;
}

bool operator<(_int2 const & Left, _int2 const & Right)
{
	return Left.Height < Right.Height and Left.Kg < Right.Kg;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;
	vector<_int2> People{};
	cin >> N;

	for(int i=0; i<N; i++)
	{
		_int2 Table{};
		cin >> Table.Kg >> Table.Height;
		People.push_back(Table);
	}

	for(int i=0; i< People.size(); i++)
	{
		int Count = 0;
		for(int j=0; j<People.size(); j++)
		{
			if (People[i] < People[j])
				Count++;
		}
		cout << Count+1<<" ";
	}

	return 0;
}