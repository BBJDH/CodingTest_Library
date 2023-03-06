/*
 *2447 - 별찍기 - 10
 *
 *처음에는 재귀 함수 안에서 0모양을 찍어내려고 접근하였으나,
 *별을 왼쪽에서 오른쪽으로 한 행씩 찍어나가므로
 *
 *2중 for문으로 NxN의 좌표를 순회하며
 *좌표와 크기정보를 입력받아 해당 좌표는 별인지 공백인지
 *판별하는 재귀식을 만들기로 했다.
 *
 *좌표를 1부터 시작하고자 하였으나 이렇게 하면
 *크기가 3인 제로에서는 공백 위치가 {2,2}이지만
 *크기가 9인 제로에서는 {4,4},{5,5},{6,6}으로 그 규칙을 찾아가기 어렵다
 *
 *좌표를 0부터 시작하면
 *크기가 3인 제로에서는 공백 위치가 {1,1}이지만
 *크기가 9인 제로에서는 {3,3},{4,4},{5,5}으로
 *(크기/3)으로 좌표를 나눈 수 % 3으로 같은 규칙이 성립한다.
 *
 *때문에 위의 규칙으로 재귀함수를 작성한다.
 *최초 입력받은 크기/3으로 9개의 구역으로 나누어 판정하고 여기서 공백이 아니라면
 *다시 크기/3으로 진입하여 별인지 공백인지를 판별한다.
 *크기가 0에 도달한다면 별로 확정한다.
 *
 */

#include <iostream>

using namespace std;

bool IsStar(int const X, int const Y, int const BlockSize)
{
	if (BlockSize == 0)
	{
		return true;
	}

	if ((X / BlockSize) % 3 == 1 and (Y / BlockSize) % 3 == 1)
	{
		return false;
	}

	return IsStar(X, Y, BlockSize / 3);
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N = 0;
	//3의 제곱수로 입력
	cin >> N;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (IsStar(x, y, N / 3))
			{
				cout << "*";
				continue;

			}
			cout << " ";
		}
		cout << "\n";
	}

	return 0;
}