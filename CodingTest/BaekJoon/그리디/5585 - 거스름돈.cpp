/*
 *5585 - 거스름돈
 *
 *그리디로 접근한다 가장 큰돈부터 빼나가면서 카운트를 증가시킨다
 *
 *마지막 1마저 모두 빼내어 진다면 해당 카운트가 최적해가 된다.
 */
#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Coin[6] = { 500,100,50,10,5,1 };
	int N = 0, Index = 0, Count = 0;
	int Change = 0;
	cin >> N;
	Change = 1000 - N;
	while (Index < 6)
	{
		if (Change < Coin[Index])
		{
			Index++;
			continue;
		}
		Change -= Coin[Index];
		Count++;
	}
	cout << Count;

	return 0;
}