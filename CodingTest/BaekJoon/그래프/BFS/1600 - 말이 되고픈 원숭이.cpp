/*
 * 1600 - ���� �ǰ��� ������
 *
 *�׷��� Ž���� ���� Ǯ�� �����ϴ�
 *
 *�湮 �迭�� 3���� �迭�� �����Ѵٴ� �߻��� �ʿ��� ����
 *
 *���� ������ �湮 �Ͽ��� ��, ���� �̵��� Ƚ���� ���� �湮ó���� �ʿ��ϴ�
 *
 *2���� �迭�� ��ǥ �湮�� ����Ѱ��, ���� ������ �����̵��� ����� ����
 *�����̷θ� �̵��ϰԵ� ����� ���� �����Ѵ�.
 *
 *������ ���� ������ ���� ���� ������ Ƚ���� �湮 �迭�� �߰��Ѵ�.
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

void SearchEdge(Node const& Current)//....ä��!
{

    //���� ��ó�� ������ ���� ������ �׳� ���� ĭ���� �����̴� ��쵵 BFSQueue�� ���� �õ�
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
    //��ó�� �����ϼ� �ִ� ���
    if (Current.HorseStep < MaxCountOfHorse)
    {
        //���� �����̴� ��� ������ Next�� ���� Node�� BFSQueue�� ���� �õ� 
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


    //���� ��� Push �õ��� ���� �������� �̹� �湮�Ͽ��ٸ�, BFS Ư���� �̹� �ִܰ�η� ���������Ƿ� Push�� ������
}

void BFS(Node const& Start)
{
    Push(Start);

    while (not BFSQueue.empty())
    {
        Node const Current = BFSQueue.front();
        BFSQueue.pop();

        //�����ߴٸ� �ִܰŸ� Ȯ���̹Ƿ� ���⼭ ����!
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