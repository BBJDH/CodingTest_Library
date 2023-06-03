#include<iostream>
#include<math.h>
#include<bitset>

using namespace std;

/*
max =10, min 1
�ִ� �������� 3
2~ max���� �ּ� ���������� �ִ� ������ ���� ��ŷ ����
1 2 3 5 6 7 10
*/

bitset<1000001> IsExist{};
//min + 1,000,000 �̹Ƿ� +1�� �ʿ��ϴ� 0~1,000,000 �� 1,000,001�� ��Ʈ�� �ʿ��Ѽ�
long long Min = 0, Max = 0;
long long End = 0;// max�� ���� ������ �ִ� ����

/*
i�� 2���� ����, End���� ����
�������� �������� �� �ִ� �ּ��� ������ ã�ƾ� ��
min�� i�� �������� ���� �� ShareNum ����(���� min�� �۾Ƽ� ���� 0�̶�� 1�� ����)
�ݺ��� ���� (�ش� ShareNum�� ���Ͽ� +1�����ϸ� Max���� ���������� �ش� ���� ��ũ)
{
}
*/
void MarkExist()
{
	for (long long i = 2; i <= End; i++)
	{
		long long ShareNum = (Min / (i * i));
		if (ShareNum * (i * i) < Min) ShareNum++;	//���ۼ��� Min���� �۴ٸ� ShareNum ������Ű�� ����

		while (ShareNum * i * i <= Max)
		{
			//��ŷ�� ShareNum *i*i -  min���� ���
			IsExist.set(ShareNum * i * i - Min);
			ShareNum++;
		}
	}
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> Min >> Max;
	End = static_cast<int>(sqrt(Max));

	MarkExist();

	cout << static_cast<int>(Max - Min + 1 - IsExist.count());

	return 0;
}
