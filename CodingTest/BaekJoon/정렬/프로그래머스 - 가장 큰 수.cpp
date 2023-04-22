/*
 *
 * 프로그래머스 - 가장 큰 수
 *
 * 정렬은 쉽지만 규칙을 찾기 어려웠던 문제였다.
 *
 * 규칙을 찾아본다면,
 *
 * 9로 시작
 * 999 [99] {9} 998 997 .... 990
 * 989 [98] 988 987 ... 980
 * 979 [97] 978 977 ... 970
 * ..
 * 909 [90] 908 907 ... 900
 *
 * 8로 시작
 * 899 [89] 898 897 ...
 * 889 888 [88] {8} 887 ...
 * 879 878 [87] 877 876 ...
 * ...
 * 809 808 [80] 807 806 ...
 *
 * 7로 시작
 * 799 798 [79] 797 796 795 ...
 * 789 788 [78] 787 786 785 ...
 * 779 778 777 [77] {7} 776 775 ...
 * 769 768 767 [76] 766 ...
 * 759 758 757 [75] 754 ...
 * ...
 *
 * 1로 시작
 * 199 ... 192 [19] 191 190
 * ...
 * 120 ... 122 [12] 121 120
 * 119 ... 112 111 [11] {1} 110
 * 109 ... 102 101 [10] 100
 *
 * 의 순서로 진행되어야 한다.
 *
 *
 *
 *
 * 위의 모든 조건을 만족하려면,
 * 다음과 같은 조작을 해주어야 한다.
 *
 * 199(9) ... 192(1) [19](19) 191(1) 190(1)
 * ...
 * 120(1) ... 122(1) [12](12) 121(1) 120(1)
 * 119(1) ... 112(1) 111(1) [11](11) {1}(111) 110(1)
 * 109(1) ... 102(1) 101(1) [10](10) 100(1)
 *
 *괄호 안의 수들은 조작하여 추가한 수들이다
 *
 *즉 문제의 요구사항대로 4길이의 반복되는 수를 만들어주고 이것을 문자열로 비교한다면,
 *위의 모든 조건을 충족한다.
 *
 *즉 정리해보면,
 *
 *입력 받은 숫자만으로 최대 길이만큼 반복시켜 숫자를 구성한다.
 *
 *이것들을 정렬하였을 때 가장 큰 수가 문자의 첫번째에왔을 때 가장 큰 수이다.
 *
 *따라서 정렬된 순으로 해당 숫자를 문자열에 합쳐 출력하면 된다.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int Num;
    string StrNum;
};

bool operator>(Node const& Left, Node const& Right)
{
    return Left.StrNum > Right.StrNum;
}

bool operator<(Node const& Left, Node const& Right)
{
    return Left.StrNum < Right.StrNum;
}

vector<Node> NumsStr{};

string solution(vector<int> numbers) {

    string answer = "";
    int MaxLenth = 0;
    for (int const elem : numbers)
    {
        MaxLenth = max(MaxLenth, static_cast<int>(to_string(elem).size()));
    }
    for (int const elem : numbers)
    {
        string StrNum = to_string(elem);
        int Index = 0;
        while (StrNum.size() < 4)
        {
            StrNum += StrNum[Index];
            Index++;
        }
        NumsStr.push_back({ elem, StrNum });
    }

    sort(NumsStr.begin(), NumsStr.end(), greater<>());

    for (int i = 0; i < NumsStr.size(); i++)
    {
        answer += to_string(NumsStr[i].Num);
    }
    if (answer[0] == '0')
    {
        return "0";
    }

    return answer;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cout << solution({ 999, 98, 987, 99, 9 });

    return 0;
}