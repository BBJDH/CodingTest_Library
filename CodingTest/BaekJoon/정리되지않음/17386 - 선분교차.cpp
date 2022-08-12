#include <iostream>
#include <cassert>
using namespace std;

struct _longlong2
{
	long long _1;
	long long _2;

	long long X() const { return _1; };
	long long Y() const { return _2; };
	//왜 받는 수는 백만까지만 받지만 연산자 호출후 결과값을 저장하면서 백만*백만을 저장하게 될 수 있다
};

struct Vector2D
{
	_longlong2 Start;
	_longlong2 End;
};
/*
먼저 첫번째 입력받은 벡터와 다음 입력 받은 벡터 양 끝점에 대해서 외적
이 두 결과의 곱이 음수라면 첫번째 교차 조건 성립
다시 마찬가지로 두번째 벡터와 첫번째 입력 받은 벡터의 양 끝점에 대해서 외적
이 두 결과의 곱이 음수라면 선분은 서로 교차 혹은 평행하다
하지만 문제는 세점이 일직선에 위치한 경우는 없다고 조건이 걸려있으므로
위의 외적의 결과가 0인 경우는 생략한다
*/

int CCW(_longlong2 const& First, _longlong2 const& Second, _longlong2 const& Third)
{
	long long const Result = First.X() * Second.Y() + Second.X() * Third.Y() + Third.X() * First.Y()
		- (First.X() * Third.Y() + Second.X() * First.Y() + Third.X() * Second.Y());

	assert(Result != 0);

	//백만단위의 수가 곱해지므로 여기서 음수 양수만 판별해서 리턴하자 후에 다시 또 곱해지면
	//오버/언더 플로우 위험이 있다!
	if (Result < 0)
		return -1;
	return 1;
}

bool CheckVectorIntersect(Vector2D const& A, Vector2D const& B)
{
	int FirstCheck = CCW(A.Start, A.End, B.Start) * CCW(A.Start, A.End, B.End);
	int SecondCheck = CCW(B.Start, B.End, A.Start) * CCW(B.Start, B.End, A.End);
	if (FirstCheck < 0 and SecondCheck < 0)
		return true;
	return false;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	Vector2D A{}, B{};

	cin >> A.Start._1 >> A.Start._2 >> A.End._1 >> A.End._2;
	cin >> B.Start._1 >> B.Start._2 >> B.End._1 >> B.End._2;

	cout << CheckVectorIntersect(A, B);

	return 0;
}


