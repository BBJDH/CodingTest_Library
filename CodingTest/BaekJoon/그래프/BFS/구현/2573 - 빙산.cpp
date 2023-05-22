/*
 *2573 - ����
 *
 *�־��� �������迭���� ������ ã�� BFS�� ���� Ǯ����.
 *
 *�� ����ĭ�� �湮�� ������ �ָ� ĭ�� �ٴ幰 ĭ�� ���� �ջ��� ���� ���̸� ���Ѵ�.
 *�̶� �ٷ� �� ������ ��Ƽ� ���̰� 0�̵� ���� ����ó�� ���־�� �Ѵ�.(�����⵵���� ����ȴ�.)
 *
 *�� BFS���� Ƚ���� ������ ��� Ƚ���� �ǹ��ϹǷ�
 *
 *BFS�� ���� Ƚ���� ī�����Ͽ� ������ �䱸���׿� �°� ����Ѵ�.
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
    //�湮���� �ʾ����鼭 �����ΰ�쿡�� ť�� Ǫ��!
    if (Visit[Next.Y][Next.X] == false and Map[Next.Y][Next.X] != 0)
    {

        BFSQueue.push(Next);
        Visit[Next.Y][Next.X] = true;
        //���̱� ����

        int SideCount = 0;
        for (int i = 0; i < 4; i++)
        {
            _int2 Side{};
            Side.X = Next.X + Direction[i].X;
            Side.Y = Next.Y + Direction[i].Y;

            //�ֺ��� �ٴ幰�ε�, ������ �����̾��� ���� ����!(Visit�� true�� ó���Ȱ��� ����)
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

        //���ο� ���� ����
        Map[Next.Y][Next.X] = Height;


    }
}

void SearchEdge(_int2 const& Current)
{
    //���⼭ 
    for (int i = 0; i < 4; i++)
    {
        _int2 Next{};

        Next.X = Current.X + Direction[i].X;
        Next.Y = Current.Y + Direction[i].Y;

        //���� ���⼭ �迭 ����üũ ����� �ϴµ�.. ������ ������ �����ڸ��� ��� 0���� ���ִ�
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

        //�湮 �迭 �ʱ�ȭ
        for (int y = 0; y < Size.Y; y++)
        {
            fill_n(Visit[y], Size.X, false);
        }

        int CountOfIceBerg = 0;
        //1�� �帣�� ����
        for (int y = 0; y < Size.Y; y++)
        {
            for (int x = 0; x < Size.X; x++)
            {

                ////�ٸ� ���
                //if(Visit[y][x] == true or Map[y][x] == 0)
                //{
                //   continue;
                //}
                ////���⿡ �����ߴٴ� ���� �̹� BFS�� �����Ǿ� �ִٶ�� �ǹ�
                //BFS({ x,y });
                //CountOfIceBerg++;


                //������ ���
                //�� �ѹ��� IsSucceeded == true �� ��ȯ��
                if (BFS({ x,y }) == true) //��ȯ�Ǵ� bool���� ���� == ������ ��� ����
                {
                    CountOfIceBerg++;
                }
            }
        }

        //�׻� ������ Ż�����Ǻ���!
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