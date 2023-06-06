/*

2166 - 다각형의 면적

첫 점을 원점으로 설정,

다음 점들을 벡터의 후보로 지정
두번째 점부터 다음점과 abs(외적연산)/2 를 더해나감
마지막점 -1 까지 연산 후 종료


주의할점

점이 주어지는 순서대로 선을이어 나갔을 때의 삼각형의 넓이를 음수 양수 같이 누적시킨다
마지막에만 절대값으로 출력한다

예시)
4
0 0
0 10
10 10
10 0
는 100이지만

4
0 0
0 10
10 0
10 10
는 0이 나와야 한다

 */



#include<iostream>
#include<vector>
using  namespace  std;

struct _longlong2
{
	long long X;
	long long Y;
};

vector<_longlong2> Vertices{};

long long Cross(_longlong2 const& First, _longlong2 const& Second)
{
	//2배 넓이를 반환 first.x * second.y - first.y * second.y
	return First.X * Second.Y - First.Y * Second.X;
}

long long Area = 0;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int InputSize = 0;
	cin >> InputSize;
	while (InputSize--)
	{
		_longlong2 InputVertex{};
		cin >> InputVertex.X >> InputVertex.Y;
		Vertices.emplace_back(InputVertex);
	}

	for (int i = 1; i < Vertices.size() - 1; i++)
	{
		_longlong2 VFirst = { Vertices[i].X - Vertices[0].X, Vertices[i].Y - Vertices[0].Y };
		_longlong2 VSecond = { Vertices[i + 1].X - Vertices[0].X, Vertices[i + 1].Y - Vertices[0].Y };
		Area += Cross(VFirst, VSecond);

	}
	//cout파 이지만 오늘 만큼은 변절자가 되었다..
	printf("%.1lf", static_cast<double>(abs(Area)) / 2.0);
	return 0;
}