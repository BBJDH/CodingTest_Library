
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

struct Position
{
	int x;
	int y;
	int row()const { return x; }
	int col()const { return y; }
};
int Vertexes_Link[26][26]{};
int Visit[26][26]{};
Position const Direction[4]{ {-1,0}, {0,-1}, {0,1}, {1,0} };
stack<Position> DFS_Stack;
vector<int> Groub_Num{};

Position Find_ToVisit_Node()
{
	for (int x = 1; x < 26; x++)
	{
		for (int y = 1; y < 26; y++)
		{
			if (Vertexes_Link[y][x] and (not Visit[y][x]))
			{
				return { x,y };
			}
		}
	}
	return { 0,0 };
}
bool Check_None_Visit_Node(Position const Node_Pos)
{
	return Vertexes_Link[Node_Pos.y][Node_Pos.x] and (not Visit[Node_Pos.y][Node_Pos.x]);
}
void Push_Edge_Nodes(Position const Node_Pos)
{
	Position New_Direction[4]{};
	for (int i = 0; i < 4; i++)
	{
		New_Direction[i] = { Node_Pos.x + Direction[i].x, Node_Pos.y + Direction[i].y };
		if (New_Direction[i].x > 0 and New_Direction[i].x < 26 and New_Direction[i].y>0 and New_Direction[i].y < 26)
		{
			if (Check_None_Visit_Node(New_Direction[i]))
			{
				DFS_Stack.push(New_Direction[i]);
				Visit[New_Direction[i].y][New_Direction[i].x] = 1;
			}
		}
	}
	return;
}

bool DFS_Loop()
{
	Position Start_Node_Pos = Find_ToVisit_Node();
	if (Start_Node_Pos.x == 0 and Start_Node_Pos.y == 0)
		return false;
	Visit[Start_Node_Pos.y][Start_Node_Pos.x] = 1;
	DFS_Stack.push(Start_Node_Pos);

	int Node_Count = 0;
	while (!DFS_Stack.empty())
	{
		Position Next_Node = DFS_Stack.top();
		DFS_Stack.pop();
		Push_Edge_Nodes(Next_Node);
		Node_Count++;
	}
	Groub_Num.push_back(Node_Count);

	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int Line_Num = 0;
	cin >> Line_Num;
	int Row_Index = 1;

	while (Line_Num--)
	{
		string Input_Str;
		cin >> Input_Str;
		int size = Input_Str.length();

		for (int i = 0; i < Input_Str.length(); i++)
		{
			Vertexes_Link[Row_Index][i + 1] = Input_Str[i] - '0';
		}
		Row_Index++;
	}
	while (DFS_Loop()) {}
	sort(Groub_Num.begin(), Groub_Num.begin() + Groub_Num.size());
	cout << Groub_Num.size() << "\n";

	for (int i = 0; i < Groub_Num.size(); i++)
	{
		cout << Groub_Num[i] << "\n";
	}

	return 0;
}