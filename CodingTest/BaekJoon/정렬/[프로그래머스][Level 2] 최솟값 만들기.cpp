/*
 *[프로그래머스][Level 2] 최솟값 만들기
 *
 *로직은 간단하게 오름차순, 내림차순으로 정렬한 배열을 서로 곱한 값을 출력하면 된다.
 *
 *두 수의 곱은 가장 큰수와 가장 작은 수의 곱으로 합해나가면 되기 때문
 *
 *
 */

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<>());

    for (int i = 0; i < A.size(); i++)
    {
        answer += A[i] * B[i];
    }

    return answer;
}