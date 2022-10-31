/*
2143 - 두 배열의 합

두 배열을 입력받고 두배열에 대하여 모든 가능한 부분합을 구해준다

A B 각 배열마다 DP를 하는데 (1000)^2 을 시도하게된다

DP_A 배열을 접근하여 정렬된 DP_B에서 Target - DP_A원소 만큼을 찾는다

문제는 DP_A에 해답이 되는 동일 원소가 여러개 존재할 수 있으므로

최초의 일치값과 초과값을 찾아서 뺀 갯수를 Count에 증가시켜준다

*/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> A{};
vector<int> B{};
vector<int> DP_A{};
vector<int> DP_B{};

int TargetNum = 0;

void SearchTargetNum()
{
	long long Count = 0;
	sort(DP_B.begin(), DP_B.end());

	for (auto const& Elem : DP_A)
	{
		int const Diff = TargetNum - Elem;

		auto Start = lower_bound(DP_B.begin(), DP_B.end(), Diff);
		auto End = upper_bound(DP_B.begin(), DP_B.end(), Diff);
		Count += static_cast<long long>(End - Start);
	}
	cout << Count;
}

void MakeDP()
{
	for (int i = 0; i < A.size(); i++)
	{
		int Sum = 0;
		for (int j = i; j < A.size(); j++)
		{
			Sum += A[j];
			DP_A.emplace_back(Sum);
		}
	}
	for (int i = 0; i < B.size(); i++)
	{
		int Sum = 0;
		for (int j = i; j < B.size(); j++)
		{
			Sum += B[j];
			DP_B.emplace_back(Sum);
		}
	}
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> TargetNum;

	int Sum = 0;
	int ASize = 0;
	cin >> ASize;

	while (ASize--)
	{
		int InputNum = 0;
		cin >> InputNum;
		A.emplace_back(InputNum);
	}
	Sum = 0;
	int BSize = 0;
	cin >> BSize;

	while (BSize--)
	{
		int InputNum = 0;
		cin >> InputNum;
		B.emplace_back(InputNum);
	}
	MakeDP();
	SearchTargetNum();
	return 0;
}