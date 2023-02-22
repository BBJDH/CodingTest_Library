/*
 *11729 - �ϳ��� ž �̵� ����
 *
 *�ϳ���ž�� Ǫ�µ��� ��Ȯ�� ��Ģ�� �����Ѵ�.
 *
 *2���� ������ �Űܺ���
 *
 *1
 *2
 *0 0 0
 *
 *2�� ���ǿ��� �ʿ��� �۾���
 *Start = 1�����, Dest = 3�����, Temp = 2�� ���
 *�̰� �̸� ���� 1�� ������ 2�� ��տ� ���õǾ�� �Ѵ�.
 *�� 1���� Start = 1, Dest = 2, Temp = 3�� �ȴ�.
 *
 *������ ���� 1���� ������ �� �����Ƿ� Dest�� �Ű��ش�
 *
 *2 1
 *0 0 0
 *
 *���� 2���� ���� ������ �� �����Ƿ� �����δ�
 *
 *  1 2
 *0 0 0
 *
 *���� ��ǥ������ 3�� ��տ� �Ű����Ƿ� �ٽ� ���� ������
 *3�� ��տ� �÷��� �Ѵ�
 *�� 1���� 2 ���� �Ű� ���ƾ� �Ѵ�
 *���� =1, Start =2, Dest=3, Temp=1
 *1���� 2������ �ö� ������ ����ȴ�.
 *
 *�����ϰ� �����ϸ�
 *
 *disc=2, Start=1, Dest=3, Temp=2
 *disc=1, Start=1, Dest=2, Temp=3
 *1������ ->Dest�� �̵�
 *2������ ->Dest�� �̵�
 *disc=1, Start=2, Dest=3, Temp=1
 *1������ ->Dest�� �̵�
 *����
 *
 *�̹��� ���� 3�� ¥���� �Ű� ����
 *
 *Disc=3, Start=1, Dest=3, Temp=2 ---- ���� 3������ �̵� ȣ��
 *
 *Disc=2, Start=1, Dest=2, Temp=3 --
 *Disc=1, Start=1, Dest=3, Temp=2  |
 *1������ ->Dest�� �̵�			   |   2�� ������ �̵�����
 *2������ ->Dest�� �̵�			   |
 *disc=1, Start=3, Dest=2, Temp=1 --
 *
 *3������ ->Dest�� �̵�            ---- 3������ �̵�
 *
 *disc=2, Start=2, Dest=3, Temp=1 --
 *disc=1, Start=2, Dest=1, Temp=2  |
 *1������ ->Dest�� �̵�			   |   2�� ������ �̵�����
 *2������ ->Dest�� �̵�			   |
 *disc=1, Start=1, Dest=3, Temp=2 --
 *
 *���� ��Ģ�� ������ ����
 *
 *
 *���� N�� ������ �ű� �� Start=1, Dest=3, Temp=2�� Ȯ���̰�
 *N�� Dest�� �������ؼ���
 *N-1������ ������ Temp ��ġ�� �̵��ؾ� �ϱ� ������
 *N-1 �� Start=N������ Start, Dest=N������ Temp,Temp=N������ Dest �� ������ �ʿ��ϴ�
 *���Ŀ� N�� ������ �ű��(���� �̵� ���)
 *���� �ٽ� N-1�� Temp���� Dest�� �Űܾ� �Ѵ�.
 *�� N-1, Start=N������Temp,Dest=N������Dest,Temp=N������Start�� �ȴ�.
 *
 *�ٸ� N�� 1�ΰ��� ���� ������ �������������Ƿ� �ٷ� �̵������ϴ�.
 *N�� 1�� ���� �ٷ� �̵�ó���Ѵ�.
 *
 *�ϳ���ž�� �ű������ �ּ� �̵� Ƚ���� 2^N-1�̴�
 *
 */

#include <iostream>

using namespace std;

void Hanoi(int const Disc, int const Start, int const Dest, int const Temp)
{
	if (Disc == 1)
	{
		cout << Start << " " << Dest << "\n";
		return;
	}
	Hanoi(Disc - 1, Start, Temp, Dest);
	cout << Start << " " << Dest << "\n";
	Hanoi(Disc - 1, Temp, Dest, Start);

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;
	cin >> N;
	cout << (1 << N) - 1 << "\n";
	Hanoi(N, 1, 3, 2);

	return 0;
}