/*
 *
 *17478 - 재귀함수가 뭔가요?
 *
 *주어진 요구사항대로 재귀함수를 구현한다.
 *
 *-가 아니라 _를 출력해야한다.
 *현재 재귀깊이에 맞게 _를 함수를 따로 작성하여 재사용했다.
 *
 *현재 깊이 목표 깊이를 잘 전달해준다면 무사히 정답을 받을 수 있다.
 *
 *문제 특성상 오타에 유의하자...
 *
 */


#include <iostream>

using namespace std;

void PrintHyphen(int const Count)
{
	int PrintCount = Count * 4;
	while (PrintCount--)
	{
		cout << "_";
	}
}

void Recursive(int const CurrentCount, int const& MaxCount)
{
	PrintHyphen(CurrentCount);
	cout << "\"재귀함수가 뭔가요?\"\n";

	if (CurrentCount == MaxCount)
	{
		PrintHyphen(CurrentCount);
		cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
		PrintHyphen(CurrentCount);
		cout << "라고 답변하였지.\n";
		return;
	}

	PrintHyphen(CurrentCount);
	cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";

	PrintHyphen(CurrentCount);
	cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";

	PrintHyphen(CurrentCount);
	cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";

	Recursive(CurrentCount + 1, MaxCount);

	PrintHyphen(CurrentCount);
	cout << "라고 답변하였지.\n";
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int CountOfRecusive = 0;
	cin >> CountOfRecusive;
	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
	Recursive(0, CountOfRecusive);

	return 0;
}