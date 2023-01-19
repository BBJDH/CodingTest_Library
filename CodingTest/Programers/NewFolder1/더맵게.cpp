#include"stdafx.h"
using namespace std;


int solution(vector<int> scoville, int K) {
	int answer = 0;
	//맨앞의 원소가 K를 넘으면 탈출
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
	//다돌았는데 탈출 못했으면 -1

	return -1;
}

int main()
{
	vector<int> scoville = { 1,2,3,9,10,12 };

	cout<<solution(scoville, 7);

	return 0;
}

/*
* 
* 우선순위 큐를 활용
#include <string>
#include <vector>
#include <queue>
#include<iostream>
using namespace std;

int solution(vector<int> scoville, int K) {

    priority_queue<long long,vector<long long>,greater<>> Shake{};
    int answer = 0;

    for(auto const & elem : scoville)
        Shake.push(elem);

    while(!Shake.empty())
    {
        if(Shake.top()>=K)
        {
            return answer;
        }
        long long num1 = Shake.top();
        Shake.pop();
        if(Shake.empty())
            break;
        long long num2 = Shake.top();
        Shake.pop();
        Shake.push(num1+num2*2);
        answer++;

        //cout<<num;
    }

    return -1;
}

*/