#include<cstdio>
#include<algorithm>
#pragma warning(disable:4996)



void BiSearch(int const search_num, int const*const target_arry, int const target_arry_size)
{
	bool is_searching = true;
	int left_index = 0;
	int right_index = target_arry_size-1;
	int target_arry_index = 0;

	while (right_index>= left_index)
	{
		target_arry_index = left_index + (right_index- left_index) / 2;


		if (search_num == target_arry[target_arry_index])
		{
			printf("1\n");
			return;
		}
		else if (search_num < target_arry[target_arry_index])
		{
			right_index = target_arry_index-1;
		}
		else
		{
			left_index = target_arry_index+1;
		}
	}
	printf("0\n");

	return ;

	
}


int main()
{
	int target_arry[100001]{};
	int target_num_size, search_num_size;
	scanf("%d", &target_num_size);
	for(int i =0; i< target_num_size; i++)
		scanf("%d", &target_arry[i]);
	
	std::sort(target_arry, target_arry+ target_num_size);


	scanf("%d", &search_num_size);
	for (int i = 0; i < search_num_size; i++)
	{
		int search_num = 0;
		scanf("%d", &search_num);
		BiSearch(search_num, target_arry, target_num_size);
	}



	return 0;
}