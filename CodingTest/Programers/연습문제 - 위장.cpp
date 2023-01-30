/*
 * �ڵ��׽�Ʈ ���� > �ؽ� > ����
 *
 *
 *������ ����ȭ���Ѻ���,
 *
 *�ᱹ �� ī�װ��� ����ִ� ���� ���� 3 2 3 �̶�� �Ҷ�
 *
 *3������ �ʿ� �������� �ʴ°�� +1�� �Ͽ�
 *4*3*4 �� ����� ���� ���´�.
 *������ �������� �߰��������� �������� �����Ƿ�
 *���� �Ŀ��� -1�� ���ش�(�߰�������� �ϳ��� ����)
 *�� �����ϸ�
 *
 *���� ī�װ��� �ʰ�����+1�� ���� ���Ѵ���
 *-1�� ���ָ� �װ��� �ذ� �ȴ�. 4*3*4-1
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