/*
9252 LCS 2

문자열 크기에 대해서 2차원 배열을 생성
각 문자열에 대한 2차원 배열을 구성

  A C A Y K P
C 0 1 1 1 1 1
A 1 2 2 2 2 2 
P 1 2 2 2 2 3
C 1 3 3 3 3 3
A 2 3 3 3 3 3
K 2 3 3 3 4 4

정리하면

문자 하나기준 하나라도 일치하는 문자가 나오면 그 인덱스 부터 해당행에 +1을 기록
항시 이전 행의 DP값을 누적
해당 행에 같은 문자가 여러번 떠도 오직 +1만 누적
*/


#pragma region 골드
/*

N과M 3

모든 수의 합의 평균이 n-1경우 부터 하나씩 아래로 내려가면서 탐색
평균 n-1은 N개의 수 모두 n-1경우 밖에 없음
n-2는 마찬가지로 모두 n-2이거나 n-2보다 큰 수와 n-2보다 작은 수와의 조합으로 평균 n-2가 가능
모든 입력받은 수의 합/N 부터 접근 이이상은 나올수 없는 평균

*/

#pragma region 0 만들기
//
//void Solution(int const current_num, int const max_num,int prev_calc_num, int result, string str)
//{
//	if (current_num == max_num)
//	{
//		result += prev_calc_num;
//		if(result==0)
//			cout << str <<"\n";
//		return;
//	}
//	//1+2 3 4
//	int new_calc_num = 0;
//	if (prev_calc_num > 0)
//		new_calc_num = prev_calc_num * 10 + current_num + 1;
//	else
//		new_calc_num = prev_calc_num * 10 - (current_num + 1);
//
//	//n+1번째 계산해야할 변수는 prev_calc_num 이고 함수에 result에 계산해서 넣어
//	//n+1번째, 종단점, 바뀌는 계산값, 다음지점 누적 계산값, 다음지점 누적 문자열
//
//	Solution(current_num+1,max_num, new_calc_num, result , str+" "+std::to_string(current_num + 1) );
//	Solution(current_num+1,max_num, current_num + 1, result + prev_calc_num, str+"+"+std::to_string(current_num + 1) );
//	Solution(current_num+1,max_num, -(current_num + 1), result + prev_calc_num, str+"-"+std::to_string(current_num + 1) );
//}
//
//
//int main()
//{
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
//
//
//
//	int test_case = 0;
//	cin >> test_case;
//
//	while (test_case--)
//	{
//		int num = 0;
//		cin >> num;
//		//내가 n번째 수 기준 계산값을 계산했어 계산해줘
//		//n번째, 종단점, 바뀌는 계산값, 현재 까지 누적 계산값, 누적된 문자열
//		Solution(1, num, 1,0, "1");
//		cout << "\n";
//
//	}
//
//	return 0;
//}  
#pragma endregion


#pragma endregion

#pragma region  한수

//bool sequence_check(int num)
//{
//	if (num < 100)
//		return true;
//
//	vector<int> arr{};
//	while (num)
//	{
//		arr.push_back(num%10);
//		num /= 10;
//	}
//	vector<int> sequence{};
//	for (int i = 0; i < arr.size() - 1; i++)
//	{
//		sequence.push_back(arr[i]- arr[i+1]);
//	}
//	for (int i = 0; i < sequence.size()-1; i++)
//	{
//		if (sequence[i] != sequence[i + 1])
//			return false;
//	}
//	return true;
//}
//
//int main()
//{
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
//	
//	int num = 0;
//	cin >> num;
//	int count = 0;
//	for (int i = 1; i <= num; i++)
//	{
//		if (sequence_check(i))
//			count++;
//	}
//	cout << count;
//
//	return 0;
//}
//

#pragma endregion

#pragma region 셀프넘버

//int Make_SelfNum(int num)
//{
//	int sum = num;
//	while (num)
//	{
//		sum += num % 10;
//		num /= 10;
//	}
//	return sum;
//}
//
//int main()
//{
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
//
//	std::set<int> nums;
//
//	for (int i = 1; i <= 10000; i++)
//		nums.insert(i);
//
//	for (int i = 1; i < 10000; i++)
//	{
//		nums.erase(Make_SelfNum(i));
//	}
//	for (set<int>::iterator iter = nums.begin(); iter!= nums.end(); iter++)
//		cout << *iter << "\n";
//
//	return 0;
//}  
#pragma endregion

#pragma region 함수 단계 브론즈
//int main()
//{

#pragma region 윤년
	////%4 =0 이면 윤년 판독 시작
	////400의 배수이면 윤년
	////%100 =0 이면 평년 
	////

	//int year = 0;

	//scanf("%d", &year);

	//if (year % 4 == 0)
	//{
	//	if(year%400==0)
	//		printf("1");
	//	else if (year % 100==0)
	//		printf("0");
	//	else
	//		printf("1");
	//}
	//else
	//{
	//	printf("0");

	//}  
#pragma endregion

#pragma region 사분면
					//int x, y = 0;

	//scanf("%d %d", &x, &y);

	//if (x * y > 0) //둘다 양 혹은 음수
	//{
	//	if (x > 0)
	//		printf("1");
	//	else
	//		printf("3");
	//}
	//else //둘중 하나가 음수
	//{
	//	if (x > 0)
	//		printf("4");
	//	else
	//	{
	//		printf("2");
	//	}
	//}

#pragma endregion

#pragma region 알람 시계
					//int hour, min = 0;
	//scanf("%d %d", &hour, &min);
	//

	////해당 분 수가 45보다 작다면 시간 -1
	//if (min < 45)
	//{
	//	if(hour==0)
	//		printf("%d %d",23, min + 15);
	//	else
	//		printf("%d %d", hour-1, min + 15);
	//}
	//else
	//{
	//	if (hour == 23)
	//		printf("%d %d", hour, min-45);
	//	else
	//		printf("%d %d", hour, min - 45);
	//}  
#pragma endregion

#pragma region 오븐시계
					//int start_hour, start_min, set_min = 0;
	//int alam_hour, alam_min=0;
	//scanf("%d %d %d", &start_hour, &start_min, &set_min);

	//{
	//	if (start_min + set_min >= 60)
	//	{
	//		alam_hour = start_hour + ((start_min + set_min) / 60);
	//	}
	//	else
	//		alam_hour = start_hour;
	//	alam_min = (start_min + set_min) % 60;
	//	alam_hour = alam_hour % 24;
	//}
	//printf("%d %d", alam_hour, alam_min);  
#pragma endregion

#pragma region 주사위 세개
					//int rand_dice[3]{};
	//int overlap_count = 1;
	//int same_num = 0;
	//scanf("%d %d %d", &rand_dice[0], &rand_dice[1], &rand_dice[2]);
	//std::sort(rand_dice, rand_dice+3);
	//for (int i = 0; i < 2; i++)
	//{
	//	if (rand_dice[i] == rand_dice[i + 1])
	//	{
	//		overlap_count++;
	//		same_num = rand_dice[i];
	//	}
	//}
	//if(overlap_count==3)
	//	printf("%d", 10000 + (same_num * 1000));
	//else if (overlap_count == 2)
	//{
	//	printf("%d", 1000+ (same_num * 100));
	//}
	//else
	//	printf("%d",(rand_dice[2] * 100));

	//

#pragma endregion

#pragma region 합
					//int num = 0;
	//scanf("%d", &num);
	//printf("%d", num* (num + 1) / 2);  
#pragma endregion

#pragma region 빠른 입출력
				///*
//	C++을 사용하고 있고 cin/cout을 사용하고자 한다면, cin.tie(NULL)과 sync_with_stdio(false)를 둘 다 적용해 주고, endl 대신 개행문자(\n)를 쓰자. 
//	단, 이렇게 하면 더 이상 scanf/printf/puts/getchar/putchar 등 C의 입출력 방식을 사용하면 안 된다.
//
//*/
//	int size = 0;
//
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
//
//		cin >> size;
//	for (size_t i = 0; i < size; i++)
//	{
//		int a = 0, b = 0;
//		cin >> a >> b;
//
//		cout << a + b<<"\n";
//	}

#pragma endregion

#pragma region OX퀴즈
					//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);


	//int size = 0;
	//cin >> size;
	//for (int i = 0; i < size; i++)
	//{
	//	std::string OX{};
	//	cin >> OX;
	//	int count = 0;
	//	int sum = 0;
	//	for (int j = 0; j < OX.size(); j++)
	//	{
	//		if (OX[j] == 'O')
	//		{
	//			count++;
	//		}
	//		else
	//		{
	//			sum += count * (count + 1) / 2;
	//			count = 0;
	//		}
	//	}
	//	sum += count * (count + 1) / 2;

	//	cout << sum<<"\n";
	//}  
#pragma endregion

#pragma region 평균은 넘겠지
					//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);

	//int class_size = 0;
	//cin >> class_size;

	//for (int i = 0; i < class_size; i++)
	//{
	//	std::vector<int> students;
	//	int student_size = 0;
	//	cin >> student_size;
	//	students.resize(student_size);
	//	int sum = 0;

	//	for (int i = 0; i < students.size(); i++)
	//	{
	//		cin >> students[i];
	//		sum += students[i];
	//	}
	//	int avg = sum / students.size();

	//	std::sort(students.begin(), students.begin() + students.size());
	//	int count = 0;
	//	for (int i = students.size()-1; i >= 0; i--)
	//	{
	//		if (students[i] > avg)
	//			count++;
	//		else
	//		{
	//			cout<<fixed;
	//			cout.precision(3);
	//			cout << static_cast<double>(count) / static_cast<double>(students.size())*100.00f<<"%\n";
	//			break;
	//		}
	//	}

	//}  
#pragma endregion

//}  
#pragma endregion

