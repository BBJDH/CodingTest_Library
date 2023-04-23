/*
 *======================================================================
 *연습문제 - 하우징 시스템
 *
 * 각 칸의 접근비용 => 칸부터 시설까지 거리 * 중요도
 *
 * 칸이 여러개인 경우 시설 접근비용은 각 칸 기중 최대비용으로 산출
 *
 * 요구사항대로 구현 및 브루트포스로 풀이한다.
 *
 */


 #include <iostream>
 #include <vector>
 
 using namespace std;
 
 int Solution(int N, vector<vector<int>> facility)
 {
 	int answer = 100000000;
 
 
 
 	for(int y=1; y<=N; y++)
 	{
 		for(int x=1; x<=N; x++)
 		{
 			int MaxCost = 0;
 			for(vector<int> const & elem : facility)
 			{
 				int Distance = abs(x - elem[1]) + abs(y - elem[0]);
 				MaxCost = max(MaxCost, Distance * elem[2]);
 			}
 			answer = min(answer, MaxCost);
 		}
 	}
 
 	return answer;	
 }
 
 int main()
 {
 	cin.tie(nullptr);
 	ios_base::sync_with_stdio(false);
 	vector<vector<int>> Input = { {1,3,1}, {3,1,1}};
 	vector<vector<int>> Input = { {1,3,2}, {3,1,1}};
 	vector<vector<int>> Input = { {1, 1, 1}};
 	cout<<Solution(3, Input);
 
 	return 0;
 }
 
