/*
 *11286 - 절댓값 힙
 *
 *
 *요구사항에 맞게 우선순위 큐를 구성해 프로그램을 작성했다.
 *
 *크기를 절대값을 우선으로 비교하고 동일한 절대값이라면 정수의 크기를 비교할 수 있게
 *
 *정수 두개를 가지는 자료형을 구조체로 작성한다.
 *이를 비교할 연산자 오버로딩을 문제의 요구사항과 동일하게 작성했다.
 *
 *이후 오름차순으로 우선순위 큐에 넣도록 만들고
 *
 *요구사항대로 Push와 Print 및 Pop연산을 해주면 프로그램이 완성된다.
 *
 *
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace	std;

struct _int2
{
	int Num;
	int AbsNum;
};

bool operator>(_int2 const& Left, _int2 const& Right)
{
	if (Left.AbsNum == Right.AbsNum)
	{
		return Left.Num > Right.Num;
	}

	return Left.AbsNum > Right.AbsNum;
}
bool operator<(_int2 const& Left, _int2 const& Right)
{
	if (Left.AbsNum == Right.AbsNum)
	{
		return Left.Num < Right.Num;
	}

	return Left.AbsNum < Right.AbsNum;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	priority_queue<_int2, vector<_int2>, greater<>> HeapOfMinAbs{};

	int CountOfInput = 0;
	cin >> CountOfInput;
	while (CountOfInput--)
	{
		int InputNum = 0;
		cin >> InputNum;
		if (InputNum == 0)
		{
			if (HeapOfMinAbs.empty())
			{
				cout << 0 << "\n";
				continue;
			}
			cout << HeapOfMinAbs.top().Num << "\n";
			HeapOfMinAbs.pop();
			continue;
		}

		HeapOfMinAbs.push({ InputNum ,abs(InputNum) });
	}

	return 0;
}