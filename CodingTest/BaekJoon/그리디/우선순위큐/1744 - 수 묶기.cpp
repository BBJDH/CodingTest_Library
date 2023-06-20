/*
 *1744 - �� ����
 *
 *�켱���� ť �ΰ��� �̿��� �׸���� Ǯ����.
 *
 *������ �ΰ� �̻� �����Ѵٸ� ���� ���Ͽ� ����� ���� �� �ִ�.
 *�Ǵ� ������ 1���� ������ �� 0�� �����Ѵٸ� �� ���� ���Ͽ� 0�� ����� �ִ�.
 *�������� ���ϴ� ��� ���� ���� �������� ���ؾ� ���� ū ����� ����� ���� �� �ִ�.
 *�׸��� ���Ŀ� 0�� �������ų� Ȧ�� ������ ������ ���� ū �����̾�� ���� ū ���� ���� �� �ִ�.
 *
 *���� 0�� ������ �����Ͽ� ���� ���� ������ ���������� �켱���� ť�� �ۼ��Ѵ�.
 *�׸��� ���������� �μ��� ������� ���� ���ϰ� ������ �ϳ����� ��Ҹ� ���ϸ� �ȴ�.
 *
 *
 *����� ��� �ٸ� ���ܰ� �����Ѵ�
 *
 *���� ����� ������ �켱����ť�� �ۼ��ϵ�, ���� ū ������ ������������ �ۼ��Ѵ�.
 *
 *�� ��, 2 1 1 �� ���������� ��쿡 ��������
 *1�� �����Ͽ� ���� ���´ٸ� 1��ŭ �ִ밪�� �𿩳�����
 *
 *���� �� ���� ������ �� �� �ϳ��� 1�̶�� �� �� ��� �����ʰ� ���Ѵ�.
 *
 *���� ������ ��� �����ϸ� ������ Result�� ����Ѵ�.
 *
 */


#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	priority_queue<int, vector<int>, greater<>> MinusFirst{};
	priority_queue<int > PlusFirst{};
	int Size = 0;
	int Result = 0;
	cin >> Size;
	while (Size--)
	{
		int InputNum = 0;
		cin >> InputNum;
		if (InputNum <= 0)
		{
			MinusFirst.push(InputNum);
			continue;
		}
		PlusFirst.push(InputNum);
	}



	while (not MinusFirst.empty())
	{
		if (MinusFirst.size() > 1)
		{
			int const FirstNum = MinusFirst.top();
			MinusFirst.pop();
			int const SecondNum = MinusFirst.top();
			MinusFirst.pop();
			Result += FirstNum * SecondNum;
			continue;
		}

		Result += MinusFirst.top();
		MinusFirst.pop();
	}

	while (not PlusFirst.empty())
	{
		if (PlusFirst.size() > 1)
		{
			int const FirstNum = PlusFirst.top();
			PlusFirst.pop();
			int const SecondNum = PlusFirst.top();
			PlusFirst.pop();

			if (FirstNum == 1 or SecondNum == 1)
			{
				Result += FirstNum;
				Result += SecondNum;
				continue;
			}

			Result += FirstNum * SecondNum;
			continue;
		}

		Result += PlusFirst.top();
		PlusFirst.pop();
	}
	cout << Result;
	return 0;
}
