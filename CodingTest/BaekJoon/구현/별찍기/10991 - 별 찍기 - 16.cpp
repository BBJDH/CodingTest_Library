/*
 *10991 - �� ��� - 16
 *
 *�Է� : 5
 *
 *0000*
 *000*0*
 *00*0*0*
 *0*0*0*0*
 **0*0*0*0*
 *
 *
 *�� �׸�ó�� �Է� ���� ���ڿ� N�� ����
 *
 *N-(���� ��) ��ŭ ���� ������ ��� �� ���� ����� ������
 *
 *�ٸ� ����ϴ� ���� Ȧ¦�� ���� ���� ������ ������ָ� �ȴ�.
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