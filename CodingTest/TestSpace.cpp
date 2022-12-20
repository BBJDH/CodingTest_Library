#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true)
	{
		int girlFriend = 0;
		int boyFriend = 0;

		cin >> girlFriend >> boyFriend;

		if (girlFriend == 0 and boyFriend == 0)
			break;

		cout << girlFriend + boyFriend << "\n";
	}
	

	return 0;
}