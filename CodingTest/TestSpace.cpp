#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> Nums{};

void Solution()
{
	sort(Nums.begin(), Nums.end());

	int StartNum = Nums[0];
	int EndNum = Nums[Nums.size()-1];

	for(int i=StartNum; i<=EndNum; i++)
	{
		
	}

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;

	cin >> N;

	for(int i=0; i<N; i++)
	{
		int inputNum = 0;
		cin >> inputNum;

		Nums.push_back(inputNum);
	}

	
	
	
	return 0;
}