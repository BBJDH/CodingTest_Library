/*
 *
 *7568 - 덩치
 *
 *정수형 두개짜리 구조체를 만든 후
 *
 *문제의 요구사항에 맞게 연산자 오버로딩을 해준다
 *
 *이후 해당 사람기준으로 N^2으로 탐색하여
 *
 *해당 사람보다 큰사람이 존재하는 수만큼 카운트하여
 *+1만큼 출력한다.
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