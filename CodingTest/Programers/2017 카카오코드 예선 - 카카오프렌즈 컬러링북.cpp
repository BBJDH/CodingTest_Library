
/*
 *2017 카카오코드 예선 - 카카오프렌즈 컬러링북
 *
 *
 *간단한 BFS 문제였다.
 *다만 큐에 삽입할때 위치 뿐만아니라 컬러도 넣어주어
 *구역을 식별할 수 있도록 처리한다
 *
 *BFS의 시작점은 모든 컬러를 가진 위치에 대하여 시행하며
 *한번이라도 이미 탐색된 공간은 방문처리가 되어있으므로
 *삽입되어도 탐색처리되지 않는다.
 *
 */
 
 #include <vector>
 #include <queue>


 using namespace std;

 // 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

 struct _int2
 {
     int X;
     int Y;
 };
 struct Node
 {
     _int2 Pos{};
     int Color;
 };
 _int2 Direction[4] = {{1,0},{-1,0},{0,1},{0,-1}};
 int Visit[100][100]{};
 queue<Node>BFS_Queue{};
 vector<vector<int>>Map{};

 int SizeX=0,SizeY=0;

 bool Push(Node const & Next)
 {
     if(Visit[Next.Pos.Y][Next.Pos.X]==false)
     {
         Visit[Next.Pos.Y][Next.Pos.X] = true;
         BFS_Queue.push(Next);
         return true;
     }
     return false;
 }

 void RoundEdges(Node const & Current)
 {
     for(int i=0; i<4; i++)
     {
         Node Next{};
         Next.Pos.X = Current.Pos.X+Direction[i].X;
         Next.Pos.Y = Current.Pos.Y+Direction[i].Y;
         Next.Color = Current.Color;
         if(Next.Pos.X >=0 && Next.Pos.X <SizeX && Next.Pos.Y >=0 && Next.Pos.Y <SizeY and Current.Color == Map[Next.Pos.Y][Next.Pos.X] )
         {
             Push(Next);
         }

     }
 }

 int BFS(Node const & Start)
 {
     if(Push(Start)==false)
         return 0;
     int Count=0;
     while(!BFS_Queue.empty())
     {
         Node const Current = BFS_Queue.front();
         BFS_Queue.pop();
         RoundEdges(Current);
         Count++;
     }
     return Count;
 }


 vector<int> solution(int m, int n, vector<vector<int>> picture) {
     int number_of_area = 0;
     int max_size_of_one_area = 0;

     //초기화
     SizeX = n;
     SizeY = m;
     //BFS_Queue = queue<_int2>{};
     for(int i=0; i<100; i++)
         fill_n(Visit[i],100,false);
     Map = picture;
     // 실행
     for(int y=0; y<SizeY; y++)
     {
         for(int x=0; x<SizeX; x++)
         {
             if(Map[y][x]!=0)
             {
                 int result = BFS({{x,y}, Map[y][x]});
                 if(result != 0)
                 {
                     number_of_area++;
                     max_size_of_one_area = max(max_size_of_one_area, result);
                 }
             }
         }
     }
     vector<int> answer(2);
     answer[0] = number_of_area;
     answer[1] = max_size_of_one_area;
     return answer;
 }
  


