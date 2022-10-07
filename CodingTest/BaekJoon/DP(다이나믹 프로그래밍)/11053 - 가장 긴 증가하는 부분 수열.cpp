#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Sequence{};
vector<int> MaxSize{};


//�迭 ���� i�� ���ؼ� i ������ �ְ� �� ������ ���

void CheckMaxSize()
{
	//�ε��� ������ �ϳ��� �����ϸ�  �ε��� ���� ���� �迭�� �����Ͽ� �ִ� ũ���� ���� ������ Ȯ��
	//�ε����� �������
	//�ڽ��� �ε������� ���� �ε����� ����, �ش� �ε����� �����Ͱ� �ڽź��� �۴ٸ� ����ũ�⸦ �޾ƿ�
	//���� ����ũ�Ⱑ �� ū �ε����� �ִٸ� ���� ũ�⸦ ������Ʈ
	//�ݺ����� ���������� �ڽ��� �ε��������� ���� ũ�⸦ ���� ���� ũ���� +1 �� ����
	//������ �ε������� ����, ����, �ְ� ū ���� ���

	MaxSize.push_back(1);
	for (int i = 1; i < Sequence.size(); i++)
	{
		int SequenceSize = 0;
		for (int j = 0; j < i; j++)
		{
			//i��° ���� J��° ������ ũ�鼭 j��°������ �ִ� ������ ���� ������Ʈ�� ����ũ�⺸�� ũ�ٸ�
			//�̾����
			if (Sequence[i] > Sequence[j] and SequenceSize < MaxSize[j])
				SequenceSize = MaxSize[j];
		}
		MaxSize.push_back(SequenceSize + 1);
	}
	sort(MaxSize.begin(), MaxSize.end());
	cout << *(MaxSize.end() - 1);

}


int main()
{
	int Size = 0;

	cin >> Size;

	for (int i = 0; i < Size; i++)
	{
		int Input_Num = 0;
		cin >> Input_Num;
		Sequence.push_back(Input_Num);
	}
	CheckMaxSize();
	return 0;
}