/*
ù° �ٿ� ������ ���� N(1 �� N �� 1,000),
������ ���� M(1 �� M �� 10,000),
Ž���� ������ ������ ��ȣ V�� �־�����.
���� M���� �ٿ��� ������ �����ϴ� �� ������ ��ȣ�� �־�����.
� �� ���� ���̿� ���� ���� ������ ���� �� �ִ�.
�Է����� �־����� ������ ������̴�.
*/
#include <iostream>
#include<stack>
#include<queue>
#include <cstring>

using namespace std;
//����, ������, ���۹�ȣ

int Vertexes_Link[1001][1001]{};
int Visit[1001]{};
//stack<int> DFS_Stack;
queue<int> BFS_Queue;


/*


*/
//void DFS_Loop(int const size)
//{
//	//1 2 4 3
//	while (!DFS_Stack.empty())
//	{
//		bool Is_Need_To_Pop = true;
//		int const Visit_Index = DFS_Stack.top();
//
//		for (int i = 1; i < size+1; i++)
//		{
//			if (Vertexes_Link[Visit_Index][i] and (not Visit[i]))
//			{
//				DFS_Stack.push(i);
//				Visit[i] = 1;
//				cout << i << " ";
//				Is_Need_To_Pop = false;
//				break;
//			}
//		}
//		if (Is_Need_To_Pop)
//			DFS_Stack.pop();
//	}
//}
void DFS_Recursion(int const Visit_Index, int const size)
{
	cout << Visit_Index << " ";

	for (int i = 1; i < size + 1; i++)
	{
		if (Vertexes_Link[Visit_Index][i] and (not Visit[i]))
		{
			Visit[i] = 1;
			DFS_Recursion(i, size);
		}
	}
}
void BFS_Loop(int const size)
{
	while (!BFS_Queue.empty())
	{
		int Visit_Index = BFS_Queue.front();
		BFS_Queue.pop();
		cout << Visit_Index << " ";
		for (int i = 1; i < size + 1; i++)
		{
			if (Vertexes_Link[Visit_Index][i] and (not Visit[i]))
			{
				BFS_Queue.push(i);
				Visit[i] = 1;
			}
		}
	}
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int Vertexs_Num = 0;
	int Edges_Num = 0;
	int Start_Vertexs = 0;

	cin >> Vertexs_Num >> Edges_Num >> Start_Vertexs;

	while (Edges_Num--)
	{
		int Node_Index = 0;
		int Edge_Index = 0;
		cin >> Node_Index >> Edge_Index;

		Vertexes_Link[Node_Index][Edge_Index] = Vertexes_Link[Edge_Index][Node_Index] = 1;
	}
	Visit[Start_Vertexs] = 1;
	BFS_Queue.push(Start_Vertexs);

	DFS_Recursion(Start_Vertexs, Vertexs_Num);
	cout << "\n";

	memset(Visit, 0, sizeof(int) * 1001);
	Visit[Start_Vertexs] = 1;
	BFS_Loop(Vertexs_Num);
	//cout << Start_Vertexs << " ";
	//DFS_Stack.push(Start_Vertexs);
	//DFS_Loop(Vertexs_Num);

	return 0;
}



