#include<iostream>
#include <set>
#include <string>
using namespace std;

set<int> Student_Records;

void Push_Record(string const& Input_Nums)
{
	int Record = 0;

	for (int i = 0; i < Input_Nums.size(); i++)
	{
		Record |= (1 << Input_Nums[i]);
	}
	Student_Records.insert(Record);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int Students_Num = 0;
	while (cin >> Students_Num)
	{
		Student_Records.clear();
		while (Students_Num--)
		{
			string Input_Nums{};
			cin >> Input_Nums;
			Push_Record(Input_Nums);

		}
		cout << Student_Records.size() << "\n";
	}


	return 0;
}