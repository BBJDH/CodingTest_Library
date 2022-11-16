/*
11049 - 행렬 곱셈 순서

행렬의 갯수 만큼 DP[500][500]


5 3
3 2
2 4
4 6

행렬이 있다고 가정해보자

각 행렬의 위치는 변하지 않으므로 인접 행렬간 곱셈은 항상 연산횟수가 최소이다
각 행렬간 연산수를 기록해보면

5 3             0     5*3*2(30) 0		0
  3 2       =>	0		0	  3*2*4(24) 0
	2 4			0		0		0	2*4*6(48)
	  4 6		0		0		0		0

이번엔 각 행렬의 곱으로 생기는 행렬의 크기도 기록해보자()
(입력행렬)					(행렬 크기 변화)					(행렬 연산 수)
5 3					5 3	  5 2	5 4		5 6				0		30		A		0
  3 2		=>			  3 2	3 4		3 6			=>	0		0		24		B
	2 4							2 4		2 6				0		0		0		48
	  4 6								4 6				0		0		0		0

행렬 연산 수 A 와 B를 구해보면,
A => (5 3 3 2 행렬로 만들어진 5 2 행렬 연산값, 30) + (만들어진 5 2 와 남은행렬 2 4행렬 연산값 5*2*4) = 70
  => (3 2 2 4 행렬로 만들어진 3 4 행렬 연산값, 24) + (만들어진 3 4 와 남은행렬 5 3행렬 연산값 5*3*4) = 84
  이 두값의 최소값인 70이 A가 된다

  즉 정리하면
  DP[0][2] = min(기존 DP[0][2], DP[0][0](값은 0이다) + DP[1][2]				+ 두 DP행렬의 곱셈연산 수 )
  DP[0][2] = min(기존 DP[0][2], DP[0][1]				+ DP[2][2](값은 0이다) + 두 DP행렬의 곱셈연산 수 )
  로 정리된다

B => (3 2 2 4 행렬로 만들어진 3 4 행렬 연산값, 24) + (만들어진 3 4 와 남은행렬 4 6행렬 연산값 3*4*6) = 96
  => (2 4 4 6 행렬로 만들어진 2 6 행렬 연산값, 48) + (만들어진 2 6 와 남은행렬 3 2행렬 연산값 3*2*6) = 84
  이 두값의 최소값인 84이 B가 된다

	즉 정리하면
  DP[1][3] = min(기존 DP[1][3], DP[1][1](값은 0이다) + DP[2][3]				+ 두 DP행렬의 곱셈연산 수 )
  DP[1][3] = min(기존 DP[1][3], DP[1][2]				+ DP[3][3](값은 0이다) + 두 DP행렬의 곱셈연산 수 )
  로 정리된다

  (입력행렬)					(행렬 크기 변화)					(행렬 연산 수)
5 3					5 3	  5 2	5 4		5 6				0		30		70		C
  3 2		=>			  3 2	3 4		3 6			=>	0		0		24		84
	2 4							2 4		2 6				0		0		0		48
	  4 6								4 6				0		0		0		0

C를 구해보면
70(5*4행렬) + 5*4*6(5 4 4 6) = 190
30(5*2행렬) + 48(2*6행렬) + 5*2*6(5 2 2 6) = 138
84(3*6행렬) + 5*3*6(5 3 3 6) = 174
C는 138이 된다

	즉 정리하면
  DP[0][3] = min(기존 DP[0][3], DP[0][0](값은 0이다) + DP[1][3] + 두 DP행렬의 곱셈연산 수 )
  DP[0][3] = min(기존 DP[0][3], DP[0][1]				+ DP[2][3] + 두 DP행렬의 곱셈연산 수 )
  DP[0][3] = min(기존 DP[0][3], DP[0][2]				+ DP[3][3](값은 0이다) + 두 DP행렬의 곱셈연산 수 )
  로 정리된다

즉 종합해보면 DP[Start][End] = DP[Start][Mid] + DP[Mid+1][End] + 두 DP행렬 곱에서 발생하는 연산 수
								(Mid는 Start부터 시작, Mid+1이 End와 같을때 까지)

로 정리된다
각 연산마다 변형될 행렬의 모양과 연산수를 DP배열로 저장한다

먼저 임의의 두 행렬 크기에 대한 연산 수를 구하는 함수를 작성하고, DP를 시작하자

 */

#include <iostream>
#include <vector>

using namespace std;

struct _int2
{
	int Row;
	int Col;
};
#define INF ~(1<<31)
int Size = 0;
int DP[500][500]{};
_int2 DP_Matrix[500][500]{};

int CalcMulCount(_int2 const& Left, _int2 const& Right)
{
	return Left.Row * Left.Col * Right.Col;
}

void MakeDP(int const Start, int const End)
{
	//DP[Start][End]를 구한다

	DP[Start][End] = INF;
	for (int mid = Start; mid + 1 <= End; mid++)
	{
		DP[Start][End] = min(DP[Start][End], DP[Start][mid] + DP[mid + 1][End]
			+ CalcMulCount(DP_Matrix[Start][mid], DP_Matrix[mid + 1][End]));
	}
	DP_Matrix[Start][End] = { DP_Matrix[Start][Start].Row, DP_Matrix[End][End].Col };
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> Size;
	for (int i = 0; i < Size; i++)
	{
		_int2 Input{};

		cin >> Input.Row >> Input.Col;
		DP_Matrix[i][i] = Input;
	}

	//DP[0][Size-1]을 구하기 위한 여정 시작
	/*
	 * DP[0][0] DP[1][1] DP[2][2] DP[3][3]
	 * DP[0][1] DP[1][2] DP[2][3]
	 * DP[0][2] DP[1][3]
	 * DP[0][3] 구하고 종료
	 *
	 * Start - End 사이의 gap을 0부터 Size-1로 늘여나가며 DP를 구함
	 */

	for (int gap = 1; gap < Size; gap++)
	{
		for (int start = 0; start + gap < Size; start++)
		{
			int end = start + gap;
			MakeDP(start, end);
		}
	}
	cout << DP[0][Size - 1];


	return 0;
}
