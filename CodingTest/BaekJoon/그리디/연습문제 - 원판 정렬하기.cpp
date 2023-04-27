/*
 *======================================
 *
 *연습문제 - 원판 정렬하기
 *
 *
 * n = 원의 개수
 * m = 각 원의 배열 크기
 *
 */


/*
 *
 * 그리디는 안된다...
 *
 * 각 원에서 최대 정렬 갯수가 같은 갯수가 여러개이면 다음에 넘겨줄 최적 배열을 알 수 없다...
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
////InnerCircle은 고정, 
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
//        //배열돌려보기 완료
//        if(CurrentSortedCount>= MaxSortedCount)
//        {
//            MaxSortedCount = CurrentSortedCount;
//            ResultOfMaxSorted = CurrentMadeCircle;
//        }
//    }
//
//
//    //종료
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
//    //가장 안쪽은 고정 두번째 동심원부터 시작
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
 * 정답 받아낸 것
 * 
 * 
 * 문제의 조건에 m^n은 10000을 넘지 않기 때문에 브루트포스가 가능하다.
 *
 * 그냥 브루트 포스로 모든 인덱스를 백트레킹하여 배열로 보낸후
 * 
 * 끝에서 정렬 갯수를 모두 카운팅하여 가장 큰것을 보존한다.
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
        //원 정렬 여부 스캔
        int AscendingCount = 0;
        for(int i=0; i< MaxCircleLength; i++)
        {
            //최대 깊이까지 확인
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
    //가장 안쪽은 고정
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
