/*
가장 큰 동전부터 넣기를 시도 금액이 초과된다면 지나가고 적다면
다시 큰 코인부터 더해감
금액이 같아진다면 탈출, 코인수를 반환(항상 최적의 코인수가 나옴)

종합해보면 그냥 나눗셈과 나머지로도 해결 가능
*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> Coins{};

int N = 0;
int TargetWon = 0;
int CurrentWon = 0;
int CurrentCount = 0;
bool IsSolved = false;

void AddCoin()
{
	while (!IsSolved)
	{
		for (size_t i = Coins.size() - 1; i >= 0; i--)
		{
			if (CurrentWon + Coins[i] == TargetWon)
			{
				cout << CurrentCount + 1;
				IsSolved = true;
				return;
			}
			else if (CurrentWon + Coins[i] < TargetWon)
			{
				CurrentWon += Coins[i];
				CurrentCount++;
				break;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> TargetWon;

	while (N--)
	{
		int InputCoin = 0;
		cin >> InputCoin;
		Coins.push_back(InputCoin);
	}
	AddCoin();

	return 0;
}
