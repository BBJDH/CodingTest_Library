
/*
2992 - 크면서 작은 수


#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
	char input[7];
	scanf("%s",input);
	printf("%s\n",next_permutation(input,input+strlen(input))?input:"0");
}
next_permutation 통해서 간단하게 해결 가능하다

나는 조합을 위해 백트래킹을 사용했다
수를 방문하듯이 처리하며 모든 경우의 수를 작은수부터 기록하므로 자동 정렬된다
이것을 이분탐색으로 타겟넘버의 다음 수를 찾았다
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

