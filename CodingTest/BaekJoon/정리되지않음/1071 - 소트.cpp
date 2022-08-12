#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> InputNums{};

/*
���� ���� ����
�� ������ �ٽ� �迭�� ����,

ù������ ����
������� �������� ���ٸ�
{
	������ ī��Ʈ, ���� �ε����� �Ѿ
}
���� ���� ���
{
	�������� +1�̶��
	{
		+2 �̻��� �ִ��� �˻�
		{
			�����Ѵٸ� �������� +2 ���� ����
			�����ε����� �Ѿ
		}
		+2 �̻��� �������� �ʴ´ٸ�(+1���� �������Ƿ� �� ������ �ߺ����������� Ȯ�����ָ� �ȴ�)
		{
			����� ������ ������ ������ ����
			������ ���ͷ����� =  lower_bound(�ε���-ī��Ʈ, ������, �ε��� ����)
			ū�� ���ͷ����� = upper_bound(�ε���+1, ������, �ε��� ����) ã�Ƶΰ�
			�ݺ���(ū�� ���ͷ����Ͱ� �ʰ��ϱ� ������) ����(������, ū��)
			���ͷ����͵� �÷���,
			�Ϸ�� break
		}
	}
	�������� +1�� �ƴ϶��
	{
		�׳� ���, �ε��� ����
	}
	ī��Ʈ �ʱ�ȭ
}

*/
void Sort()
{
	int Index = 0;
	int Count = 0;
	while (Index < InputNums.size() - 1)
	{
		if (InputNums[Index] == InputNums[Index + 1])
		{
			Count++;
			Index++;
		}
		else
		{
			if (InputNums[Index + 1] == InputNums[Index] + 1)
			{
				auto Iter_PlusTwoValue = upper_bound(InputNums.begin() + Index, InputNums.end(), InputNums[Index + 1]);
				if (Iter_PlusTwoValue != InputNums.end())
				{
					swap(InputNums[Index + 1], *Iter_PlusTwoValue);
					Index++;
				}
				else
				{
					auto Iter_Smaller = lower_bound(InputNums.begin() + Index - Count, InputNums.end(), InputNums[Index]);
					auto Iter_Bigger = upper_bound(InputNums.begin() + Index + 1, InputNums.end(), InputNums[Index]);
					while (Iter_Bigger != InputNums.end())
					{
						swap(*Iter_Smaller, *Iter_Bigger);
						Iter_Smaller++;
						Iter_Bigger++;
					}
					break;
				}
			}
			else
			{
				Index++;
			}
			Count = 0;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int InputCount = 0;

	cin >> InputCount;


	while (InputCount--)
	{
		int Input = 0;
		cin >> Input;
		InputNums.push_back(Input);
	}
	sort(InputNums.begin(), InputNums.end());
	Sort();
	for (int const& elem : InputNums)
		cout << elem << " ";
	return 0;
}
