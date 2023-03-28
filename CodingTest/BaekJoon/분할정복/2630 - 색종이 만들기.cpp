/*
 * 2630 - 색종이 만들기
 *
 *
 *분할 정복과 재귀를 통해 풀었다
 *
 *색종이를 문제가 요구하는바와 같이 4등분으로 분할 정복한다
 *
 *더이상 자를 수 없는 Size==1 인 상태에 도달한다면 해당 종이의 컬러를 반환한다.
 *
 *반환값은 종이의 색(하얀색, 파란색)과 이 구역을 모두 카운팅 했는지 유무이다.
 *0은 하얀색 1은 파란색 2는 해당 구역이 완료되었음을 나타낸다.
 *
 *분할된 4구역의 값을 배열로 저장하여 모든 종이의 색이 일치하는지를 확인한다
 *
 *일치하지 않는다면 해당 구역의 나뉜 종이의 갯수를 카운팅하고
 *
 *완료된 구역의 의미인 2를 반환한다.
 *
 *이와 같이 모든 구역에 대하여 분할이 완료되고 카운팅이 완료되었다면
 *
 *해당 결과값을 출력한다.
 *
 *마지막으로 제일 큰 종이가 1 혹은 0으로 모두 같은 색인 경우를 고려한다.
 *
 */


#include <iostream>

using namespace std;

struct _int2
{
	int X;
	int Y;
};

int Paper[128][128]{};
int Result[2]{};
int Size = 0;
int PaperOfWhite = 0;
int PaperOfBlue = 0;


int DivideAndConquer(_int2 const PosOfStart, int const Size)
{
	if (Size == 1)
	{
		return Paper[PosOfStart.Y][PosOfStart.X];
	}
	int const NewSize = Size / 2;
	int ResultOfDivide[4]{};
	ResultOfDivide[0] = DivideAndConquer(PosOfStart, NewSize);
	ResultOfDivide[1] = DivideAndConquer({ PosOfStart.X + NewSize, PosOfStart.Y }, NewSize);
	ResultOfDivide[2] = DivideAndConquer({ PosOfStart.X,PosOfStart.Y + NewSize }, NewSize);
	ResultOfDivide[3] = DivideAndConquer({ PosOfStart.X + NewSize,PosOfStart.Y + NewSize }, NewSize);

	if (ResultOfDivide[0] == ResultOfDivide[1] and ResultOfDivide[1] == ResultOfDivide[2]
		and ResultOfDivide[2] == ResultOfDivide[3] and ResultOfDivide[3] != 2)
	{
		return ResultOfDivide[0];
	}
	for (int i = 0; i < 4; i++)
	{
		if (ResultOfDivide[i] == 2)
		{
			continue;
		}
		int const ColorOfPaper = ResultOfDivide[i];
		Result[ColorOfPaper]++;
	}
	//이 구역의 종이 수는 모두 카운팅 완료 했으므로 2
	return 2;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> Size;

	for (int y = 0; y < Size; y++)
	{
		for (int x = 0; x < Size; x++)
		{
			cin >> Paper[y][x];
		}
	}
	int ColorOfPaper = DivideAndConquer({ 0,0 }, Size);
	if (ColorOfPaper != 2)
	{
		Result[ColorOfPaper]++;
	}

	cout << Result[0] << "\n" << Result[1];
	return 0;
}