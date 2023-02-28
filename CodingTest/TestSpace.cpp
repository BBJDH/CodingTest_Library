/*
 *1996 - 프린터 큐
 *
 *단순 우선순위에 따라 프린트 되는 순서를 출력하는것으로 접근하여
 *
 *우선순위 큐로 풀고자 시도하였으나
 *
 *예외상황이 존재했다
 *
 *6 0 
 *1 1 9 1 1 1 인 경우 우선순위큐로는 오답을 출력한다.
 *(1이 루트로 기록되었다가 9가 삽입되는순간 9와 1위치가 스왑된다.)
 *
 *따라서 요구사항대로 Pop과 Push를 해주어야 한다.
 *
 *이를위해 실시간으로 다음 프린트 숫자를 알리는 우선순위 큐와,
 *해당 우선순위와 입력받았을때 등록된 인덱스를 가지는 큐를 따로 작성하여 관리한다.
 *
 *우선순위 큐를 보며 다음 프린드될 우선순위를 확인하고
 *프린터큐에서 Pop과 푸시를 목표 인덱스가 나올 때까지 반복한다.
 *
 *이후 이 프린트 수를 출력한 후 종료
 *
 *
 *
 *가독성, 모듈화, 유지보수를 위한 코딩 고민을 해봤다. 
 *반복문에 쓸 반복 조건을 기술하다가 이러한 bool반환이 복잡한 경우
 *가독성이 좋고 유지보수가 편한 코드를 고민했다.
 *
 *이번 반복문의 목표는 어떤 조건을 찾을 때까지 반복문을 Loop해야 하므로
 *함수 사용자 입장에서 보기 편하게 반복문의 EndCondition에서 접근했다.
 *EndCondtion을 먼저 기술하고 이것의 Not처리하면 반복문을 순환하는 조건이 완성된다.
 *이런방식이 어쩌면, 다른사람이 보기에도 편한 코드가 아닐까?
 *
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node
{
	int Num;
	int Index;
};

bool operator>(Node const & Left, Node const& Right)
{
	return Left.Num > Right.Num;
}
bool operator<(Node const& Left, Node const& Right)
{
	return Left.Num < Right.Num;
}

bool IsFindingTarget(queue<Node> const& PrinterQueue, priority_queue<int, vector<int>> const & DescendingOrder_PQ, int const IndexOfTarget )
{
	//반복문 조건을 서술 - 반복문의 EndCondition을 기술하고 이것의 Not을 Return해 반복문의 Loop 유무를 알림
	
	bool EndCondition = true;
	EndCondition &= IndexOfTarget == PrinterQueue.front().Index;			//타겟인덱스를 찾은상황 이면서
	EndCondition &= PrinterQueue.front().Num >= DescendingOrder_PQ.top();	//뒤에 큰수가 없는상황이면 종료
	return not EndCondition; //종료 조건의 반대여야 하므로 not 처리
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int TestCase = 0;
	cin >> TestCase;
	while (TestCase--)
	{
		int N = 0, IndexOfTarget=0,CountOfPrint=0;
		cin >> N >> IndexOfTarget;

		priority_queue<int, vector<int>> DescendingOrder_PQ{};
		queue<Node> PrinterQueue{};

		for(int i=0; i<N; i++)
		{
			int inputNum = 0;
			cin >> inputNum;
			DescendingOrder_PQ.push(inputNum);
			PrinterQueue.push({ inputNum ,i });
		}

		while (IsFindingTarget(PrinterQueue, DescendingOrder_PQ, IndexOfTarget))
		{
			Node const Current = PrinterQueue.front();
			PrinterQueue.pop();
			if(Current.Num == DescendingOrder_PQ.top())
			{
				DescendingOrder_PQ.pop();
				CountOfPrint++;

				continue;
			}
			PrinterQueue.push(Current);
		}
		cout << CountOfPrint + 1<<"\n";
	}



	return 0;
}