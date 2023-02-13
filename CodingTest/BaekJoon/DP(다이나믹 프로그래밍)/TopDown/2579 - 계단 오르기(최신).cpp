/*
 * 2579 - ��� ������
 *
 *��Ʈ��ŷ���� ��� ������ �����ϰ� �ִ밪�� �����Ϸ��� �õ�������,
 *�ð��ʰ��� �����ߴ�
 *
 *���� DP�� �̿��� �ð��� �����ϱ�� �����ߴ�
 *
 *BottomUp���� Ǭ�ٸ�
 *DP[1] ������ �ִ밪 = ��� �ϳ� ����� ��
 *DP[2] ������ �ִ밪 = ��� �ΰ� ����� ��
 *DP[3] ������ �ִ밪 = max(DP[i-2],DP[i-1]) + Stair[i]
 *DP[4] ������ �ִ밪 = max(DP[i-2],DP[i-1]) + Stair[i]
 *...
 *�̷� ������ Ǯ����� �ȴ�.
 *
 *������ �������� TopDown���� Ǯ���� �ߴ�.
 *
 *�Դٰ� ������ 0���κ����� ȣ���� �ƴ� N���� ���� ȣ��� TopDown�� Ǯ���.
 *
 *TopDown�� ��������, �̹� ���� ���� ��ȯ, ����� �� ó���� �ؾ����� �������
 *
 *����� -1 ���� �����ϹǷ� ������ 0�� ����� �Ѱ� �־��ְ� �����Ѵ�.
 *(���������� �ٷ� �� ����� ��� �Ǵ� ���)
 *
 *
 */

#include<iostream>
#include <vector>

using namespace std;

vector<int> Stairs{};
int DP[301]{};
int MaxScore = 0;
int N = 0;

//���� ��������, ���� ����
int MakeDP(int Pos)
{
	//Ż������
	if (Pos < 1)
	{
		return 0;
	}
	//�̹� ���Ȱ��� �ִٸ� ��ȯ
	if (DP[Pos] != 0)
	{
		return DP[Pos];
	}

	//1ĭ �ǳ� �ٴ� ���
	DP[Pos] = max(DP[Pos], MakeDP(Pos - 2) + Stairs[Pos]);
	//�������� ��� ���
	DP[Pos] = max(DP[Pos], MakeDP(Pos - 3) + Stairs[Pos - 1] + Stairs[Pos]);

	return DP[Pos];
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	Stairs.push_back(0);

	for (int i = 0; i < N; i++)
	{
		int input = 0;
		cin >> input;
		Stairs.push_back(input);
	}
	MakeDP(N);
	cout << DP[N];
	return 0;
}

