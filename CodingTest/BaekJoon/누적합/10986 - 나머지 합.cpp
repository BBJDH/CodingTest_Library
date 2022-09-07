/*
10986 - 나머지 합

6 2
1 3 3 1 1 3
를 예시로 생각해보자

누적합을 구해보면
1 4 7 8 9 12 에서 해가 나오는 경우를 뽑아보면
1, 7, 9		이 수들에서 구간을 구하면 반드시 합이 M으로 나누어진다
4, 8, 12	이 수들에서 구간을 구하면 반드시 합이 M으로 나누어진다
위의 방법으로 모든 구간의 합을 먼저 구한다
다시 정리해보면, {1, 7, 9}(나머지 1), {4, 8, 12}(나머지0)
나머지가 같은 숫자에 대해 구간을 뽑는다 나머지의 갯수 컴비네이션 2

따라서 순열순으로 더한 누적합의 나머지가 같은 구간을 카운팅 해주어야 하므로(앞서 말했듯 구간의 길이는 중요하지 않다)

이후 단 한개의 원소로 나누어지는 경우를 추산
입력 받을때 미리 구간 합 마다 0이 되는경우를 카운팅 해준다

출력할 값과 더해지는 수들은 범위가 int를 초과함에 유의
*/
#include<iostream>
#include<vector>
using namespace std;

vector<long long> Nums{};

int ModNum = 0;
long long Count = 0;
void Solution()
{

	for (int i = 0; i < Nums.size(); i++)
	{
		Count += (Nums[i] * (Nums[i] - 1)) / 2;
	}
	cout << Count;

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int NumSize = 0;

	cin >> NumSize >> ModNum;
	long long Sum = 0;
	Nums.resize(ModNum);

	while (NumSize--)
	{
		int InputNum = 0;
		cin >> InputNum;
		Sum += InputNum;
		Nums[Sum % ModNum]++;
		if (Sum % ModNum == 0)
			Count++;
	}
	Solution();

	return 0;
}