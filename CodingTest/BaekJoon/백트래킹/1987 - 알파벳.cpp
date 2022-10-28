/*
1987 - ���ĺ�

���ڿ� find()�� ����� �湮ó�����ϸ� �ð��ʰ��� �߻���Ų��

�湮ó���� ����� �� ���� ���ֱ����� ��Ʈ��ŷ�� ����Ѵ� (BFS�� �����ϴ�)
���ĺ� 26�ڸ��� �ε����� �Ľ��� �湮ó�� �Ѵ�
�� �б� ���Ḷ�� ������ Max�� ���� ������Ʈ�Ѵ�


�־��� ���� �׽�Ʈ���̽�

20 20
ABCDEFGHIJKLMNOPQRST
BCDEFGHIJKLMNOPQRSTU
CDEFGHIJKLMNOPQRSTUV
DEFGHIJKLMNOPQRSTUVW
EFGHIJKLMNOPQRSTUVWX
FGHIJKLMNOPQRSTUVWXY
GHIJKLMNOPQRSTUVWXYZ
HIJKLMNOPQRSTUVWXYZA
IJKLMNOPQRSTUVWXYZAA
JKLMNOPQRSTUVWXYZAAA
KLMNOPQRSTUVWXYZAAAA
LMNOPQRSTUVWXYZAAAAA
MNOPQRSTUVWXYZAAAAAA
NOPQRSTUVWXYZAAAAAAA
OPQRSTUVWXYZAAAAAAAA
PQRSTUVWXYZAAAAAAAAA
QRSTUVWXYZAAAAAAAAAA
RSTUVWXYZAAAAAAAAAAA
STUVWXYZAAAAAAAAAAAA
TUVWXYZAAAAAAAAAAAAA

���� 26 �̴�

*/


#include<iostream> 
#include<vector>

using namespace std;
struct _int2
{
	int X;
	int Y;
};

_int2 Direction[4] = { {-1,0}, {1,0} ,{0,1} ,{0,-1} };
vector<string> Board{};
bool VisitAlphabat[26]{};
int R = 0, C = 0;
int MaxSize = 0;



void BackTrack(_int2 const& Current, int const Count)
{
	//���� �迭�� �湮ó��, Ż��� ��� ������Ʈ

	for (int i = 0; i < 4; i++)
	{
		_int2 const Next{ Current.X + Direction[i].X, Current.Y + Direction[i].Y };

		if (Next.X >= 0 and Next.X < C and Next.Y >= 0 and Next.Y < R)
		{
			int const VisitIndex = Board[Next.Y][Next.X] - 'A';
			if (VisitAlphabat[VisitIndex] == false)
			{
				VisitAlphabat[VisitIndex] = true;
				BackTrack(Next, Count + 1);
				VisitAlphabat[VisitIndex] = false;
			}
		}
	}

	MaxSize = max(MaxSize, Count);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> R >> C;
	int InputCount = R;
	while (InputCount--)
	{
		string InputStr{};
		cin >> InputStr;
		Board.emplace_back(InputStr);
	}

	int const VisitIndex = Board[0][0] - 'A';
	VisitAlphabat[VisitIndex] = true;

	BackTrack({ 0,0 }, 1);
	cout << MaxSize;
	return 0;
}
