
/*
2992 - ũ�鼭 ���� ��


#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
	char input[7];
	scanf("%s",input);
	printf("%s\n",next_permutation(input,input+strlen(input))?input:"0");
}
next_permutation ���ؼ� �����ϰ� �ذ� �����ϴ�

���� ������ ���� ��Ʈ��ŷ�� ����ߴ�
���� �湮�ϵ��� ó���ϸ� ��� ����� ���� ���������� ����ϹǷ� �ڵ� ���ĵȴ�
�̰��� �̺�Ž������ Ÿ�ٳѹ��� ���� ���� ã�Ҵ�
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>


using namespace std;

vector<int> SingleNums{};
bitset<6> NumCheck{};
vector<int> MadeNumList{};

int TargetNum = 0;

void MakeNum(int const& PrevNum = 0, int Numsize = 0)
{
	for (int i = 0; i < SingleNums.size(); i++)
	{
		if (NumCheck[i] == false)
		{
			int Size = Numsize;
			int NextNum = PrevNum * 10 + SingleNums[i];
			Size++;
			if (Size == SingleNums.size())
			{
				MadeNumList.push_back(NextNum);
			}
			else
			{
				NumCheck[i] = true;
				MakeNum(NextNum, Size);
			}
			NumCheck[i] = false;
		}
	}

}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int InputNum = 0;

	cin >> InputNum;
	TargetNum = InputNum;
	while (InputNum)
	{
		SingleNums.push_back(InputNum % 10);
		InputNum /= 10;
	}
	sort(SingleNums.begin(), SingleNums.end());

	MakeNum();
	auto const Iter = upper_bound(MadeNumList.begin(), MadeNumList.end(), TargetNum);

	if (Iter == MadeNumList.end())
		cout << 0;
	else
		cout << *Iter;

	return 0;
}

