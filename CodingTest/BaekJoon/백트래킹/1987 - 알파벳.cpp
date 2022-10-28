/*
1987 - 알파벳

문자열 find()를 사용해 방문처리를하면 시간초과를 발생시킨다

방문처리를 경우의 수 마다 해주기위해 백트래킹을 사용한다 (BFS도 가능하다)
알파벳 26자리를 인덱스로 파싱해 방문처리 한다
각 분기 종료마다 전역의 Max를 비교해 업데이트한다


최악의 연산 테스트케이스

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

답은 26 이다

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
	//전역 배열로 방문처리, 탈출시 기록 업데이트

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
