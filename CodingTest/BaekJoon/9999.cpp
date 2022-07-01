* /
int main()
{
	int TestCase = 0, HubNum = 0;

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> location{};


	cin >> TestCase >> HubNum;
	while (TestCase--)
	{
		int input_location = 0;
		cin >> input_location;
		location.push_back(input_location);
	}
	sort(location.begin(), location.begin() + location.size());

	vector<int> distance{};
	for (size_t i = 0; i < location.size() - 1; i++)
	{
		int calc_distance = location[i + 1] - location[i];
		distance.push_back(calc_distance);
	}
	sort(distance.begin(), distance.begin() + distance.size());



	//print
	for (size_t i = 0; i < location.size(); i++)
	{
		cout << location[i];
	}
	cout << "\n";
	for (size_t i = 0; i < distance.size(); i++)
	{
		cout << distance[i];
	}



	return 0;
}
