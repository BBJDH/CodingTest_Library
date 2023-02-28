/*
 *1996 - ������ ť
 *
 *�ܼ� �켱������ ���� ����Ʈ �Ǵ� ������ ����ϴ°����� �����Ͽ�
 *
 *�켱���� ť�� Ǯ���� �õ��Ͽ�����
 *
 *���ܻ�Ȳ�� �����ߴ�
 *
 *6 0 
 *1 1 9 1 1 1 �� ��� �켱����ť�δ� ������ ����Ѵ�.
 *(1�� ��Ʈ�� ��ϵǾ��ٰ� 9�� ���ԵǴ¼��� 9�� 1��ġ�� ���ҵȴ�.)
 *
 *���� �䱸���״�� Pop�� Push�� ���־�� �Ѵ�.
 *
 *�̸����� �ǽð����� ���� ����Ʈ ���ڸ� �˸��� �켱���� ť��,
 *�ش� �켱������ �Է¹޾����� ��ϵ� �ε����� ������ ť�� ���� �ۼ��Ͽ� �����Ѵ�.
 *
 *�켱���� ť�� ���� ���� ������� �켱������ Ȯ���ϰ�
 *������ť���� Pop�� Ǫ�ø� ��ǥ �ε����� ���� ������ �ݺ��Ѵ�.
 *
 *���� �� ����Ʈ ���� ����� �� ����
 *
 *
 *
 *������, ���ȭ, ���������� ���� �ڵ� ����� �غô�. 
 *�ݺ����� �� �ݺ� ������ ����ϴٰ� �̷��� bool��ȯ�� ������ ���
 *�������� ���� ���������� ���� �ڵ带 ����ߴ�.
 *
 *�̹� �ݺ����� ��ǥ�� � ������ ã�� ������ �ݺ����� Loop�ؾ� �ϹǷ�
 *�Լ� ����� ���忡�� ���� ���ϰ� �ݺ����� EndCondition���� �����ߴ�.
 *EndCondtion�� ���� ����ϰ� �̰��� Notó���ϸ� �ݺ����� ��ȯ�ϴ� ������ �ϼ��ȴ�.
 *�̷������ ��¼��, �ٸ������ ���⿡�� ���� �ڵ尡 �ƴұ�?
 *
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node
{
	int Num;
	int Index;
};

bool operator>(Node const & Left, Node const& Right)
{
	return Left.Num > Right.Num;
}
bool operator<(Node const& Left, Node const& Right)
{
	return Left.Num < Right.Num;
}

bool IsFindingTarget(queue<Node> const& PrinterQueue, priority_queue<int, vector<int>> const & DescendingOrder_PQ, int const IndexOfTarget )
{
	//�ݺ��� ������ ���� - �ݺ����� EndCondition�� ����ϰ� �̰��� Not�� Return�� �ݺ����� Loop ������ �˸�
	
	bool EndCondition = true;
	EndCondition &= IndexOfTarget == PrinterQueue.front().Index;			//Ÿ���ε����� ã����Ȳ �̸鼭
	EndCondition &= PrinterQueue.front().Num >= DescendingOrder_PQ.top();	//�ڿ� ū���� ���»�Ȳ�̸� ����
	return not EndCondition; //���� ������ �ݴ뿩�� �ϹǷ� not ó��
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int TestCase = 0;
	cin >> TestCase;
	while (TestCase--)
	{
		int N = 0, IndexOfTarget=0,CountOfPrint=0;
		cin >> N >> IndexOfTarget;

		priority_queue<int, vector<int>> DescendingOrder_PQ{};
		queue<Node> PrinterQueue{};

		for(int i=0; i<N; i++)
		{
			int inputNum = 0;
			cin >> inputNum;
			DescendingOrder_PQ.push(inputNum);
			PrinterQueue.push({ inputNum ,i });
		}

		while (IsFindingTarget(PrinterQueue, DescendingOrder_PQ, IndexOfTarget))
		{
			Node const Current = PrinterQueue.front();
			PrinterQueue.pop();
			if(Current.Num == DescendingOrder_PQ.top())
			{
				DescendingOrder_PQ.pop();
				CountOfPrint++;

				continue;
			}
			PrinterQueue.push(Current);
		}
		cout << CountOfPrint + 1<<"\n";
	}



	return 0;
}