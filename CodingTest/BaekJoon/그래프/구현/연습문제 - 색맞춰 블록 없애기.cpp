/*
 *======================================================================
 *연습문제 - 색맞춰 블록 없애기
 *
 *같은 색을 BFS가 탐색할 같은 구역으로 취급한다.
 *
 *가로, 세로순으로 BFS를 탐색하여 검색된 구역을 누적 및 합산한다.
 *
 *가장 컷던 구역을 Answer로 출력
 *
 */

 #include <iostream>
 #include <vector>
 #include <string>
 #include <queue>
 
 using namespace std;
 
 struct _int2 
 {
 	int X;
 	int Y;
 };
 
 struct Node
 {
 	int X;
 	int Y;
 	char Block;
 };
 
 vector<string> Board{};
 bool Visit[50][50]{};
 queue<Node> BFS_Queue{};
 int Size = 0;
 _int2 Direction[4] = {{1,0}, {-1,0}, {0,1}, {0,-1} };
 
 void Push(Node const & Next)
 {
 	if(Visit[Next.Y][Next.X]==false)
 	{
 		Visit[Next.Y][Next.X] = true;
 		BFS_Queue.push(Next);
 	}
 }
 
 void RoundEdges(Node const& Current)
 {
 	for(int i=0; i<4; i++)
 	{
 		Node Next{};
 		Next.X = Current.X + Direction[i].X;
 		Next.Y = Current.Y + Direction[i].Y;
 		
 		if (Next.X >= 0 and Next.X < Size and
 			Next.Y >= 0 and Next.Y < Size and
 			Current.Block == Board[Next.Y][Next.X])
 		{
 			Next.Block = Board[Next.Y][Next.X];
 			Push(Next);
 		}
 	}
 }
 
 int BFS(Node const & Start)
 {
 	BFS_Queue = queue<Node>();
 	int Result = 0;
 	Push(Start);
 	while (!BFS_Queue.empty())
 	{
 		Node const Current = BFS_Queue.front();
 		BFS_Queue.pop();
 		RoundEdges(Current);
 		Result++;
 	}
 	return Result;
 }
 
 int Solution(vector<string> board)
 {
 	int answer = -1;
 	Size = board.size();
 	Board = board;
 
 	for(int y=0; y<Size; y++)
 	{
 		for(int i=0; i<50; i++)
 		{
 			fill_n(Visit[i], 50, false);
 		}
 		int Sum = 0;
 		for(int x=0; x<Size; x++)
 		{
 			Sum += BFS({x,y,Board[y][x]});
 		}
 		answer = max(answer, Sum);
 	}
 	for (int x = 0; x < Size; x++)
 	{
 		for (int i = 0; i < 50; i++)
 		{
 			fill_n(Visit[i], 50, false);
 		}
 		int Sum = 0;
 		for (int y = 0; y < Size; y++)
 		{
 			Sum += BFS({ x,y,Board[y][x] });
 		}
 		answer = max(answer, Sum);
 	}
 
 	return answer;
 }
 
 int main()
 {
 	cin.tie(nullptr);
 	ios_base::sync_with_stdio(false);
 	//vector<string> Input = { "ABBBBC", "AABAAC", "BCDDAC", "DCCDDE", "DCCEDE", "DDEEEB" };
 	vector<string> Input = { "DDCCC", "DBBBC", "DBABC", "DBBBC", "DDCCC" };
 	cout << Solution(Input);
 
 	return 0;
 }
 
