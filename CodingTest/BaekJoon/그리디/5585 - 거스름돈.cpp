/*
 *5585 - �Ž�����
 *
 *�׸���� �����Ѵ� ���� ū������ �������鼭 ī��Ʈ�� ������Ų��
 *
 *������ 1���� ��� ������ ���ٸ� �ش� ī��Ʈ�� �����ذ� �ȴ�.
 */
#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int Coin[6] = { 500,100,50,10,5,1 };
	int N = 0, Index = 0, Count = 0;
	int Change = 0;
	cin >> N;
	Change = 1000 - N;
	while (Index < 6)
	{
		if (Change < Coin[Index])
		{
			Index++;
			continue;
		}
		Change -= Coin[Index];
		Count++;
	}
	cout << Count;

	return 0;
}