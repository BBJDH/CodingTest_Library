/*
2143 - �� �迭�� ��

�� �迭�� �Է¹ް� �ι迭�� ���Ͽ� ��� ������ �κ����� �����ش�

A B �� �迭���� DP�� �ϴµ� (1000)^2 �� �õ��ϰԵȴ�

DP_A �迭�� �����Ͽ� ���ĵ� DP_B���� Target - DP_A���� ��ŭ�� ã�´�

������ DP_A�� �ش��� �Ǵ� ���� ���Ұ� ������ ������ �� �����Ƿ�

������ ��ġ���� �ʰ����� ã�Ƽ� �� ������ Count�� ���������ش�

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