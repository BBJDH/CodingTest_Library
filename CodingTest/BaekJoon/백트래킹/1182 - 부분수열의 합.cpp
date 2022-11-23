/*
 *1182 - 부분수열의 합
 *
 *
 *각 번호에대해 방문 비트를 만들고 백트래킹을 시작
 *이미 방문한 번호는 이미 합산되어있으므로 호출될 필요없고
 *부분 수열의 정의상 left가 지나온 부분의 수는 더해지지 않는다
 *
 */

#include<iostream>
#include <vector>

using namespace std;


vector<int> Sequence{};
int Visit[20]{};

int Size = 0;
int DestNum = 0;
int Count = 0;

void BackTracking(int const StartIndex, int const Sum)
{
	for (int i = StartIndex; i < Size; i++)
	{
		if (Visit[i] == false)
		{
			Visit[i] = true;
			if (Sum + Sequence[i] == DestNum)
				Count++;
			BackTracking(i + 1, Sum + Sequence[i]);
			Visit[i] = false;

		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	cin >> Size >> DestNum;
	int sum = 0;
	for (int i = 0; i < Size; i++)
	{
		int inputNum = 0;
		cin >> inputNum;
		sum += inputNum;
		Sequence.emplace_back(inputNum);
	}
	//입력 및 누적합 구성 완료
	BackTracking(0, 0);
	cout << Count;
	return 0;
}