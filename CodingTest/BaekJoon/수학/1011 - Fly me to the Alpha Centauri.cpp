/*
 *1011 - Fly me to the Alpha Centauri
 *
 *ó������ BFS�� ���� ��ġ�� Dest�� ��ġ�ϰ� �ӵ��� 0�̶�� �������� ó���ߴ�.
 *
 *������ �������� 2^31�� �޸� �ʰ��� �߻�,
 *
 *�ٸ� ���� ����� ã�ƺ���� �ߴ�.
 *	(+1�� �Ǵ� ����)
 *�̵��Ÿ��� 1(1) �̶�� 1�� 1				- ���� �������� 0*2+1
 *�̵��Ÿ��� 2(O) �̶�� 2�� 1 1				- ������ 1�� ���� +1
 *�̵��Ÿ��� 3(O) �̶�� 3�� 1 1 1		- ������ 1�� 4������ 2�� ���� +1
 *�̵��Ÿ��� 4(X) ���   3�� 1 2 1			- ������ ����
 *�̵��Ÿ��� 5(O) ���   4�� 1 2 1 1			- ������ 4�� ����
 *�̵��Ÿ��� 6(X) �̶�� 4�� 1 2 2 1			- ������ ����
 *�̵��Ÿ��� 7(O) �̶�� 5�� 1 2 2 1 1		- 4�� 9 ������ 6�� ����
 *�̵��Ÿ��� 8(X) �̶�� 5�� 1 2 2 2 1		- ������ ����
 *�̵��Ÿ��� 9(X) �̶�� 5�� 1 2 3 2 1		- ������ ����
 *�̵��Ÿ��� 10(O) �̶�� 6�� 1 2 3 2 1 1		- ������ 9�� ����
 *�̵��Ÿ��� 11(X) �̶�� 6�� 1 2 3 2 2 1		- ������ ����
 *�̵��Ÿ��� 12(X) �̶�� 6�� 1 2 3 3 2 1		- ������ ����
 *�̵��Ÿ��� 13(O) �̶�� 7�� 1 2 3 3 2 1		- ������ 9�� 16 ������ 12�� ����
 *
 * ...
 *
 *���� ���� �������� �������� �������� ���������� ���������� �̵��Ÿ��� 1�� �þ��
 *�� ���� ���� ������ �Ÿ��� Distance��� �Ѵٸ�,
 *
 *Distance�� �������� SqrtOfDistance�� ���ϰ�,
 *(SqrtOfDistance-1)*2+1�� �̵��Ÿ��� ����� �д�.
 *���� ���� Distance�� SqrtOfDistance�� ������ �����ٸ� +1
 *SqrtOfDistance�� SqrtOfDistance+1�� ������ �������� �����ٸ� +1
 *ó���Ͽ� ����Ѵ�.
 *
 *�Է� �޴� �Ÿ��� 2�� 31���� �� ���ɼ��� �ִ� ���� ���� �� ���ϴ� int �ڷ����� �����÷ο찡 �߻��� �� �ִ�.
 *������ SqrtOfDistance*SqrtOfDistance�� �ƴ� double�� ��ȯ�ϴ� pow�Լ��� �̿���
 *����� �Ϸ��ϰ� �� ���� int�� ĳ�����ߴ�.
 *
 */

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int TestCase = 0;
	cin >> TestCase;
	while (TestCase--)
	{
		int Start = 0, Dest = 0, Result = 0;
		int SqrtOfDistance = 0, Distance = 0;
		int NumOfMiddle = 0;
		cin >> Start >> Dest;
		Distance = Dest - Start;
		SqrtOfDistance = static_cast<int>(sqrt(Distance));
		NumOfMiddle = static_cast<int>((pow(SqrtOfDistance, 2) + pow(SqrtOfDistance + 1, 2)) / 2);
		Result = (SqrtOfDistance - 1) * 2 + 1;

		if (Distance > pow(SqrtOfDistance, 2))
		{
			Result++;
		}
		if (Distance > NumOfMiddle)
		{
			Result++;
		}

		cout << Result << "\n";
	}

	return 0;
}