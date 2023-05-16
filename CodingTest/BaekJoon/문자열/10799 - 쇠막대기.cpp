/*
 * 10799 - 쇠막대기
 *
 *요구사항그대로 문자열을 파싱하여 구현을 통해 풀었다
 *"()"가 절단부를 의미하므로 이 지점까지 쌓어있는 파이프 수와
 *이미 잘려진 파이프 수를 카운팅하고 "()"에서 쌓인 파이프 수를 누적하는 방식이다.
 *
 *입력받은 문자열의 맨 왼쪽부터 접근한다
 *
 *현재 위치를 CurrentPos라 하고 다음 위치를 NextPos로 한다
 *(이 위치는 파이프가 잘리는 위치를 의미한다)
 *()부분을 찾아 NextPos에 저장하고 NextPos까지
 *'('를 만난다면 잘릴 파이프의 갯수를 증가하고
 *')'를 만난다면 파이프의 끝단을 의미하므로 Result를 증가시킨다
 *후에 NextPos까지 절차를 완료하였다면 현재 잘릴 파이프의 갯수 또한 Result에 추가한다.
 *
 *이것을 반복하여 find()가 Npos를 반환한다면 NextPos를 문자열의 사이즈로 지정하여
 *문자열 끝까지 무사히 처리토록 하고 Result를 출력해 종료한다.
 *
 *다른 풀이방법으로 오른쪽부터 집어넣은 스택을 통해서도 풀이가 가능하다.
 *
 */


#include <iostream>
#include <string>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int NumOfoverlappingPipe = 0;
	int CurrentPos = 0, Result = 0;

	string StrOfInput{};
	cin >> StrOfInput;

	while (CurrentPos < StrOfInput.size())
	{
		size_t NextPos = StrOfInput.find("()", CurrentPos);

		if (StrOfInput.find("()", CurrentPos) == string::npos)
		{
			NextPos = StrOfInput.size();
		}
		while (CurrentPos < NextPos)
		{
			if (StrOfInput[CurrentPos] == '(')
			{
				NumOfoverlappingPipe++;
			}
			else
			{
				NumOfoverlappingPipe--;
				Result++;
			}
			CurrentPos++;
		}
		Result += NumOfoverlappingPipe;
		CurrentPos = static_cast<int>(NextPos) + 2;
	}

	cout << Result;
	return 0;
}