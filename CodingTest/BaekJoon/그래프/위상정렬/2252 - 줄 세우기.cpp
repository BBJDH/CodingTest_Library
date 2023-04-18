/*
 *
 *2252 - �� �����
 *
 *�������ķ� Ǯ�� �����ϴ�.
 *
 *�Է¹޴� Edges�� �Բ� �������� InDegree�� ����صд�.
 *
 *���� ���������� 0�� ���������� ť�� �����Ѵ�.(������ �̿��ص� �ȴ�.)
 *
 *���� ������ ������ ù ��忡�� ����� ���� ������ ������������ -1 ���ش�
 *
 *-1 ���� ���Ӱ� ���������� 0�̵� ������ ť�� �����Ѵ�.
 *
 *���� ������ �ݺ��� N���� ��尡 ������ ���´ٸ� ������ ������ ���̰�,
 *
 *�� ���� ť�� ��ٸ� ��ȯ�� �߻��� ���̴�.
 *
 *ť ��� ������ ����Ѵٸ� ������ ���� ����� ���� �� �ִ�.
 *
 */

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<int> InDegree{};
vector<vector<int>> Edges{};
int Size = 0;

void Solution()
{
	//stack<int> ZeroInDegree{};	//���� ���
	queue<int> ZeroInDegree{};
	for (int i = 1; i < InDegree.size(); i++)
	{
		if (InDegree[i] == 0)
		{
			ZeroInDegree.push(i);
		}
	}

	//������ ������ ����Ƿ��� ��Ȯ�� N���� ��尡 �������;� ��
	for (int i = 0; i < Size; i++)
	{

		if (ZeroInDegree.empty())
		{
			cout << "��ȯ�߻�\n";
			break;
		}
		//���
		//int const NumToPrint = ZeroInDegree.top();	//���� ���
		int const NumToPrint = ZeroInDegree.front();
		ZeroInDegree.pop();
		cout << NumToPrint << " ";
		for (int const elem : Edges[NumToPrint])
		{
			InDegree[elem]--;
			if (InDegree[elem] == 0)
			{
				ZeroInDegree.push(elem);
			}
		}
	}
}


int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int CountOfEdges = 0;
	cin >> Size >> CountOfEdges;
	Edges.resize(Size + 1);
	InDegree.resize(Size + 1);
	while (CountOfEdges--)
	{
		int Start = 0, Dest = 0;

		cin >> Start >> Dest;
		Edges[Start].push_back(Dest);
		InDegree[Dest]++;
	}

	Solution();


	return 0;
}