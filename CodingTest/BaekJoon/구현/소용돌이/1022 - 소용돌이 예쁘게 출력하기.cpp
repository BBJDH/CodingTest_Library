/*
 *1022 - 소용돌이 예쁘게 출력하기
 *
 *입력받은 크기만큼 배열을 만들어두고,
 *
 *소용돌이를 그려가다가 입력받은 좌표 안으로 들어오면,
 *배열에 기록한다.
 *
 *소용돌이를 최대크기로 만들어간다면 10000* 10000으로 1억에 달하지만
 *
 *배열의 크기는 49이하로 while문안에서 배열이 다 채워지면
 *
 *종료하여 비용을 줄였다.
 *
 *배열을 예쁘게 출력하기위해 배열의 번호중 가장 큰수의 길이를 구하고
 *
 *길이만큼 부족한부분은 공백처리를 해주어야 한다.
 *
 *
 *소용돌이에는 다음과 같은 규칙이있다.
 *
 *1을 기록하고
 *오른쪽으로 한칸 위로 한칸
 *왼쪽 두칸 아래 두칸
 *오른쪽 세칸 위로 세칸
 *왼쪽 네칸 아래 네칸
 *...
 *두번 코너를 돌 때마다 앞으로 전진하는 횟수가 1씩 증가한다
 *
 */


#include <iostream>
#include <vector>

using namespace std;

struct _int2
{
	int X;
	int Y;
};

//오른쪽 위 왼쪽 아래
_int2 Direction[4] = { {1,0},{0,-1},{-1,0},{0, 1} };

int GetLengthOfNum(int TargetNum)
{
	int Result = 0;
	while (TargetNum)
	{
		TargetNum /= 10;
		Result++;
	}
	return Result;
}
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	//출력할 배열
	vector<vector<int>> ArrayToPrint{};
	//출력할 왼쪽 위, 오른쪽 아래 좌표
	_int2 MinPosToPrint{};
	_int2 MaxPosToPrint{};
	_int2 CurrentPos{};
	int NumToPrint = 1;
	int MaxFillCount = 1;
	int CurrentFillCount = 0;
	int CurrentCountOfDirChanged = 0;
	int IndexOfDirection = 0;

	cin >> MinPosToPrint.Y >> MinPosToPrint.X >> MaxPosToPrint.Y >> MaxPosToPrint.X;
	int PrintSizeOfY = MaxPosToPrint.Y - MinPosToPrint.Y + 1;
	int PrintSizeOfX = MaxPosToPrint.X - MinPosToPrint.X + 1;

	//출력 크기에 맞춰 배열크기 할당
	ArrayToPrint.resize(PrintSizeOfY);
	for (int i = 0; i < PrintSizeOfY; i++)
	{
		ArrayToPrint[i].resize(PrintSizeOfX);
	}

	while (ArrayToPrint[0][0] == 0 or ArrayToPrint[PrintSizeOfY - 1][0] == 0
		or ArrayToPrint[0][PrintSizeOfX - 1] == 0 or ArrayToPrint[PrintSizeOfY - 1][PrintSizeOfX - 1] == 0)
	{
		//위치체크, 범위 안이면 배열에 기록
		if (CurrentPos.X >= MinPosToPrint.X and CurrentPos.Y >= MinPosToPrint.Y
			and CurrentPos.X <= MaxPosToPrint.X and CurrentPos.Y <= MaxPosToPrint.Y)
		{
			_int2 IndexOfPrintArr{};
			IndexOfPrintArr.X = CurrentPos.X - MinPosToPrint.X;
			IndexOfPrintArr.Y = CurrentPos.Y - MinPosToPrint.Y;
			ArrayToPrint[IndexOfPrintArr.Y][IndexOfPrintArr.X] = NumToPrint;
		}


		//다음 위치 미리 계산

		CurrentPos.X = CurrentPos.X + Direction[IndexOfDirection].X;
		CurrentPos.Y = CurrentPos.Y + Direction[IndexOfDirection].Y;
		CurrentFillCount++;

		//MaxFillCount에 도달했다면 방향 전환 및 CurrentFillCount초기화
		if (CurrentFillCount == MaxFillCount)
		{
			//방향 바뀐수 증가, 방향인덱스 증가
			CurrentCountOfDirChanged++;
			IndexOfDirection = (IndexOfDirection + 1) % 4;
			CurrentFillCount = 0;

			//만약 CurrentCountOfDirChanged가 2에 도달한다면 MaxFillCount가 증가하는 규칙이 있음
			if (CurrentCountOfDirChanged == 2)
			{
				//방향바꾼수 초기화
				CurrentCountOfDirChanged = 0;
				MaxFillCount++;
			}
		}

		//칸을 채운 수 증가, 


		//다음 번호 미리 갱신

		NumToPrint++;
	}


	//배열 출력... 예쁘게...
	//가장 큰 수는 NumToPrint가 그 길이를 알고 있다.
	int LengthOfMaxNum = GetLengthOfNum(NumToPrint - 1);

	for (vector<int> const& arr : ArrayToPrint)
	{
		for (int const elem : arr)
		{
			int Length = GetLengthOfNum(elem);
			for (int i = 0; i < LengthOfMaxNum - Length; i++)
			{
				cout << " ";
			}

			cout << elem << " ";
		}
		cout << "\n";
	}

	return 0;
}