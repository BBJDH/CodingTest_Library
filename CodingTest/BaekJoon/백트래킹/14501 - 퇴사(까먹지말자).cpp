/*
 * 14501 - 퇴사
 *
 *N이 15 이하 이므로 브루트 포스로 풀이 가능하다.
 *
 *백트래킹으로 모든 경우의 수를 탐색하도록 한다.
 *
 *방문 처리될 Visit을 N이 1~ 15 이므로 16의 크기로 설정
 *회사에 머무르는 날 N을 전역으로 두어
 *Visit 방문 처리시 N도 초과하는지 같이 검사한다.
 *
 *백트래킹시 각 경우의 수에 해당하는 값을 전달해 주어야 하므로
 *레퍼런스를 사용하지않고 전달한다. (값 생성)
 *또한 for문을 통해 조합을 탐색하므로 이전에 탐색한 경우는 필요치 않다.
 *
 *따라서 재귀 호출 시 내가 현재 방문한 다음 장소부터 탐색을 시행한다.
 *(꼭 기억하자!)
 *
 */

#include <iostream>
#include <vector>

using namespace std;

struct _int2
{
	int Time;
	int Pay;
};

bool Visit[16]{};
vector<_int2> Schedule{};
int MaxPay = 0;
int N = 0;


int Push(int Day, _int2 const& NextOrder)
{

	for (int i = Day; i < Day + NextOrder.Time; i++)
	{
		if (Visit[i] == true or i > N)
			return 0;
	}

	for (int i = Day; i < Day + NextOrder.Time; i++)
	{
		Visit[i] = true;
	}
	return NextOrder.Pay;
}
void Release(int Day, _int2 const& NextOrder)
{
	for (int i = Day; i < Day + NextOrder.Time; i++)
	{
		Visit[i] = false;
	}

}

void BackTracking(int Start, int SumPay = 0)
{
	for (int i = Start; i <= N; i++)
	{
		int CurrentPay = 0;
		CurrentPay = Push(i, Schedule[i]);

		if (CurrentPay != 0)	//이번 절차에서 Push 성공함
		{
			SumPay += CurrentPay;
			BackTracking(i + 1, SumPay);

			Release(i, Schedule[i]);	//회수
			SumPay -= CurrentPay;
		}
	}
	MaxPay = max(MaxPay, SumPay);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	Schedule.push_back({});	//시작 인덱스를 1로 맞추기위해 공백 삽입
	for (int i = 0; i < N; i++)
	{
		_int2 inputData{};
		cin >> inputData.Time >> inputData.Pay;
		Schedule.push_back(inputData);
	}
	BackTracking(1);
	cout << MaxPay;
	return 0;
}