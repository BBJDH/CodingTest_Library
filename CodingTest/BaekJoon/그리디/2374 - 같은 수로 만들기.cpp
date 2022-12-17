/*
 *2374 - 같은 수로 만들기
 *
 *제일 큰 max 수 그리디로 채택된 비교수 하나를 사용한다
 *
 *다른분들은 스택과 분할정복을 사용하시기도 했지만.. 사실 필요치 않다 정수 하나로 처리가능하다
 *
 *
 *
 *순차적으로 수를 받으며 max를 업데이트, (추후에 사용)
 *
 *비교할 숫자 하나를 만들어두고 진행한다
 *
 *비교할 숫자의 조건
 *
 *비교할 숫자가 0(설정되어있지 않다면)이라면 비교할수 cmpNum에 설정
 *
 *다음수가 더 크다면 cmpNum와의 차를 result에 추가, cmpNum 업데이트
 *
 *다음수가 더 작다면 cmpNum를 업데이트
 *
 *마지막에 위에서 업데이트한 max와 cmNum의 차를 더함
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