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
�ش� �簢���� �� �࿡���� �ִ밪���� �簢�� ���� ���� ��ġ���� ����
�� ���� �Լ�
{
	���� ���̿� �ɷ��� ���� ��ġ�� ��� 2��ȯ
	���� �ɸ��� ���  1��ȯ
	�ƹ��͵� �Ȱɸ��� 0
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
	//���� �� ���߿� ���� ����
	if (MinAxis.Min > MaxAxis.Min)
		Swap(MinAxis, MaxAxis);
	//���� ���� Max�� ������ ���� Min���� ũ�ٸ� �� �浹 2��ȯ
	//�� �ߵ� �߿��� ���� Max�� ������ Min�� ������ ��ġ�Ѵٸ� ���� ������ ��ģ�ٴ� �ǹ��� 1�� ��ȯ
	//���� ���� Max�� ������ ���� Min���� �۴ٸ� ���� �浹 ���� �ʾ����Ƿ� 0��ȯ

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