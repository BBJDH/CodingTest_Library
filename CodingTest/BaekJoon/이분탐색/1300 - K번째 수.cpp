/*
 *1300 - K번째 수
 *
 *3
 *
 *1 2 3
 *2 4 6
 *3 6 9
 *1 2 3 4 5 6 7 8 9 개
 *1 2 2 3 3 4 6 6 9
 *5
 *
 *1 2 3 4 5
 *2 4 6 8 10
 *3 6 9 12 15
 *4 8 12 16 20
 *5 10 15 20 25
 *
 *1 2 3 4 5 6 7 8 9 10 11 12 13 14 15  16  17  18  19  20  21  22  23  24  25
 *1 2 2 3 3 4 4 4 5 5  6  6  8  8  9   10  10  12  12  15  15  16  20  20  25
 *
 *
 * 5*5 크기로 입력받은 수중에 예를 들어 10에 대해 이 수가 몇번째 수인지를 검사한다면
 *
 *각 행당 최대 N개의 수가 누적된다 즉
 *첫번째 행은 1의 배수 5개 (1~5)
 *두번째 행은 2의 배수 5개 (2~10)
 *세번째 행은 3의 배수 3개 (3~9)
 *네번째 행은 4의 배수 2개 (4~8)
 *다섯번째 행은 5의 배수 2개 (5~10)
 *
 *즉 번호 10이하의 숫자 갯수는 17개 이다
 *
 *원하는 숫자의 갯수를 찾기위해 이분탐색을 시행한다
 *
 *
 *
 *실제로 16번째 수를 찾아보자
 *
 *범위는 0~ 26으로 시작한다 (0과 26은 탐색범위 숫자가 아니게 설정한다 즉 1~25의 숫자만 탐색된다)
 *
 *left(0) + right(26) 의 반인 13이 선정되고
 *
 *13이하 숫자의 갯수는 위의 계산방법에 의해 19개가 된다
 *복표인 16번째수보다 크므로 mid에 right가 대입, mid 오른쪽은 버려진다
 *다시 left(0) ~ right(13)으로 검색, mid는 6이된다
 *6이하의 갯수는 12개, 이번에는 16번째보다 작다 left를 옮긴다
 *
 *6 ~ 13 으로 검색, 중간은 9가된다
 *9이하의 갯수는 15개, 이번에도 작다, 다시 left를 옮긴다
 *9~13 중간은 11이된다
 *11이하는 17개, 16보다 크다 역시 right를 옮긴다
 *9~11 중간은 10
 *10에서 17이 나온다! 하지만 역시 16보다 크다! right를 옮긴다
 *9~10이므로 더의상 찾을 구획이 존재하지 않는다 (위에서 left와 right는 탐색 범위 밖의 숫자로 설정했다)
 *
 *여기서 이분탐색의 반환을 선택해야 한다 left를 반환할 것인가 right를 반환할 것인가?
 *
 *만약 16이나 17번째 수를 찾고 있었다면? 혹은 그 숫자가 한개뿐이라면?
 *right를 반환하면 위의 예외가 모두 해결된다. 이외에도 만약 찾던 수가 실제 배열에 없는 수일 수도 있다.
 *왜 right인가? 예를들어 11을 생각해보자 배열에는 실제로 10과 12뿐이지만 이분탐색은 11을 찾게될 수도있다
 *왜냐하면 10이하의 숫자들은 17개 지만 11이하의 숫자들도 17개이기 때문이다
 *이를 방지하기위해 해당 숫자 구간의 최소를 탐색한다 11이 되었다면 10도 되지않는지 내려보는것이다
 *불가능해진다면 left를 당겨온다 즉 right는 잠재적인 정해인것처럼 고정되는것이다
 *만약 mid 10에서 충족된다면 right를 mid로 당겨온다 다음 왼쪽 구간에서 유효한 숫자를 찾기 위해서 이다
 *10이 정해라면 왼쪽은 탐색을 모조리 실패하고 left는 9로, right는 10으로 종료된다
 *right는 10으로 반환된다.
 *
 *짧게 요약하자면 B[k]는 B[k-1]까지 이진탐색을 실패만 right가 정해이다
 *(right항상 B[k-1]보다 큰 범위이고 B[k-1]까지는 확실히 숫자 갯수가 충족되지 않으므로 항상 정해는 right이다 )
 *
 *
 */
#include <iostream>

using namespace  std;

long long N = 0;

long long CalcIndex(long long const CurrentNum)
{
	long long count = 0;
	for (long long i = 1; i <= CurrentNum and i <= N; i++)
	{
		count += min(CurrentNum / i, N);
	}

	return count;
}

void BinerySearch(long long const DestIndex)
{
	long long leftNum = 0;
	long long rightNum = N * N + 1;
	long long midNum = 0;

	while (leftNum + 1 < rightNum)
	{
		midNum = (leftNum + rightNum) / 2;
		long long const currentCount = CalcIndex(midNum);

		if (currentCount < DestIndex)
			leftNum = midNum;
		else
			rightNum = midNum;
	}
	cout << rightNum;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	long long dest = 0;
	cin >> N >> dest;

	cin >> dest;
	BinerySearch(dest);


	return 0;
}