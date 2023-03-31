/*
 *11403 - ��� ã��
 *
 *�Է� ���� ���� �迭�� �״�� ����Ͽ�
 *
 *�Է¹��� ���� ������ SIze ����
 *0~ Size �� ���������� ���� DFS�� �����Ѵ�.
 *
 *�����ϸ鼭 �湮�ϰ� �Ǵ� ������ Visit���� �迭�� ó���Ѵ�.(Visit[������][���� ������ ����])
 *(Ȥ�� 1���� �迭�� �Ͽ� �� DFS���� �� ����ϰ� ���۽� �ʱ�ȭ ���־ �ȴ�.)
 *
 *�̹� �湮�� ������ �ٽ� �湮�ϰ� �Ǵ� ��ȯ�� �߻��Ѵٸ� Visit[������][���� ������ ����]
 *���� �̹� �湮ó���� �Ǿ����Ƿ� ���̻� Ž���� �������� �ʴ´�.
 *
 *������ Visit�� ��� ������ְ� ���α׷��� �����Ѵ�.
 *
 *�÷��̵�-������ ���� Ǫ�� ����� �����ϴ�
 *
 */

#include <iostream>

using namespace std;

int Edges[100][100]{};
int Visit[100][100]{};
int Size = 0;


void DFS(int const CurrentPos, int const& Start)
{
	for (int Dest = 0; Dest < Size; Dest++)
	{
		if (Edges[CurrentPos][Dest] == 1 and Visit[Start][Dest] == 0)
		{
			Visit[Start][Dest] = 1;
			DFS(Dest, Start);
		}
	}
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> Size;

	for (int Src = 0; Src < Size; Src++)
	{
		for (int Dest = 0; Dest < Size; Dest++)
		{
			cin >> Edges[Src][Dest];
		}
	}

	for (int i = 0; i < Size; i++)
	{
		DFS(i, i);
	}

	for (int Src = 0; Src < Size; Src++)
	{
		for (int Dest = 0; Dest < Size; Dest++)
		{
			cout << Visit[Src][Dest] << " ";
		}
		cout << "\n";
	}

	return 0;
}