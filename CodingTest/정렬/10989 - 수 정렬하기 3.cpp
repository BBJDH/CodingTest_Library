
/*
10989 - �� �����ϱ� 3

N���� ���� ��� �����Ѵٸ� �޸� �ʰ��� �߻��Ѵ�
���� 10000������ �ڿ������� ��Ʈ��
10001�� ¥�� �迭�� ����� �Էµ� ������ŭ ������ָ� �ȴ�
*/
#include<iostream>
#include<algorithm>
using namespace std;

int Arr[10001]{};
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	int  Size = 0;

	cin >> Size;

	while (Size--)
	{
		int  InputNum = 0;
		cin >> InputNum;
		Arr[InputNum]++;
	}

	for (int i = 0; i < 10001; i++)
	{
		for (int j = 0; j < Arr[i]; j++)
		{
			cout << i << "\n";
		}
	}

	return 0;
}