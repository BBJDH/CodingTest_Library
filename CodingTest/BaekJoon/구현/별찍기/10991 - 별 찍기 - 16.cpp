/*
 *10991 - 별 찍기 - 16
 *
 *입력 : 5
 *
 *0000*
 *000*0*
 *00*0*0*
 *0*0*0*0*
 **0*0*0*0*
 *
 *
 *위 그림처럼 입력 받은 숫자에 N에 대해
 *
 *N-(현재 줄) 만큼 별을 공백을 출력 후 별을 출력해 나간다
 *
 *다만 출력하는 별을 홀짝에 따라 별과 공백을 출력해주면 된다.
 *
 */

#include<iostream>
using namespace std;

int main()
{
    int CountOfLine = 0;
    cin >> CountOfLine;

    for (int blank = CountOfLine - 1; blank >= 0; blank--)
    {
        for (int i = 0; i < blank; i++)
        {
            cout << " ";
        }
        for (int i = 0; i < (CountOfLine - blank) * 2 - 1; i++)
        {
            if (i % 2 == 1)
            {
                cout << " ";
            }
            else
            {
                cout << "*";
            }
        }
        cout << "\n";
    }
    return 0;
}