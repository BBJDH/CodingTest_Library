/*
 *
 *2493 - ž
 *
 *
 *�� ž���� �迭�� ������ �䱸���״�� �ϳ��� �ݺ����� ���� Ȯ���Ѵٸ�
 *ž�� 50���� �̸鼭 ã�ƾ��� �۽�ž�� ���� ���� �ִ� ��츦 ����غ���
 *125,000,000,000 (50�� * 50�� /2) �� ����� �߻��Ѵ�. (�ð��ʰ� �߻�)
 *
 *���� ���� ����� �ƴ� ������ �̿��� Ǯ���Ѵ�.
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

//�䱸���״�� ����(�ð��ʰ� �߻�!)
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

//������ �̿��� Ǯ�� 
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