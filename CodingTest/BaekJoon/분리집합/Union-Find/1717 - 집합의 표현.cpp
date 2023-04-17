/*
 *
 *1717 - ������ ǥ��
 *
 *Union-Find�� ���� Ǯ�� �����ϴ�.
 *
 *ó�� �Է¹޴� N���� ���Ͽ� �ڽ��� �θ�� ������ ������ �迭�� ������ش�.
 *
 *Union[����] = �θ�  �� ���踦 �������� �����.
 *
 *�̰��� ��������� ȣ���Ͽ� �θ� ã�Ƴ�����.
 *
 *�̶� ����Լ��� ������ȯ�� �ֻ��� �θ� ��� ���ҵ��� �θ�� ������Ʈ�ǵ���
 *����Լ��� �����Ѵ�.
 *
 *������ ������ LeftNum�� �ֻ��� �θ� RightNum�� �ֻ��� �θ�� ���������� �����Ѵ�
 *(�� LeftNum�� ������ RightNum�� �������� �������� �ȴ�.)
 *
 *���� ���� �������� ���� ���δ� GetParent�� ���� ������ �ֻ��� �θ� ��������
 *
 *Ȯ�θ� ���ָ� �ȴ�.
 *
 *
 */

#include <iostream>
#include <vector>

using namespace std;


vector<int> Union{};

int GetParent(int const Child)
{
	if (Union[Child] == Child)
	{
		return Child;
	}
	return Union[Child] = GetParent(Union[Child]);
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int Size = 0;
	int TestCase = 0;
	cin >> Size >> TestCase;

	Union.resize(Size + 1);
	for (int i = 0; i < Union.size(); i++)
	{
		Union[i] = i;
	}

	while (TestCase--)
	{
		int Operator = 0, LeftNum = 0, RightNum = 0;

		cin >> Operator >> LeftNum >> RightNum;

		if (Operator == 0)
		{
			Union[GetParent(LeftNum)] = GetParent(RightNum);
			continue;
		}
		if (GetParent(LeftNum) == GetParent(RightNum))
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}


	return 0;
}