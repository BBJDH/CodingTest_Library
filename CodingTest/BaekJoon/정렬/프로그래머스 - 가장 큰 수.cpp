/*
 *
 * ���α׷��ӽ� - ���� ū ��
 *
 * ������ ������ ��Ģ�� ã�� ������� ��������.
 *
 * ��Ģ�� ã�ƺ��ٸ�,
 *
 * 9�� ����
 * 999 [99] {9} 998 997 .... 990
 * 989 [98] 988 987 ... 980
 * 979 [97] 978 977 ... 970
 * ..
 * 909 [90] 908 907 ... 900
 *
 * 8�� ����
 * 899 [89] 898 897 ...
 * 889 888 [88] {8} 887 ...
 * 879 878 [87] 877 876 ...
 * ...
 * 809 808 [80] 807 806 ...
 *
 * 7�� ����
 * 799 798 [79] 797 796 795 ...
 * 789 788 [78] 787 786 785 ...
 * 779 778 777 [77] {7} 776 775 ...
 * 769 768 767 [76] 766 ...
 * 759 758 757 [75] 754 ...
 * ...
 *
 * 1�� ����
 * 199 ... 192 [19] 191 190
 * ...
 * 120 ... 122 [12] 121 120
 * 119 ... 112 111 [11] {1} 110
 * 109 ... 102 101 [10] 100
 *
 * �� ������ ����Ǿ�� �Ѵ�.
 *
 *
 *
 *
 * ���� ��� ������ �����Ϸ���,
 * ������ ���� ������ ���־�� �Ѵ�.
 *
 * 199(9) ... 192(1) [19](19) 191(1) 190(1)
 * ...
 * 120(1) ... 122(1) [12](12) 121(1) 120(1)
 * 119(1) ... 112(1) 111(1) [11](11) {1}(111) 110(1)
 * 109(1) ... 102(1) 101(1) [10](10) 100(1)
 *
 *��ȣ ���� ������ �����Ͽ� �߰��� �����̴�
 *
 *�� ������ �䱸���״�� 4������ �ݺ��Ǵ� ���� ������ְ� �̰��� ���ڿ��� ���Ѵٸ�,
 *���� ��� ������ �����Ѵ�.
 *
 *�� �����غ���,
 *
 *�Է� ���� ���ڸ����� �ִ� ���̸�ŭ �ݺ����� ���ڸ� �����Ѵ�.
 *
 *�̰͵��� �����Ͽ��� �� ���� ū ���� ������ ù��°������ �� ���� ū ���̴�.
 *
 *���� ���ĵ� ������ �ش� ���ڸ� ���ڿ��� ���� ����ϸ� �ȴ�.
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