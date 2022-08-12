

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int Map[101][101]{};
int Visit[101]{};
stack<int> DPS_Stack;
queue<int> BFS_Queue;
int Curupted_Num = 0;
void DFS_Recursion(int const Computer_Index, int& Curupted_Num)
{
	for (int i = 1; i < 101; i++)
	{
		if (Map[Computer_Index][i] && (not Visit[i]))
		{
			Visit[i] = 1;
			Curupted_Num++;
			DFS_Recursion(i, Curupted_Num);
		}
	}
}
void DFS_Loop()
{
	while (not DPS_Stack.empty())
	{
		int Visit_Computer_Num = DPS_Stack.top();
		DPS_Stack.pop();
		for (int i = 1; i < 101; i++)
		{
			if (Map[Visit_Computer_Num][i] and (not Visit[i]))
			{
				DPS_Stack.push(i);
				Visit[i] = true;
				Curupted_Num++;
			}
		}
	}
}
void BFS_Loop()
{
	while (not BFS_Queue.empty())
	{
		int Visit_Computer_Num = BFS_Queue.front();
		BFS_Queue.pop();
		for (int i = 1; i < 101; i++)
		{
			if (Map[Visit_Computer_Num][i] and (not Visit[i]))
			{
				BFS_Queue.push(i);
				Visit[i] = true;
				Curupted_Num++;
			}
		}
	}
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);



	int Edge_Num = 0;
	int Computer_Num = 0;

	cin >> Computer_Num >> Edge_Num;

	while (Edge_Num--)
	{
		int Computer_Index = 0;
		int Edge_Computer_Index = 0;
		cin >> Computer_Index >> Edge_Computer_Index;
		Map[Computer_Index][Edge_Computer_Index] = Map[Edge_Computer_Index][Computer_Index] = 1;
	}
	Visit[1] = 1;
	//DPS_Stack.push(1);
	//DFS_Loop();
	BFS_Queue.push(1);
	BFS_Loop();
	cout << Curupted_Num;

	return 0;
}

