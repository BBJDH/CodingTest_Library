/*
 *
 *1476 - ��¥ ���
 *
 *��Ϳ� ���Ʈ������ Ǯ����.
 *
 *E, S, M �� ��� (Value % Max) + (Value / Max) ������ ��� �����ϴ�
 *(�̶� Max�� 1�� �Ǵ� ���̴� E�� 16, S�� Max�� 29)
 *
 *������ Value�� �ʹ� Ŀ�� (Value % Max) + (Value / Max) ���� Max�� �Ѿ �� �����Ƿ�
 *�̰��� ��������� ó���ߴ�.
 *
 *������ Value�� ���� E S M �� ���ϴ� �Լ��� ���� ���� ��ͷ� �ۼ��� ��
 *
 *Value�� ���Ʈ������ ���� �ϳ��� �÷����� ���� Ž���Ѵ�.
 *
 *E S M �� ��� ��ġ�ϴ� Value�� ��Ÿ���ٸ� ����ϰ� �����Ѵ�.
 *
 *
 */

#include <iostream>

using namespace std;

int SetNum(int const Value, int const Max)
{
	if (Value < Max)
	{
		return Value;
	}
	int const NextValue = (Value % Max) + (Value / Max);
	return SetNum(NextValue, Max);
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int E = 0, S = 0, M = 0;
	int CurrentNum = 1;
	cin >> E >> S >> M;

	CurrentNum = max(max(E, S), M);
	while (true)
	{
		if (SetNum(CurrentNum, 16) == E and SetNum(CurrentNum, 29) == S and SetNum(CurrentNum, 20) == M)
		{
			cout << CurrentNum;
			break;
		}

		CurrentNum++;
	}


	return 0;
}