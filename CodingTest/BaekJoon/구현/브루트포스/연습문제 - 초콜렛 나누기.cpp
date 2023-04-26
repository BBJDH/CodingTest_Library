/*
 *======================================
 *
 *연습문제 - 초콜렛 나누기
 *
 * DDDW
 * DDWW
 * MMMM
 *
 * DDDW
 *
 * DDWW
 *
 * MMMM
 *
 *
 *
 * DD DW
 * DD WW
 *
 * MMMM
 *
 *
 * DDD W
 * DDW W
 *
 * MMMM
 *
 * 많은 조건 분기를 가지는 구현문제이다.
 *
 * 수평으로 나누고 수직으로 나누는경우(위에서 시작, 아래에서 시작)
 * 수평으로만 나누는경우
 *
 * 수직도 마찬가지로 왼쪽 오른쪽에서 수직으로 나누고 수평으로 나누는 경우, 수직으로만 나누는 경우
 *
 * 각각에 대하여 구역을 나누고, 이것의 비교함수 또한 순수 구현으로 구현한다.
 *
 */

 #include <iostream>
 #include <vector>
 #include <string>
 
 using namespace std;
 
 struct _int2
 {
 	int X;
 	int Y;
 };
 
 struct _int3
 {
 	int DarkCount;
 	int MilkCount;
 	int WhiteCount;
 };
 
 vector<string> Chocolate{};
 void CountingChocolet(_int2 const & Start, _int2 const& End, _int3 & Result)
 {
 	Result = {};
 	for(int y= Start.Y; y< End.Y; y++)
 	{
 		for(int x= Start.X; x< End.X; x++)
 		{
 			if(Chocolate[y][x] =='D')
 			{
 				Result.DarkCount++;
 				continue;
 			}
 			if (Chocolate[y][x] == 'M')
 			{
 				Result.MilkCount++;
 				continue;
 			}
 			if (Chocolate[y][x] == 'W')
 			{
 				Result.WhiteCount++;
 				continue;
 			}
 		}
 	}
 }
 
 bool IsSucceed(vector<_int3> const & DividedChocolet)
 {
 
 	//0번째 초콜릿 Dark가 가장 많은경우
 	if(DividedChocolet[0].DarkCount > DividedChocolet[1].DarkCount and DividedChocolet[0].DarkCount > DividedChocolet[2].DarkCount)
 	{
 		//1번째 Milk 초콜릿이 가장 많은 경우
 		if(DividedChocolet[1].MilkCount > DividedChocolet[0].MilkCount and DividedChocolet[1].MilkCount > DividedChocolet[2].MilkCount)
 		{
 			//White도 가장 많아야 함
 			if(DividedChocolet[2].WhiteCount > DividedChocolet[0].WhiteCount and DividedChocolet[2].WhiteCount > DividedChocolet[1].WhiteCount)
 			{
 				return true;
 			}
 		}
 		//2째 인경우
 		if (DividedChocolet[2].MilkCount > DividedChocolet[0].MilkCount and DividedChocolet[2].MilkCount > DividedChocolet[1].MilkCount)
 		{
 			//White도 가장 많아야 함
 			if (DividedChocolet[1].WhiteCount > DividedChocolet[0].WhiteCount and DividedChocolet[1].WhiteCount > DividedChocolet[2].WhiteCount)
 			{
 				return true;
 			}
 		}
 	}
 
 
 
 	//1번째 초콜릿 Dark가 가장 많은경우
 	if (DividedChocolet[1].DarkCount > DividedChocolet[2].DarkCount and DividedChocolet[1].DarkCount > DividedChocolet[0].DarkCount)
 	{
 		//0번째 Milk 초콜릿이 가장 많은 경우
 		if (DividedChocolet[0].MilkCount > DividedChocolet[1].MilkCount and DividedChocolet[0].MilkCount > DividedChocolet[2].MilkCount)
 		{
 			//White도 가장 많아야 함
 			if (DividedChocolet[2].WhiteCount > DividedChocolet[0].WhiteCount and DividedChocolet[2].WhiteCount > DividedChocolet[1].WhiteCount)
 			{
 				return true;
 			}
 		}
 		//2 인경우
 		if (DividedChocolet[2].MilkCount > DividedChocolet[0].MilkCount and DividedChocolet[2].MilkCount > DividedChocolet[1].MilkCount)
 		{
 			//White도 가장 많아야 함
 			if (DividedChocolet[0].WhiteCount > DividedChocolet[1].WhiteCount and DividedChocolet[0].WhiteCount > DividedChocolet[2].WhiteCount)
 			{
 				return true;
 			}
 		}
 	}
 
 
 	//2번째 초콜릿 Dark가 가장 많은경우
 	if (DividedChocolet[2].DarkCount > DividedChocolet[0].DarkCount and DividedChocolet[2].DarkCount > DividedChocolet[1].DarkCount)
 	{
 		//0번째 Milk 초콜릿이 가장 많은 경우
 		if (DividedChocolet[0].MilkCount > DividedChocolet[1].MilkCount and DividedChocolet[0].MilkCount > DividedChocolet[2].MilkCount)
 		{
 			//White도 가장 많아야 함
 			if (DividedChocolet[1].WhiteCount > DividedChocolet[0].WhiteCount and DividedChocolet[1].WhiteCount > DividedChocolet[2].WhiteCount)
 			{
 				return true;
 			}
 		}
 		//1 인경우
 		if (DividedChocolet[1].MilkCount > DividedChocolet[0].MilkCount and DividedChocolet[1].MilkCount > DividedChocolet[2].MilkCount)
 		{
 			//White도 가장 많아야 함
 			if (DividedChocolet[0].WhiteCount > DividedChocolet[1].WhiteCount and DividedChocolet[0].WhiteCount > DividedChocolet[2].WhiteCount)
 			{
 				return true;
 			}
 		}
 	}
 
 	return false;
 }
 
 int solution( vector<string> chocolate)
 {
 	int answer = 0;
 
 	Chocolate = chocolate;
 
 	vector<_int3> DividedChocolet{};
 	DividedChocolet.resize(3);
 
 	//수평부터
 	for(int y=0; y< chocolate.size(); y++)
 	{

        //수평으로만
        for (int secondy = y + 1; secondy < chocolate.size(); secondy++)
        {
            CountingChocolet({ 0,0 }, { static_cast<int>(chocolate[0].size()), y }, DividedChocolet[0]);
            CountingChocolet({ 0, y }, { static_cast<int>(chocolate[0].size()), secondy }, DividedChocolet[1]);
            CountingChocolet({ 0, secondy }, { static_cast<int>(chocolate[0].size()), static_cast<int>(chocolate.size()) }, DividedChocolet[2]);
            //판정
            if (IsSucceed(DividedChocolet) == true)
            {
                answer++;
            }
        }

 		//수평으로 위 아래로 잘라야 함
 		//위로 자른 경우
 		CountingChocolet({ 0,0 }, { static_cast<int>(chocolate[0].size()), y }, DividedChocolet[0]);
 		for (int x = 0; x < chocolate[0].size(); x++)
 		{
 
 			CountingChocolet({ 0, y }, { x, static_cast<int>(chocolate.size()) }, DividedChocolet[1]);
 			CountingChocolet({ x, y }, { static_cast<int>(chocolate[0].size()), static_cast<int>(chocolate.size()) }, DividedChocolet[2]);
 			if (IsSucceed(DividedChocolet) == true)
 			{
 				answer++;
 			}
 		}
 		//아래로 자른 경우
 		CountingChocolet({ 0,static_cast<int>(chocolate.size() - y) }, { static_cast<int>(chocolate[0].size()), static_cast<int>(chocolate.size()) }, DividedChocolet[0]);
 		for (int x = 0; x < chocolate[y].size(); x++)
 		{
 			CountingChocolet({ 0, 0 }, { x, static_cast<int>(chocolate.size() - y) }, DividedChocolet[1]);
 			CountingChocolet({ x, 0 }, { static_cast<int>(chocolate[0].size()), static_cast<int>(chocolate.size() - y) }, DividedChocolet[2]);
 			if (IsSucceed(DividedChocolet) == true)
 			{
 				answer++;
 			}
 		}
 
 
 
 
 
 	}
 	//수직부터
 
 	for (int x = 0; x < chocolate[0].size(); x++)
 	{

        //DD DMM MWWW, DD DMMM WWW, DD DMMMW WW 
        //DDD MM MWWW, DDD MMM WWW, DDD MMMW WW
        //DDDM MM WWW, DDDM MMW WW
        //수직으로만
        for (int secondx = x + 1; secondx < chocolate[0].size(); secondx++)
        {
            CountingChocolet({ 0,0 }, { x, static_cast<int>(chocolate.size()) }, DividedChocolet[0]);
            CountingChocolet({ x, 0 }, { secondx, static_cast<int>(chocolate.size()) }, DividedChocolet[1]);
            CountingChocolet({ secondx, 0 }, { static_cast<int>(chocolate[0].size()), static_cast<int>(chocolate.size()) }, DividedChocolet[2]);
            //판정
            if (IsSucceed(DividedChocolet) == true)
            {
                answer++;
            }
        }


 		//수직으로 왼쪽부터 자른경우,  오른쪽부터 자른경우 구분해야 함
 
 		//왼쪽으로 자른 경우
 		CountingChocolet({ 0,0 }, { x, static_cast<int>(chocolate.size()) }, DividedChocolet[0]);
 		for (int y = 0; y < chocolate.size(); y++)
 		{
 			CountingChocolet({ x, 0 }, { static_cast<int>(chocolate[0].size()),y }, DividedChocolet[1]);
 			CountingChocolet({ x, y }, { static_cast<int>(chocolate[0].size()), static_cast<int>(chocolate.size()) }, DividedChocolet[2]);
 			if (IsSucceed(DividedChocolet) == true)
 			{
 				answer++;
 			}
 		}
 		
 		//오른쪽부터 자른 경우
 		CountingChocolet({ static_cast<int>(chocolate[0].size() - x), 0 }, { static_cast<int>(chocolate[0].size()), static_cast<int>(chocolate.size()) }, DividedChocolet[0]);
 		for (int y = 0; y < chocolate.size(); y++)
 		{
 
 			CountingChocolet({ 0, 0 }, { static_cast<int>(chocolate[0].size() - x),  y }, DividedChocolet[1]);
 			CountingChocolet({ 0, y }, { static_cast<int>(chocolate[0].size() - x), static_cast<int>(chocolate.size()) }, DividedChocolet[2]);
 			if (IsSucceed(DividedChocolet) == true)
 			{
 				answer++;
 			}
 		}
 
 	}
 
 	return answer;
 }
 
 int main()
 {
 	cin.tie(nullptr);
 	ios_base::sync_with_stdio(false);
 
 	//cout << solution({ "DDMWWD","MDDMMW","WDDDDD", "MWDDWM", "WWWWDD", "WWWWWM"});
 	//cout << solution({ "DDMMWW"});
 	cout << solution({ "DDDW","DDWW","MMMM" });
 	//cout << solution({ "DDDMMMWWW" });
 
 	return 0;
 }