//#include <iostream>
//#include <queue>
//#include <vector>
//
//using namespace std;
//
//struct _int2
//{
//	int X;
//	int Y;
//};
//
//queue<_int2> BFS_Queue{};
//vector<_int2> EmptyPlace{};
//_int2 Direction[4] = { {1,0}, {-1,0}, {0,-1}, {0,1} };
//int Map[1000][1000]{};
//bool Visit[1000][1000]{};
//int SizeY = 0, SizeX = 0;
//
//bool Push(_int2 const & Next)
//{
//	if(Visit[Next.Y][Next.X]==false)
//	{
//		Visit[Next.Y][Next.X] = true;
//		BFS_Queue.push(Next);
//		return true;
//	}
//	return false;
//}
//
//void RoundEdges(_int2 const & Current)
//{
//	for(int i=0; i<4; i++)
//	{
//		_int2 Next{};
//		//0이하로 내려가는경우
//		Next.X = Current.X + Direction[i].X;
//		Next.Y = Current.Y + Direction[i].Y;
//		if (Next.X == -1)
//			Next.X = SizeX - 1;
//		else if(Next.X == SizeX)
//			Next.X = 0;
//
//		if (Next.Y == -1)
//			Next.Y = SizeY - 1;
//		else if (Next.Y == SizeY)
//			Next.Y = 0;
//		Push(Next);
//
//	}
//}
//
//bool BFS(_int2 const & Start)
//{
//	if (Push(Start) == false)
//		return false;
//
//	while (!BFS_Queue.empty())
//	{
//		_int2 const Current = BFS_Queue.front();
//		BFS_Queue.pop();
//		RoundEdges(Current);
//	}
//	return true;
//}
//
//int main()
//{
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
//
//	cin >> SizeY >> SizeX;
//	for(int y=0; y<SizeY; y++)
//	{
//		for(int x=0; x<SizeX; x++)
//		{
//			cin >> Visit[y][x];
//			if(Visit[y][x]==0)
//			{
//				EmptyPlace.push_back({x,y});
//			}
//		}
//	}
//	int Result = 0;
//	for(auto const & elem : EmptyPlace)
//	{
//		if (BFS(elem))
//			Result++;
//	}
//	cout << Result;
//	return 0;
//}

// B번
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//vector<int>Nums{};
//int DP_Min[100000]{};
//int DP_Max[100000]{};
//int main()
//{
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
//
//	int N = 0;
//	cin >> N;
//	int PrevNum = 0;
//	int Sum = 0;
//
//	for(int i=0; i<N; i++)
//	{
//		int InputNum = 0;
//		cin >> InputNum;
//		if(PrevNum != InputNum)
//		{
//			if(PrevNum==0)
//			{
//				PrevNum = InputNum;
//				Sum++;
//				continue;
//			}
//			if (PrevNum == 2)
//				Sum *= -1;
//			Nums.push_back(Sum);
//			PrevNum = InputNum;
//			Sum = 0;
//		}
//		Sum++;
//	}
//	if (PrevNum == 2)
//		Sum *= -1;
//	Nums.push_back(Sum);
//	//음수 양수로 치환 완료, 최소 최대 부분수열 구하기 시작
//
//	DP_Max[0] = Nums[0];
//	DP_Min[0] = Nums[0];
//	int MaxNum = DP_Max[0];
//	int MinNum = DP_Min[0];
//	for(int i=1; i< Nums.size(); i++)
//	{
//		DP_Max[i] = max(DP_Max[i - 1] + Nums[i], Nums[i]);
//		DP_Min[i] = min(DP_Min[i - 1] + Nums[i], Nums[i]);
//		MaxNum = max(MaxNum, DP_Max[i]);
//		MinNum = min(MinNum, DP_Min[i]);
//	}
//	cout << max(abs(MinNum), MaxNum);
//	return 0;
//}
//


