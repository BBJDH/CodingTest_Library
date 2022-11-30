/*
 *18111 - ����ũ����Ʈ
 *
 *����ϳ��� ĳ�� ��� - 2��
 *����ϳ��� ä��� ��� - 1��
 *
 *
 *�ּҳ��� 0���� �ִ� ���̴� ����� �ִ� ���̷� ������ �ϵ�,
 *���� ����� 0�ΰ�츦 ����Ͽ� ����ó���� ����
 *
 */

#include <iostream>

using namespace std;

int N = 0, M = 0, B = 0;
int Map[500][500]{};


int CalcTime(int const Num)
{
	if (Num > 0)
		return Num;
	else
		return Num * (-2);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> B;

	int sumBlock = 0;
	int maxHeight = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			int inputNum = 0;
			cin >> inputNum;
			sumBlock += inputNum;
			Map[x][y] = inputNum;
			maxHeight = max(maxHeight, inputNum);
		}
	}

	int minTime = 1234567891;
	int maxBlock = (sumBlock + B) / (N * M);
	int resultHeight = 0;
	for (int currnet = maxHeight; currnet >= 0; currnet--)
	{
		//if (currnet > maxHeight)
		//	break;
		if (currnet > maxBlock) continue;

		int totalTime = 0;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				totalTime += CalcTime(currnet - Map[x][y]);
			}
		}

		if (minTime > totalTime)
			resultHeight = currnet;
		minTime = min(minTime, totalTime);
	}

	cout << minTime << " " << resultHeight;
	return 0;
}