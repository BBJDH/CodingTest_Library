#include"stdafx.h"


using namespace std;


vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	vector<vector<int>> answer;
	
	for (int answer_row = 0; answer_row < arr1.size(); answer_row++)//행시작
	{
		answer.push_back({});
		for (int answer_col = 0; answer_col < arr2[0].size(); answer_col++)//열시작
		{
			int sum = 0;
			for (int elem =0; elem< arr1[0].size(); elem++)
			{
				sum += arr2[elem][answer_col] * arr1[answer_row][elem];
			}
			answer[answer_row].push_back(sum);
		}
	}
	return answer;
}

int main()
{
	vector<vector<int>> result;
	vector<vector<int>> arr1 = {
		{2,3,2},
		{4,2,4},
		{3,1,4}
	};
	vector<vector<int>> arr2 = {
		{5,4,3},
		{2,4,1},
		{3,1,1}
	};
	result = solution(arr1,arr2);

	int i = 0;

	return 0;
}