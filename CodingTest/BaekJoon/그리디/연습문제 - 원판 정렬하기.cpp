/*
 *======================================
 *
 *�������� - ���� �����ϱ�
 *
 *
 * n = ���� ����
 * m = �� ���� �迭 ũ��
 *
 */


/*
 *
 * �׸���� �ȵȴ�...
 *
 * �� ������ �ִ� ���� ������ ���� ������ �������̸� ������ �Ѱ��� ���� �迭�� �� �� ����...
 *
 *
 */

//#include <cassert>
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
// struct Data
// {
//     int Num;
//     bool IsAscending;
// };
//
////InnerCircle�� ����, 
// int MakeBestResult(vector<int> const & OutterCircle, vector<Data> & InnerCircle)
// {
// 	int MaxSortedCount = 0;
//    vector<Data> ResultOfMaxSorted{};
//
//    for(int OutterStart =0; OutterStart < InnerCircle.size(); OutterStart++)
//    {
//        int CurrentSortedCount = 0;
//        vector<Data> CurrentMadeCircle{};
//        for(int InnerIndex =0, OutterIndex = OutterStart; InnerIndex< InnerCircle.size(); InnerIndex++, OutterIndex++)
//        {
//            OutterIndex = OutterIndex % InnerCircle.size();
//            CurrentMadeCircle.push_back({ OutterCircle[OutterIndex], false});
//            if(InnerCircle[InnerIndex].IsAscending == false)
//            {
//	            continue;
//            }
//            if (InnerCircle[InnerIndex].Num >= OutterCircle[OutterIndex])
//            {
//	            continue;
//            }
//
//            CurrentMadeCircle[InnerIndex].IsAscending = true;
//            CurrentSortedCount++;
//
//        }
//
//
//        //�迭�������� �Ϸ�
//        if(CurrentSortedCount>= MaxSortedCount)
//        {
//            MaxSortedCount = CurrentSortedCount;
//            ResultOfMaxSorted = CurrentMadeCircle;
//        }
//    }
//
//
//    //����
//
//    InnerCircle = ResultOfMaxSorted;
//    return MaxSortedCount;
// }
//
//
//
// int solution(int n, int m, vector<vector<int>> circles)
//{
//    int answer = 0;
//    vector<Data> InnerCircle{};
//
//    for(int const elem : circles[0])
//    {
//        Data InitResult{};
//        InnerCircle.push_back({ elem, true });
//    }
//
//    //���� ������ ���� �ι�° ���ɿ����� ����
//    for(int i=1; i< n; i++)
//    {
//        answer = MakeBestResult(circles[i], InnerCircle);
//    }
//
//
//    return answer;
// }


/*
 *
 *============================================================================
 *
 * ���� �޾Ƴ� ��
 * 
 * 
 * ������ ���ǿ� m^n�� 10000�� ���� �ʱ� ������ ���Ʈ������ �����ϴ�.
 *
 * �׳� ���Ʈ ������ ��� �ε����� ��Ʈ��ŷ�Ͽ� �迭�� ������
 * 
 * ������ ���� ������ ��� ī�����Ͽ� ���� ū���� �����Ѵ�.
 * 
 * 
 * 
 */

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

void BackTracking(vector<vector<int>>const & circles, vector<int> & IndexList,
    int const CurrentDepth, int const StartIndex, int const MaxCountOfCircle, 
    int const MaxCircleLength, int & MaxResult )
{
	if(CurrentDepth== MaxCountOfCircle)
	{
        //�� ���� ���� ��ĵ
        int AscendingCount = 0;
        for(int i=0; i< MaxCircleLength; i++)
        {
            //�ִ� ���̱��� Ȯ��
            bool IsAscending = true;
	        for(int Depth=1; Depth< MaxCountOfCircle; Depth++)
	        {
                int InnderIndex = (IndexList[Depth - 1] + i) % MaxCircleLength;
                int OutterIndex = (IndexList[Depth] + i) % MaxCircleLength;
                if(circles[Depth - 1][InnderIndex]>= circles[Depth][OutterIndex])
                {
                    IsAscending = false;
                    break;
                }
	        }
            if(IsAscending == true)
            {
                AscendingCount++;
            }
        }
        MaxResult = max(MaxResult, AscendingCount);
        return;
	}
    for(int i=0; i< MaxCircleLength; i++)
    {
        IndexList.push_back(i + 1);
        BackTracking(circles, IndexList, CurrentDepth+1, StartIndex, MaxCountOfCircle, MaxCircleLength, MaxResult);
        IndexList.pop_back();
    }
}


int solution(int n, int m, vector<vector<int>> circles)
{
    int answer = -1;

    vector<int>StartIndex{};
    StartIndex.push_back(0);
    //���� ������ ����
    BackTracking(circles, StartIndex,0,0,n,m, answer);

    return answer;
}

 int main()
 {
 	cin.tie(nullptr);
 	ios_base::sync_with_stdio(false);
 
 	//vector<vector<int>> Input = {{1,6,11,16,21,26},{2,5,8,11,14,17},{3,10,17,24,31,38}};
 	//cout << solution(3,6, Input);
 	//vector<vector<int>> Input = {{1,2,3,4},{2,1,3,4}};
 	//cout << solution(2,4, Input);

    vector<vector<int>> Input = { {999,1000}, {3,4}, {5, 6}, {7,8}, {10,100}, {11,12}, {13,14},{15,16},{17,18},{19,20} };
    cout << solution(10,2, Input);
 	return 0;
 }
