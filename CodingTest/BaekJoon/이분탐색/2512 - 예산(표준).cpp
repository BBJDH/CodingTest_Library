/*
 *2512 - ����
 *
 *���� �̺�Ž���� �����Ͽ� �ذ��ߴ�.
 *
 *����Ž�� �ݺ����� ������ BinarySearch �Լ���
 *�ȿ��� IsCorrect�Լ��� ���� �����Ѵٸ� Left�� ��������(Mid ����)
 *�ȿ��� IsCorrent�Լ��� �������� ���ߴٸ� RIght�� �����´�(Mid ����)
 *
 *���� �ݺ������� Left�� Right�� ���̰� 1�� ������ Ž���Ͽ�
 *ã���� Left�� ������
 *
 *
 */


#include <iostream>
#include <vector>

using namespace std;

bool IsCorrect(int const Mid, vector<int> const Target, int TotalInCome)
{
	//���ϴ� ������ ���� �ϴ��� �˻�

	for (int const Elem : Target)
	{


		if (Elem > Mid)
		{
			TotalInCome -= Mid;
		}
		else
		{
			TotalInCome -= Elem;
		}
	}
	if (TotalInCome < 0)
	{
		return false;
	}
	return true;
}


void BinarySearch(int const Start, int const End, vector<int> const Target, int const TotalInCome)
{
	//Left �� Right �� Ž�� ���� ������ �����Ѵ�
	int Left = Start - 1;
	int Right = End + 1;
	int Mid = 0;			//Mid�� �ݺ��� �ȿ��� �缳��

	while (Left + 1 < Right)
	{
		Mid = (Left + Right) / 2;
		if (IsCorrect(Mid, Target, TotalInCome))
		{
			Left = Mid;
		}
		else
		{
			Right = Mid;
		}
	}
	cout << Left;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	vector<int> City{};
	int NumOfCity = 0;
	int TotalInCome = 0;
	int End = 0;
	cin >> NumOfCity;
	while (NumOfCity--)
	{
		int InputNum = 0;
		cin >> InputNum;
		City.push_back(InputNum);
		End = max(End, InputNum);
	}
	cin >> TotalInCome;

	BinarySearch(1, End, City, TotalInCome);
	return 0;
}