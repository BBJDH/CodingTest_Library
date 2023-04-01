/*
 *2490 - 윷놀이
 *
 *0의 갯수만으로 결과를 출력 가능하다
 *
 *0개 - 모, 1개 - 도, 2개 - 개, 3개 - 걸, 4개 - 윷
 *
 *이렇게 매핑된 배열을 생성하고
 *
 *주어진 네개의 숫자중 0의 갯수를 카운팅하여
 *
 *배열의 인덱스로 매핑된 결과를 출력한다.
 *
 */

#include <iostream>

using namespace std;

char ResultOfCount[5] = { 'E','A','B','C','D' };

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 3; i++)
	{
		int CountOfZero = 0;
		for (int i = 0; i < 4; i++)
		{
			int InputNum = 0;
			cin >> InputNum;
			if (InputNum == 0)
			{
				CountOfZero++;
			}
		}
		cout << ResultOfCount[CountOfZero] << "\n";
	}

	return 0;
}