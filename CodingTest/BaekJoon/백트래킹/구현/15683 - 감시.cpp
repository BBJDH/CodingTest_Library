/*
 * 15683 - ����
 *
 *�ִ� ���� ũ��� 64ĭ, CCTV�� ������ 8���̴�
 *
 *���� ��� ī�޶� 4���� ��� ������ ���Ѵٰ� �ص� 4^8 �� 6�� 5õ�� ����� ���� ������
 *
 *���⿡ �������� ��ŷ�� �񰨽����� ī���� ����� 100ĭ�̶� �Ѵٰ� �ϸ� 6,553,600 �� ����� ���.
 *
 *���� �־��� 1���� �ð� �Ⱦ� ����� Ǯ�� �����Ͽ�
 *
 *���Ʈ���� �� ��Ʈ��ŷ���� ���� Ž���Ͽ� Ǯ���ߴ�.
 *
 *���� ĥ�ؼ� �ѱ�� ���� �ƴ�, ī�Ŷ��� ������ ���� �������� �־��� ���� �����Ͽ�
 *���������� ��ĥ�ϰ� �񰨽� ������ ī������ �޸� ����� �ּ�ȭ �ߴ�.
 *(���� ȣ�⿡�� ���� ����� �� ��������� ����)
 *
 *���� ���� BlindArea�� �ּҰ��� �� ������ ���ܿ��� ������Ʈ�ϸ�
 *�Լ��� ������ ����� �� MinBlindArea�� ����Ѵ�.
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

struct Camera
{
	int Type;
	_int2 Pos{};
	int Direction;
};

_int2 Size{};
vector<vector<int>> Map{};

// �� �� �� ��
_int2 Direction[4] = { {1,0}, {0,-1}, {-1,0}, {0,1} };
int MinBlindArea = 64;

void MarkAsDirection(int IndexOfDirection, _int2 const& Pos, vector<vector<int>>& CopiedMap)
{
	//�־��� �������� ���� ������ ���
	_int2 CurrentPos = Pos;
	while (CurrentPos.X < Size.X and CurrentPos.X >= 0 and CurrentPos.Y < Size.Y and CurrentPos.Y >= 0 and CopiedMap[CurrentPos.Y][CurrentPos.X] != 6)
	{
		CopiedMap[CurrentPos.Y][CurrentPos.X] = 7;
		CurrentPos.X = CurrentPos.X + Direction[IndexOfDirection].X;
		CurrentPos.Y = CurrentPos.Y + Direction[IndexOfDirection].Y;
	}
}

void MarkCamArea(Camera const& Cam, vector<vector<int>>& CopiedMap)
{
	//Cam�� ������ ���� �� ���� ��� �Լ� ȣ��
	if (Cam.Type == 5)
	{
		for (int i = 0; i < 4; i++)
		{
			MarkAsDirection(i, Cam.Pos, CopiedMap);
		}
	}
	if (Cam.Type == 4)
	{
		for (int i = 0; i < 2; i++)
		{
			MarkAsDirection((i + Cam.Direction) % 4, Cam.Pos, CopiedMap);
		}
		MarkAsDirection((Cam.Direction + 3) % 4, Cam.Pos, CopiedMap);
	}
	if (Cam.Type == 3)
	{
		for (int i = 0; i < 2; i++)
		{
			MarkAsDirection((i + Cam.Direction) % 4, Cam.Pos, CopiedMap);
		}
	}
	if (Cam.Type == 2)
	{
		MarkAsDirection(Cam.Direction, Cam.Pos, CopiedMap);
		MarkAsDirection((Cam.Direction + 2) % 4, Cam.Pos, CopiedMap);
	}
	if (Cam.Type == 1)
	{
		MarkAsDirection(Cam.Direction, Cam.Pos, CopiedMap);
	}
}

int CheckBlindArea(vector<Camera> const& NewCamSet)
{
	vector<vector<int>> CopiedMap = Map;
	//�־��� �� ī�޶�¿� ���� ���ñ��� ��ŷ
	for (Camera const& Elem : NewCamSet)
	{
		MarkCamArea(Elem, CopiedMap);
	}

	int Result = 0;
	for (int y = 0; y < Size.Y; y++)
	{
		for (int x = 0; x < Size.X; x++)
		{
			if (CopiedMap[y][x] == 0)
			{
				Result++;
			}
		}
	}
	return Result;
}

void BackTracking(int const CurrentCamIndex, vector<Camera> NewCamSet, vector<Camera> const& CameraSet)
{
	if (NewCamSet.size() == CameraSet.size())
	{
		MinBlindArea = min(MinBlindArea, CheckBlindArea(NewCamSet));
		return;
	}
	Camera NextSet = CameraSet[CurrentCamIndex];

	if (NextSet.Type == 5)
	{
		NewCamSet.push_back(NextSet);
		BackTracking(CurrentCamIndex + 1, NewCamSet, CameraSet);
		NewCamSet.pop_back();
	}
	else if (NextSet.Type == 2)
	{
		NextSet.Direction = 0;
		NewCamSet.push_back(NextSet);
		BackTracking(CurrentCamIndex + 1, NewCamSet, CameraSet);
		NewCamSet.pop_back();

		NextSet.Direction = 1;
		NewCamSet.push_back(NextSet);
		BackTracking(CurrentCamIndex + 1, NewCamSet, CameraSet);
		NewCamSet.pop_back();
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			NextSet.Direction = i;
			NewCamSet.push_back(NextSet);
			BackTracking(CurrentCamIndex + 1, NewCamSet, CameraSet);
			NewCamSet.pop_back();
		}
	}


}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	vector<Camera> CameraSet{};

	cin >> Size.Y >> Size.X;
	Map.resize(Size.Y);
	for (int y = 0; y < Size.Y; y++)
	{
		Map[y].resize(Size.X);
		for (int x = 0; x < Size.X; x++)
		{
			cin >> Map[y][x];

			if (Map[y][x] != 0 and Map[y][x] != 6)
			{
				CameraSet.push_back({ Map[y][x], {x,y}, 0 });
			}
		}
	}
	vector<Camera> NewCameraSet{};
	BackTracking(0, NewCameraSet, CameraSet);
	cout << MinBlindArea;
	return 0;
}