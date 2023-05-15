/*
 * 1922 - ��Ʈ��ũ ����
 *
 * ũ�罺Į�� �̿��� �ּҽ��д�Ʈ���� ����� �ذ��ߴ�.
 *
 *
 *������ ũ�� ������,
 *- ��� ��ǻ�ʹ� ����Ǿ�� �Ѵ�.
 *- �ּҺ������ ����Ǿ�� �Ѵ�.
 *
 * �̿� ���� �� ��ǻ�Ͱ��� ���� ��뿡 ���� �׸���� �����Ѵ�.
 *
 * _int3 �ڷ����� ����� Src���� Dest�� �����ϴ� ��� Weight�� ���ϴ�
 *
 * �ε�ȣ ������ �Լ��� �����ε��Ѵ�.
 *
 * ��� Edges�� _int3���� �Է¹޾� �迭�� �����ϰ�, ���� �ε�ȣ�� �̿��� �����Ѵ�.
 *
 * ���� �ּ� ����� �������� ���� �ϳ��� Parent�� �����ִ� �۾��� �����Ѵ�.
 *
 * ���� Src�� Dest�� Parent�� �����ϴٸ� �̹� ����� ���̹Ƿ� ����� �ջ����� �ʴ´�.
 * (�ڱ� �ڽ������� �����ΰ�쵵 Parent�� �����ϰ� �ǹǷ� �ջ���� �ʴ´�.)
 *
 * ��� Edge�� ���� ���� ������ �ݺ��ϰ� �Ϸ� �� TotalWeight�� ����Ѵ�.
 *
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct _int3
{
	int Src;
	int Dest;
	int Weight;
};

bool operator>(_int3 const& Left, _int3 const& Right)
{
	return Left.Weight > Right.Weight;
}
bool operator<(_int3 const& Left, _int3 const& Right)
{
	return Left.Weight < Right.Weight;
}


int Parent[1001]{};

int GetParent(int const Child)
{
	if (Parent[Child] == Child)
	{
		return Child;
	}
	return Parent[Child] = GetParent(Parent[Child]);
}

void Solution(vector<_int3>& Edges)
{
	int TotalWeight = 0;

	sort(Edges.begin(), Edges.end());

	for (_int3 const Elem : Edges)
	{
		int const SrcParent = GetParent(Elem.Src);
		int const DestParent = GetParent(Elem.Dest);

		if (SrcParent != DestParent)
		{
			Parent[DestParent] = SrcParent;
			TotalWeight = TotalWeight + Elem.Weight;
		}
	}
	cout << TotalWeight;
}


int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	vector<_int3>Edges{};
	int NumOfComputer = 0, NumOfEdges = 0;

	cin >> NumOfComputer >> NumOfEdges;

	for (int i = 1; i <= NumOfComputer; i++)
	{
		Parent[i] = i;
	}

	while (NumOfEdges--)
	{
		_int3 Input{};
		cin >> Input.Src >> Input.Dest >> Input.Weight;
		Edges.push_back(Input);
	}
	Solution(Edges);
	return 0;
}