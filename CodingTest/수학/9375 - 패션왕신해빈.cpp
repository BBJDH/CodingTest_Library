
/*
9375 - �мǿ� ���غ�

���� ���� ���� ��츦 �����Ͽ� ����� ���� ���

���� ī�װ��� �������� 3 2 3 �̶��
���� �Ȱ� ��츦 �����Ͽ� 4 3 4 �� ����Ͽ� 4*3*4 -1�� ���
*/
#include<iostream>
#include<map>
#include<string>
using namespace std;


map<string, int> Cloths{};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int TestCase = 0;
	cin >> TestCase;
	while (TestCase--)
	{
		Cloths.clear();
		int Size = 0;
		cin >> Size;
		while (Size--)
		{
			string Name{};
			string InputCategory{};
			cin >> Name >> InputCategory;
			Cloths[InputCategory]++;
		}
		int Mul = 1;
		for (auto const& Elem : Cloths)
			Mul *= (Elem.second + 1);
		cout << Mul - 1 << "\n";
	}

	return 0;
}
