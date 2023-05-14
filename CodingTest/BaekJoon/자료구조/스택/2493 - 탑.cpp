/*
 *
 *2493 - 탑
 *
 *
 *각 탑들을 배열로 저장해 요구사항대로 하나씩 반복문을 통해 확인한다면
 *탑이 50만개 이면서 찾아야할 송신탑이 가장 끝에 있는 경우를 계산해보면
 *125,000,000,000 (50만 * 50만 /2) 의 비용이 발생한다. (시간초과 발생)
 *
 *따라서 위의 방법이 아닌 스택을 이용해 풀이한다.
 *
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct _int2
{
	int Index;
	int Height;
};

//요구사항대로 구현(시간초과 발생!)
int GetReceivingTower_Implement(vector<int> const& Tops, int const Src)
{
	int Dest = Src - 1;
	while (Dest != -1)
	{
		if (Tops[Src] <= Tops[Dest])
		{
			return Dest + 1;
		}
		Dest--;
	}
	return 0;
}

//스택을 이용한 풀이 
void Solution(vector<int> const& Tops)
{
	stack<_int2> ReceivingTower{};
	for (int i = 0; i < Tops.size(); i++)
	{
		while (!ReceivingTower.empty())
		{
			if (ReceivingTower.top().Height < Tops[i])
			{
				ReceivingTower.pop();
			}
			else
			{
				cout << ReceivingTower.top().Index + 1 << " ";
				ReceivingTower.push({ i,Tops[i] });
				break;
			}
		}
		if (ReceivingTower.empty())
		{
			ReceivingTower.push({ i, Tops[i] });
			cout << "0 ";
		}
	}
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);


	int CountOfTop = 0;
	vector<int> Tops{};
	cin >> CountOfTop;
	while (CountOfTop--)
	{
		int InputNum = 0;
		cin >> InputNum;
		Tops.push_back(InputNum);
	}
	Solution(Tops);


	return 0;
}