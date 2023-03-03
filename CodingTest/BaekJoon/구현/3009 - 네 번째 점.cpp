/*
 *3009 - 네 번째 점
 *
 *X좌표중 한번만 입력받은 정수와
 *
 *Y좌표중 한번만 입력받은 정수를 출력해주면 된다
 *
 *직사각형이기 때문에 4점의 X와 Y 좌표는 2개 이상 존재해야 함이 규칙이다
 *
 *범위가 1000까지이기 때문에 배열을 1001개 만들고
 *입력받은 수에 대하여 ++처리를 한뒤 이 수를 다시 확인하여 1개만 들어온 수를 출력하는 방법이 있다
 *
 *하지만 위의 경우는 가장큰 수가 1000와 작은수 1이라면 1000개를 모두 확인해봐야 하는 비용이 든다
 *
 *때문에 입력받는 수는 3개로 한정되므로 map으로 입력받는 수들을 카운팅 했다.
 *
 *
 */

#include <iostream>
#include <map>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	map<int, int> CoodX{};
	map<int, int> CoodY{};

	for (int i = 0; i < 3; i++)
	{
		int X = 0, Y = 0;
		cin >> X >> Y;
		CoodX[X]++;
		CoodY[Y]++;
	}
	for (pair<int, int> const& elem : CoodX)
	{
		if (elem.second == 1)
		{
			cout << elem.first;
			break;
		}
	}
	cout << " ";
	for (pair<int, int> const& elem : CoodY)
	{
		if (elem.second == 1)
		{
			cout << elem.first;
			break;
		}
	}


	return 0;
}