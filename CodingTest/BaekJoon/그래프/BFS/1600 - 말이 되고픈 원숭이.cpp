/*
 * 1600 - 말이 되고픈 원숭이
 *
 *그래프 탐색을 통해 풀이 가능하다
 *
 *방문 배열을 3차원 배열로 구성한다는 발상이 필요한 문제
 *
 *같은 지점에 방문 하였을 때, 말로 이동한 횟수에 대한 방문처리가 필요하다
 *
 *2차원 배열로 좌표 방문만 사용한경우, 먼저 지나간 말로이동한 경우의 수가
 *원숭이로만 이동하게될 경우의 수를 방해한다.
 *
 *때문에 같은 지점에 대한 말로 점프한 횟수를 방문 배열에 추가한다.
 *
 */
#include <iostream>
#include <queue>

using namespace std;

struct _int2
{
    int X;
    int Y;
};

struct Node
{
    _int2 Pos;
    int HorseStep;
    int Step;
};

int Map[200][200]{};
bool Visit[200][200][31]{};
queue<Node> BFSQueue{};
_int2 DirectionLikeHorse[8] = { {1,-2}, {2,-1}, {2,1}, {1,2}, {-1,2}, {-2,1}, {-2,-1}, {-1,-2} };
_int2 DirectionNormal[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

_int2 Size{};
int MaxCountOfHorse = 0;


void Push(Node const& Next)
{

    if (Visit[Next.Pos.Y][Next.Pos.X][Next.HorseStep] == false and Map[Next.Pos.Y][Next.Pos.X] != 1)
    {
        Visit[Next.Pos.Y][Next.Pos.X][Next.HorseStep] = true;
        BFSQueue.push(Next);
    }
}

void SearchEdge(Node const& Current)//....채용!
{

    //물론 말처럼 움직일 수도 있지만 그냥 인접 칸으로 움직이는 경우도 BFSQueue에 삽입 시도
    for (int i = 0; i < 4; i++)
    {
        Node Next{};
        Next.Pos.X = Current.Pos.X + DirectionNormal[i].X;
        Next.Pos.Y = Current.Pos.Y + DirectionNormal[i].Y;
        Next.HorseStep = Current.HorseStep;
        Next.Step = Current.Step + 1;
        if (Next.Pos.X >= 0 and Next.Pos.X < Size.X and Next.Pos.Y >= 0 and Next.Pos.Y < Size.Y)
        {
            Push(Next);
        }
    }
    //말처럼 움직일수 있는 경우
    if (Current.HorseStep < MaxCountOfHorse)
    {
        //말로 움직이는 모든 방향을 Next로 만들어서 Node로 BFSQueue에 삽입 시도 
        for (int i = 0; i < 8; i++)
        {
            Node Next{};
            Next.Pos.X = Current.Pos.X + DirectionLikeHorse[i].X;
            Next.Pos.Y = Current.Pos.Y + DirectionLikeHorse[i].Y;
            Next.HorseStep = Current.HorseStep + 1;
            Next.Step = Current.Step + 1;

            if (Next.Pos.X >= 0 and Next.Pos.X < Size.X and Next.Pos.Y >= 0 and Next.Pos.Y < Size.Y)
            {

                Push(Next);
            }
        }
    }


    //위의 모든 Push 시도는 선행 과정에서 이미 방문하였다면, BFS 특성상 이미 최단경로로 지나갔으므로 Push에 실패함
}

void BFS(Node const& Start)
{
    Push(Start);

    while (not BFSQueue.empty())
    {
        Node const Current = BFSQueue.front();
        BFSQueue.pop();

        //도착했다면 최단거리 확정이므로 여기서 종료!
        if (Current.Pos.X == Size.X - 1 and Current.Pos.Y == Size.Y - 1)
        {
            cout << Current.Step;
            return;
        }
        SearchEdge(Current);
    }
    cout << -1;
}



int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);


    cin >> MaxCountOfHorse;
    cin >> Size.X >> Size.Y;

    for (int Y = 0; Y < Size.Y; Y++)
    {
        for (int X = 0; X < Size.X; X++)
        {
            cin >> Map[Y][X];
        }
    }
    BFS({ { 0,0 }, 0, 0 });
    return 0;
}