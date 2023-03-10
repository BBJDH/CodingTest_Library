/*
 *1022 - �ҿ뵹�� ���ڰ� ����ϱ�
 *
 *�Է¹��� ũ�⸸ŭ �迭�� �����ΰ�,
 *
 *�ҿ뵹�̸� �׷����ٰ� �Է¹��� ��ǥ ������ ������,
 *�迭�� ����Ѵ�.
 *
 *�ҿ뵹�̸� �ִ�ũ��� �����ٸ� 10000* 10000���� 1�￡ ��������
 *
 *�迭�� ũ��� 49���Ϸ� while���ȿ��� �迭�� �� ä������
 *
 *�����Ͽ� ����� �ٿ���.
 *
 *�迭�� ���ڰ� ����ϱ����� �迭�� ��ȣ�� ���� ū���� ���̸� ���ϰ�
 *
 *���̸�ŭ �����Ѻκ��� ����ó���� ���־�� �Ѵ�.
 *
 *
 *�ҿ뵹�̿��� ������ ���� ��Ģ���ִ�.
 *
 *1�� ����ϰ�
 *���������� ��ĭ ���� ��ĭ
 *���� ��ĭ �Ʒ� ��ĭ
 *������ ��ĭ ���� ��ĭ
 *���� ��ĭ �Ʒ� ��ĭ
 *...
 *�ι� �ڳʸ� �� ������ ������ �����ϴ� Ƚ���� 1�� �����Ѵ�
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

//������ �� ���� �Ʒ�
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

	//����� �迭
	vector<vector<int>> ArrayToPrint{};
	//����� ���� ��, ������ �Ʒ� ��ǥ
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

	//��� ũ�⿡ ���� �迭ũ�� �Ҵ�
	ArrayToPrint.resize(PrintSizeOfY);
	for (int i = 0; i < PrintSizeOfY; i++)
	{
		ArrayToPrint[i].resize(PrintSizeOfX);
	}

	while (ArrayToPrint[0][0] == 0 or ArrayToPrint[PrintSizeOfY - 1][0] == 0
		or ArrayToPrint[0][PrintSizeOfX - 1] == 0 or ArrayToPrint[PrintSizeOfY - 1][PrintSizeOfX - 1] == 0)
	{
		//��ġüũ, ���� ���̸� �迭�� ���
		if (CurrentPos.X >= MinPosToPrint.X and CurrentPos.Y >= MinPosToPrint.Y
			and CurrentPos.X <= MaxPosToPrint.X and CurrentPos.Y <= MaxPosToPrint.Y)
		{
			_int2 IndexOfPrintArr{};
			IndexOfPrintArr.X = CurrentPos.X - MinPosToPrint.X;
			IndexOfPrintArr.Y = CurrentPos.Y - MinPosToPrint.Y;
			ArrayToPrint[IndexOfPrintArr.Y][IndexOfPrintArr.X] = NumToPrint;
		}


		//���� ��ġ �̸� ���

		CurrentPos.X = CurrentPos.X + Direction[IndexOfDirection].X;
		CurrentPos.Y = CurrentPos.Y + Direction[IndexOfDirection].Y;
		CurrentFillCount++;

		//MaxFillCount�� �����ߴٸ� ���� ��ȯ �� CurrentFillCount�ʱ�ȭ
		if (CurrentFillCount == MaxFillCount)
		{
			//���� �ٲ�� ����, �����ε��� ����
			CurrentCountOfDirChanged++;
			IndexOfDirection = (IndexOfDirection + 1) % 4;
			CurrentFillCount = 0;

			//���� CurrentCountOfDirChanged�� 2�� �����Ѵٸ� MaxFillCount�� �����ϴ� ��Ģ�� ����
			if (CurrentCountOfDirChanged == 2)
			{
				//����ٲۼ� �ʱ�ȭ
				CurrentCountOfDirChanged = 0;
				MaxFillCount++;
			}
		}

		//ĭ�� ä�� �� ����, 


		//���� ��ȣ �̸� ����

		NumToPrint++;
	}


	//�迭 ���... ���ڰ�...
	//���� ū ���� NumToPrint�� �� ���̸� �˰� �ִ�.
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