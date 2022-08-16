#include<iostream>
#include<queue>
using namespace std;

/*
9095 - 1, 2, 3 ���ϱ�
��� ���� 123�� ������ ���ϴ� ����� �� ������ ã�´�

���
���� 123�� ť�� ����
ť�� ���� ����
���� ť���� �� ���� ���� ����� Count++
���� �ʰ��ߴٸ� �׳� pop
�� �̸��̶�� �ٽ� 123�� ���� ���ؼ� ����
������
count ����Ʈ
*/
queue<int> MakeNums{};
void Push(int const SrcNum)
{
	MakeNums.push(SrcNum + 1);
	MakeNums.push(SrcNum + 2);
	MakeNums.push(SrcNum + 3);
}
void Solution(int const TargetNum)
{
	int count = 0;

	Push(0);
	while (!MakeNums.empty())
	{
		int CurrentNum = MakeNums.front();
		MakeNums.pop();
		if (CurrentNum == TargetNum)
			count++;
		else if (CurrentNum < TargetNum)
			Push(CurrentNum);
	}
	cout << count << "\n";

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int TestCase = 0;
	cin >> TestCase;

	while (TestCase--)
	{
		int InputNum = 0;
		cin >> InputNum;
		Solution(InputNum);
	}

	return 0;
}