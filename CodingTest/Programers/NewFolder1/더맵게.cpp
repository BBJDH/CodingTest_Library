#include"stdafx.h"
using namespace std;


int solution(vector<int> scoville, int K) {
	int answer = 0;
	//�Ǿ��� ���Ұ� K�� ������ Ż��
	while (scoville.size() != 1)
	{
		sort(scoville.begin(), scoville.end());
		if (scoville.at(0) >= K)
			return answer;
		answer++;

		int first = scoville.at(0);
		int second = scoville.at(1);
		scoville.erase(scoville.begin());
		scoville.erase(scoville.begin());

		scoville.push_back(first + second * 2);
	}
	//�ٵ��Ҵµ� Ż�� �������� -1

	return -1;
}

int main()
{
	vector<int> scoville = { 1,2,3,9,10,12 };

	cout<<solution(scoville, 7);

	return 0;
}