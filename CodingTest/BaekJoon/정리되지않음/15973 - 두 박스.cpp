#include <iostream>
#include <algorithm>

using namespace std;

struct _float2
{
	int Min;
	int Max;
};
struct Box
{
	_float2 XAxis;
	_float2 YAxis;
};

/*
해당 사각형의 각 축에대한 최대값으로 사각형 끼리 축이 겹치는지 판정
축 판정 함수
{
	범위 사이에 걸러셔 축이 겹치는 경우 2반환
	점이 걸리는 경우  1반환
	아무것도 안걸리면 0
}

*/
void Swap(_float2& A, _float2& B)
{
	_float2 Temp{};
	Temp = A;
	A = B;
	B = Temp;
}

int CollisionAxis(_float2& MinAxis, _float2& MaxAxis)
{
	//먼저 두 축중에 대해 정렬
	if (MinAxis.Min > MaxAxis.Min)
		Swap(MinAxis, MaxAxis);
	//왼쪽 축의 Max가 오른쪽 축의 Min보다 크다면 축 충돌 2반환
	//축 중돌 중에서 왼쪽 Max와 오른쪽 Min이 완전히 일치한다면 축이 점에서 겹친다는 의미의 1을 반환
	//왼쪽 축의 Max가 오른쪽 축의 Min보다 작다면 축은 충돌 되지 않았으므로 0반환

	if (MinAxis.Max == MaxAxis.Min)
		return 1;
	else if (MinAxis.Max > MaxAxis.Min)
		return 2;
	else
		return 0;

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	Box Boxes[2]{};

	for (int i = 0; i < 2; i++)
	{
		cin >> Boxes[i].XAxis.Min >> Boxes[i].YAxis.Min >> Boxes[i].XAxis.Max >> Boxes[i].YAxis.Max;
	}
	int const XCollisionResult = CollisionAxis(Boxes[0].XAxis, Boxes[1].XAxis);
	int const YCollisionResult = CollisionAxis(Boxes[0].YAxis, Boxes[1].YAxis);

	if (XCollisionResult == 0 or YCollisionResult == 0)
		cout << "NULL";
	else if (XCollisionResult == 2 and YCollisionResult == 2)
		cout << "FACE";
	else if (XCollisionResult == 1 and YCollisionResult == 1)
		cout << "POINT";
	else
		cout << "LINE";

	return 0;
}