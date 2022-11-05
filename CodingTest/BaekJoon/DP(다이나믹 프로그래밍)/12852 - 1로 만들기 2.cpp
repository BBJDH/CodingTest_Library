/*
12852 - 1�� ����� 2

1���� 10^6���� n��ŭ �����Ͽ� +1 *2 *3 �غ��� ���ŵǴ� �ּҺ���� ������Ʈ�� ���
���� �Ųٷ� ����� ���� �ּҺ�� ������Ʈ �� �ҽ��ѹ��� ���� ����Ѵ�.

�Է¹��� ��ȣ�� �ε������Ͽ� Count�� ����ϰ� Src�� �������Ͽ� ���

 */


#include <iostream>
#include <algorithm>

using namespace std;

struct _int2
{
	int Count;
	int Src;
};

_int2 Nums[1000001]{};

_int2 MIN(_int2 const& NewVal, _int2 const& Dest)
{
	_int2 Result{};

	if (NewVal.Count < Dest.Count or Dest.Count == 0)
		return NewVal;
	else
		return Dest;
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 1; i < 1000000; i++)
	{
		_int2 const NewVal = { Nums[i].Count + 1,i };
		Nums[i + 1] = MIN(NewVal, Nums[i + 1]);
		if (i * 2 <= 1000000)
			Nums[i * 2] = MIN(NewVal, Nums[i * 2]);
		if (i * 3 <= 1000000)
			Nums[i * 3] = MIN(NewVal, Nums[i * 3]);
	}


	int TargetNum = 0;
	cin >> TargetNum;
	cout << Nums[TargetNum].Count << "\n";


	int Num = TargetNum;
	while (true)
	{
		cout << TargetNum << " ";

		if (TargetNum == 1)
			return 0;

		TargetNum = Nums[TargetNum].Src;

	}

	return 0;
}