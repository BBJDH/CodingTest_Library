#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Sequence{};
vector<int> MaxSize{};


//배열 원소 i에 대해서 i 까지의 최고 긴 수열을 기록

void CheckMaxSize()
{
	//인덱스 순으로 하나씩 증가하며  인덱스 보다 작은 배열로 접근하여 최대 크기의 수열 갯수를 확인
	//인덱스별 수행사항
	//자신의 인덱스보다 작은 인덱스로 접근, 해당 인덱스의 데이터가 자신보다 작다면 수열크기를 받아옴
	//또한 수열크기가 더 큰 인덱스가 있다면 수열 크기를 업데이트
	//반복문을 빠져나오며 자신의 인덱스에대한 수열 크기를 받은 수열 크기의 +1 로 대입
	//마지막 인덱스까지 시행, 정렬, 최고 큰 수를 출력

	MaxSize.push_back(1);
	for (int i = 1; i < Sequence.size(); i++)
	{
		int SequenceSize = 0;
		for (int j = 0; j < i; j++)
		{
			//i번째 수가 J번째 수보다 크면서 j번째에서의 최대 수열이 현재 업데이트한 수열크기보다 크다면
			//이어나간다
			if (Sequence[i] > Sequence[j] and SequenceSize < MaxSize[j])
				SequenceSize = MaxSize[j];
		}
		MaxSize.push_back(SequenceSize + 1);
	}
	sort(MaxSize.begin(), MaxSize.end());
	cout << *(MaxSize.end() - 1);

}


int main()
{
	int Size = 0;

	cin >> Size;

	for (int i = 0; i < Size; i++)
	{
		int Input_Num = 0;
		cin >> Input_Num;
		Sequence.push_back(Input_Num);
	}
	CheckMaxSize();
	return 0;
}