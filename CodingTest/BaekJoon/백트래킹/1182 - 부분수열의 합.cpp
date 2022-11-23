/*
 *1182 - �κм����� ��
 *
 *
 *�� ��ȣ������ �湮 ��Ʈ�� ����� ��Ʈ��ŷ�� ����
 *�̹� �湮�� ��ȣ�� �̹� �ջ�Ǿ������Ƿ� ȣ��� �ʿ����
 *�κ� ������ ���ǻ� left�� ������ �κ��� ���� �������� �ʴ´�
 *
 */

#include<iostream>
#include <vector>

using namespace std;


vector<int> Sequence{};
int Visit[20]{};

int Size = 0;
int DestNum = 0;
int Count = 0;

void BackTracking(int const StartIndex, int const Sum)
{
	for (int i = StartIndex; i < Size; i++)
	{
		if (Visit[i] == false)
		{
			Visit[i] = true;
			if (Sum + Sequence[i] == DestNum)
				Count++;
			BackTracking(i + 1, Sum + Sequence[i]);
			Visit[i] = false;

		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	cin >> Size >> DestNum;
	int sum = 0;
	for (int i = 0; i < Size; i++)
	{
		int inputNum = 0;
		cin >> inputNum;
		sum += inputNum;
		Sequence.emplace_back(inputNum);
	}
	//�Է� �� ������ ���� �Ϸ�
	BackTracking(0, 0);
	cout << Count;
	return 0;
}