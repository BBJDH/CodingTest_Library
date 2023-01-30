/*
 * 코딩테스트 연습 > 해시 > 위장
 *
 *
 *문제를 간소화시켜보면,
 *
 *결국 각 카테고리당 들어있는 옷의 수가 3 2 3 이라고 할때
 *
 *3가지의 옷에 착용하지 않는경우 +1을 하여
 *4*3*4 의 경우의 수가 나온다.
 *하지만 문제에서 발가벗은경우는 존재하지 않으므로
 *위의 식에서 -1을 해준다(발가벗은경우 하나만 차감)
 *즉 정리하면
 *
 *들어온 카테고리의 옷가지수+1의 곱을 구한다음
 *-1을 해주면 그것이 해가 된다. 4*3*4-1
 *
 */

#include <string>
#include <vector>
#include<iostream>
#include<map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    map<string, int>Combinations{};
    for (vector<string> const& elem : clothes)
        Combinations[elem[1]]++;
    answer = 1;
    for (pair<string, int> const& elem : Combinations)
        answer *= (elem.second + 1);
    return answer - 1;
}