
#include <iostream>
#include <stack>
using namespace std;

int Map[101][101]{};
int Visit[101]{};
stack<int> check;
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
	while (not check.empty())
	{
		int Visit_Computer_Num = check.top();
		check.pop();
		for (int i = 1; i < 101; i++)
		{
			if (Map[Visit_Computer_Num][i] and (not Visit[i]))
			{
				check.push(i);
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
	check.push(1);
	DFS_Loop();
	cout << Curupted_Num;

	return 0;
}