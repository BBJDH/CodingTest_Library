#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> Trees{};
int TreeCount = 0;
int LenthNeeds = 0;

long long CutTrees(long long CutHeight)
{
	long long Sum = 0;
	for (auto const& Elem : Trees)
	{
		long long SubTree = Elem - CutHeight;
		if (SubTree > 0)
			Sum += SubTree;
	}
	return Sum;
}

void Search()
{
	sort(Trees.begin(), Trees.end());

	long long Left = 0;
	long long Right = Trees[Trees.size() - 1] + 1;
	int Mid = 0;
	while (Left + 1 < Right)
	{
		long long Mid = (Right + Left) / 2;
		long long CuttedLength = CutTrees(Mid);
		if (LenthNeeds == CuttedLength)
		{
			cout << Mid;
			return;
		}
		else if (LenthNeeds < CuttedLength)
			Left = Mid;
		else
			Right = Mid;
	}
	cout << Left;
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	cin >> TreeCount >> LenthNeeds;
	while (TreeCount--)
	{
		int Treeheight = 0;
		cin >> Treeheight;
		Trees.push_back(Treeheight);
	}
	Search();
	return 0;
}
