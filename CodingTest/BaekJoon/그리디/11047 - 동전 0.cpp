/*
���� ū �������� �ֱ⸦ �õ� �ݾ��� �ʰ��ȴٸ� �������� ���ٸ�
�ٽ� ū ���κ��� ���ذ�
�ݾ��� �������ٸ� Ż��, ���μ��� ��ȯ(�׻� ������ ���μ��� ����)

�����غ��� �׳� �������� �������ε� �ذ� ����
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
