#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> InputNums{};

/*
받은 수를 정렬
각 수별로 다시 배열로 저장,

첫수부터 시작
현재수와 다음수가 같다면
{
	갯수를 카운트, 다음 인덱스로 넘어감
}
같지 않은 경우
{
	다음수가 +1이라면
	{
		+2 이상이 있는지 검사
		{
			존재한다면 다음수와 +2 수를 스왑
			다음인덱스로 넘어감
		}
		+2 이상이 존재하지 않는다면(+1수만 남았으므로 이 수들이 중복수들인지만 확인해주면 된다)
		{
			현재수 무리와 다음수 무리를 스왑
			작은수 이터레이터 =  lower_bound(인덱스-카운트, 끝까지, 인덱스 벨류)
			큰수 이터레이터 = upper_bound(인덱스+1, 끝까지, 인덱스 벨류) 찾아두고
			반복문(큰수 이터레이터가 초과하기 전까지) 스왑(작은수, 큰수)
			이터레이터들 플러스,
			완료시 break
		}
	}
	다음수가 +1가 아니라면
	{
		그냥 출력, 인덱스 증가
	}
	카운트 초기화
}

*/
void Sort()
{
	int Index = 0;
	int Count = 0;
	while (Index < InputNums.size() - 1)
	{
		if (InputNums[Index] == InputNums[Index + 1])
		{
			Count++;
			Index++;
		}
		else
		{
			if (InputNums[Index + 1] == InputNums[Index] + 1)
			{
				auto Iter_PlusTwoValue = upper_bound(InputNums.begin() + Index, InputNums.end(), InputNums[Index + 1]);
				if (Iter_PlusTwoValue != InputNums.end())
				{
					swap(InputNums[Index + 1], *Iter_PlusTwoValue);
					Index++;
				}
				else
				{
					auto Iter_Smaller = lower_bound(InputNums.begin() + Index - Count, InputNums.end(), InputNums[Index]);
					auto Iter_Bigger = upper_bound(InputNums.begin() + Index + 1, InputNums.end(), InputNums[Index]);
					while (Iter_Bigger != InputNums.end())
					{
						swap(*Iter_Smaller, *Iter_Bigger);
						Iter_Smaller++;
						Iter_Bigger++;
					}
					break;
				}
			}
			else
			{
				Index++;
			}
			Count = 0;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int InputCount = 0;

	cin >> InputCount;


	while (InputCount--)
	{
		int Input = 0;
		cin >> Input;
		InputNums.push_back(Input);
	}
	sort(InputNums.begin(), InputNums.end());
	Sort();
	for (int const& elem : InputNums)
		cout << elem << " ";
	return 0;
}
