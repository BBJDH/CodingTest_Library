/*
 *[���α׷��ӽ�][Level 2] �ּڰ� �����
 *
 *������ �����ϰ� ��������, ������������ ������ �迭�� ���� ���� ���� ����ϸ� �ȴ�.
 *
 *�� ���� ���� ���� ū���� ���� ���� ���� ������ ���س����� �Ǳ� ����
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