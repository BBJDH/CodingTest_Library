#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int Score[3]{};

	for (int i = 0; i < 3; i++)
		cin >> Score[i];

	int N = 0;
	int Max = 0;
	cin >> N;

	for(int i=0; i<N; i++)
	{
		int Sum = 0;
		for(int people=0; people <3; people++)
		{
			for(int skill =0; skill<3; skill++)
			{
				int count = 0;

				cin >> count;

				Sum += count * Score[skill];
			}
		}
		Max = max(Max, Sum);
	}
	cout << Max;

	return 0;
}