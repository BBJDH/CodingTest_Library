#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct LocationData
{
	int Position;
	int StepCount;
	//vector<int> Path;
};
queue<LocationData> BFS_Queue{};
int StartNum = 0;
int EndNum = 0;
bool Visit[100001]{};

void Visit_Location(LocationData const& data)
{
	//vector<int> Path = data.Path;
	//Path.push_back(data.Position);
	Visit[data.Position] = true;
	BFS_Queue.push({ data.Position,data.StepCount/*,  Path*/ });
}

void Push_Location(LocationData data)
{
	if (data.Position * 2 <= 100000 and (not Visit[data.Position * 2]))
	{
		Visit_Location({ data.Position * 2,data.StepCount + 1/*, data.Path*/ });
	}
	if (data.Position < 100000 and not Visit[data.Position + 1])
	{
		Visit_Location({ data.Position + 1,data.StepCount + 1/*, data.Path*/ });

	}

	if (data.Position - 1 >= 0 and not Visit[data.Position - 1])
	{
		Visit_Location({ data.Position - 1,data.StepCount + 1/*, data.Path*/ });

	}

}
void BFS_Loop()
{
	while (!BFS_Queue.empty())
	{
		LocationData data = BFS_Queue.front();
		BFS_Queue.pop();

		if (data.Position == EndNum)
		{
			cout << data.StepCount << "\n";
			//for (int& iter : data.Path)
			//	cout << iter << " ";
			return;
		}
		Push_Location(data);


	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> StartNum >> EndNum;
	BFS_Queue.push({ StartNum,0/*, vector<int>()*/ });
	Visit[StartNum] = true;
	BFS_Loop();

	return 0;
}
