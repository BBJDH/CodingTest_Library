/*
 *2374 - ���� ���� �����
 *
 *���� ū max �� �׸���� ä�õ� �񱳼� �ϳ��� ����Ѵ�
 *
 *�ٸ��е��� ���ð� ���������� ����Ͻñ⵵ ������.. ��� �ʿ�ġ �ʴ� ���� �ϳ��� ó�������ϴ�
 *
 *
 *
 *���������� ���� ������ max�� ������Ʈ, (���Ŀ� ���)
 *
 *���� ���� �ϳ��� �����ΰ� �����Ѵ�
 *
 *���� ������ ����
 *
 *���� ���ڰ� 0(�����Ǿ����� �ʴٸ�)�̶�� ���Ҽ� cmpNum�� ����
 *
 *�������� �� ũ�ٸ� cmpNum���� ���� result�� �߰�, cmpNum ������Ʈ
 *
 *�������� �� �۴ٸ� cmpNum�� ������Ʈ
 *
 *�������� ������ ������Ʈ�� max�� cmNum�� ���� ����
 *
 *
 *
 *
 */


#include <stdio.h>
int main()
{
	int N = 0;
	int cmpNum = 0;
	int maxNum = 0;
	long long result = 0;
	scanf("%d", &N);
	while (N--)
	{
		int InputNum = 0;
		scanf("%d", &InputNum);
		if (maxNum < InputNum)
			maxNum = InputNum;
		if (cmpNum == 0)
		{
			cmpNum = InputNum;
			continue;
		}
		if (cmpNum < InputNum)
			result += InputNum - cmpNum;
		cmpNum = InputNum;
	}
	printf("%lld", result + (maxNum - cmpNum));
	return 0;
}