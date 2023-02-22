/*
 *11729 - 하노이 탑 이동 순서
 *
 *하노이탑을 푸는데는 명확한 규칙이 존재한다.
 *
 *2개의 원판을 옮겨보자
 *
 *1
 *2
 *0 0 0
 *
 *2번 원판에서 필요한 작업은
 *Start = 1번기둥, Dest = 3번기둥, Temp = 2번 기둥
 *이고 이를 위해 1번 원판은 2번 기둥에 세팅되어야 한다.
 *즉 1번은 Start = 1, Dest = 2, Temp = 3이 된다.
 *
 *맨위의 원판 1번은 움직일 수 있으므로 Dest로 옮겨준다
 *
 *2 1
 *0 0 0
 *
 *이후 2번도 이제 움직일 수 있으므로 움직인다
 *
 *  1 2
 *0 0 0
 *
 *이제 목표원반을 3번 기둥에 옮겼으므로 다시 위의 원판을
 *3번 기둥에 올려야 한다
 *즉 1번을 2 위로 옮겨 놓아야 한다
 *원판 =1, Start =2, Dest=3, Temp=1
 *1번이 2번위로 올라가 로직은 종료된다.
 *
 *간결하게 정리하면
 *
 *disc=2, Start=1, Dest=3, Temp=2
 *disc=1, Start=1, Dest=2, Temp=3
 *1번원판 ->Dest로 이동
 *2번원판 ->Dest로 이동
 *disc=1, Start=2, Dest=3, Temp=1
 *1번원판 ->Dest로 이동
 *종료
 *
 *이번엔 원판 3개 짜리를 옮겨 보자
 *
 *Disc=3, Start=1, Dest=3, Temp=2 ---- 최초 3번원판 이동 호출
 *
 *Disc=2, Start=1, Dest=2, Temp=3 --
 *Disc=1, Start=1, Dest=3, Temp=2  |
 *1번원판 ->Dest로 이동			   |   2번 원판의 이동절차
 *2번원판 ->Dest로 이동			   |
 *disc=1, Start=3, Dest=2, Temp=1 --
 *
 *3번원판 ->Dest로 이동            ---- 3번원판 이동
 *
 *disc=2, Start=2, Dest=3, Temp=1 --
 *disc=1, Start=2, Dest=1, Temp=2  |
 *1번원판 ->Dest로 이동			   |   2번 원판의 이동절차
 *2번원판 ->Dest로 이동			   |
 *disc=1, Start=1, Dest=3, Temp=2 --
 *
 *위의 규칙을 정리해 보면
 *
 *
 *최초 N의 원판을 옮길 때 Start=1, Dest=3, Temp=2로 확정이고
 *N이 Dest로 가기위해서는
 *N-1까지의 원판이 Temp 위치로 이동해야 하기 때문에
 *N-1 은 Start=N에서의 Start, Dest=N에서의 Temp,Temp=N에서의 Dest 의 과정이 필요하다
 *이후에 N번 원판을 옮긴다(원판 이동 출력)
 *이제 다시 N-1을 Temp에서 Dest로 옮겨야 한다.
 *즉 N-1, Start=N에서의Temp,Dest=N에서의Dest,Temp=N에서의Start가 된다.
 *
 *다만 N이 1인경우는 위의 원판이 존재하지않으므로 바로 이동가능하다.
 *N이 1인 경우는 바로 이동처리한다.
 *
 *하노이탑을 옮기기위한 최소 이동 횟수는 2^N-1이다
 *
 */

#include <iostream>

using namespace std;

void Hanoi(int const Disc, int const Start, int const Dest, int const Temp)
{
	if (Disc == 1)
	{
		cout << Start << " " << Dest << "\n";
		return;
	}
	Hanoi(Disc - 1, Start, Temp, Dest);
	cout << Start << " " << Dest << "\n";
	Hanoi(Disc - 1, Temp, Dest, Start);

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N = 0;
	cin >> N;
	cout << (1 << N) - 1 << "\n";
	Hanoi(N, 1, 3, 2);

	return 0;
}