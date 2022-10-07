
/*
10989 - 수 정렬하기 3

N개의 수를 모두 저장한다면 메모리 초과가 발생한다
수는 10000이하의 자연수임을 힌트로
10001개 짜리 배열을 만들고 입력된 갯수만큼 출력해주면 된다
*/
#include<iostream>
#include<algorithm>
using namespace std;

int Arr[10001]{};
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	int  Size = 0;

	cin >> Size;

	while (Size--)
	{
		int  InputNum = 0;
		cin >> InputNum;
		Arr[InputNum]++;
	}

	for (int i = 0; i < 10001; i++)
	{
		for (int j = 0; j < Arr[i]; j++)
		{
			cout << i << "\n";
		}
	}

	return 0;
}