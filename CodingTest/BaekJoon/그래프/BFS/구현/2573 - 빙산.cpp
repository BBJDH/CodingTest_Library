/*
 *2573 - 빙산
 *
 *주어진 이차원배열에서 빙산을 찾아 BFS를 통해 풀었다.
 *
 *각 빙산칸을 방문할 때마다 주면 칸의 바닷물 칸의 수를 합산해 다음 높이를 구한다.
 *이때 바로 옆 빙산이 녹아서 높이가 0이된 경우는 예외처리 해주어야 한다.(다음년도부터 적용된다.)
 *
 *각 BFS정공 횟수는 빙산의 덩어리 횟수를 의미하므로
 *
 *BFS의 성공 횟수를 카운팅하여 문제의 요구사항에 맞게 출력한다.
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

_int2 Size{};
queue<_int2> BFSQueue{};
int Map[300][300]{};
int Visit[300][300]{};
_int2 Direction[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };



void Push(_int2 const& Next)
{
    //방문하지 않았으면서 빙산인경우에만 큐에 푸시!
    if (Visit[Next.Y][Next.X] == false and Map[Next.Y][Next.X] != 0)
    {

        BFSQueue.push(Next);
        Visit[Next.Y][Next.X] = true;
        //녹이기 ㄱㄱ

        int SideCount = 0;
        for (int i = 0; i < 4; i++)
        {
            _int2 Side{};
            Side.X = Next.X + Direction[i].X;
            Side.Y = Next.Y + Direction[i].Y;

            //주변에 바닷물인데, 이전에 빙산이었던 곳은 제외!(Visit이 true로 처리된곳은 제외)
            if (Map[Side.Y][Side.X] == 0 and Visit[Side.Y][Side.X] == false)
            {
                SideCount++;
            }
        }

        int Height = Map[Next.Y][Next.X] - SideCount;
        if (Height < 0)
        {
            Height = 0;
        }

        //새로운 높이 대입
        Map[Next.Y][Next.X] = Height;


    }
}

void SearchEdge(_int2 const& Current)
{
    //여기서 
    for (int i = 0; i < 4; i++)
    {
        _int2 Next{};

        Next.X = Current.X + Direction[i].X;
        Next.Y = Current.Y + Direction[i].Y;

        //원래 여기서 배열 범위체크 해줘야 하는데.. 문제의 조건이 가장자리는 모두 0으로 차있다
        Push(Next);
    }
}


bool BFS(_int2 const& Start)
{
    bool IsSucceeded = false;
    Push(Start);
    while (not BFSQueue.empty())
    {
        IsSucceeded = true;
        _int2 const Current = BFSQueue.front();
        BFSQueue.pop();
        SearchEdge(Current);
    }
    return IsSucceeded;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> Size.Y >> Size.X;

    for (int y = 0; y < Size.Y; y++)
    {
        for (int x = 0; x < Size.X; x++)
        {
            cin >> Map[y][x];
        }
    }
    int Year = 0;
    while (true)
    {

        //방문 배열 초기화
        for (int y = 0; y < Size.Y; y++)
        {
            fill_n(Visit[y], Size.X, false);
        }

        int CountOfIceBerg = 0;
        //1년 흐르기 시작
        for (int y = 0; y < Size.Y; y++)
        {
            for (int x = 0; x < Size.X; x++)
            {

                ////다른 방법
                //if(Visit[y][x] == true or Map[y][x] == 0)
                //{
                //   continue;
                //}
                ////여기에 도달했다는 것은 이미 BFS가 예정되어 있다라는 의미
                //BFS({ x,y });
                //CountOfIceBerg++;


                //대현쓰 방법
                //단 한번만 IsSucceeded == true 가 반환됨
                if (BFS({ x,y }) == true) //반환되는 bool값의 갯수 == 빙산의 덩어리 갯수
                {
                    CountOfIceBerg++;
                }
            }
        }

        //항상 조건은 탈출조건부터!
        if (CountOfIceBerg == 0)
        {
            cout << 0;
            break;
        }

        if (CountOfIceBerg > 1)
        {
            cout << Year;
            break;
        }

        Year++;
    }


    return 0;
}