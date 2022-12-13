#include<iostream>
#include <vector>



using namespace std;

class _int2
{
public:
	int X;
	int Y;
	string Name;
	int _1;



	_int2() :X{ 0 }, Y{ 0 }, Name{}
	{
		cout << "�⺻ ������ ȣ��\n";
	}
	_int2(int const x, int const y, string const& name) :X{ x }, Y{ y }, Name{name}
	{
		cout << "�Ű����� ������ ȣ��\n";
	}
	_int2(_int2 const& init)
	{//���� ������
		cout << "��������� ȣ��\n";
		*this = init;
	}
	_int2(_int2&& init)
	{//�̵� ������
		cout << "�̵������� ȣ��\n";
		*this = std::move(init);
	}

public:
	_int2 Get() const
	{// rvalue ��ȯ
		cout << "rvalue ��ȯ ȣ��\n";
		return *this; //��������� lvalue ���µ� ��ȯ�� _int2�� rvalue�� ���⼭ ��� �ٲ������ ã�� ���߾�
	}

	_int2& operator =(_int2&& Right)
	{// �̵� ���� ���� ������
		cout << "xvalue ����\n";
		if (this != &Right)
		{
			this->X = Right.X;
			this->Y = Right.Y;
			this->Name = std::move(Right.Name);
		}
		return *this;
	}

	_int2& operator =(_int2 const& Right)
	{//���� ���� ������
		cout << "lvalue ���� ����\n";
		if (this != &Right)
		{
			this->X = Right.X;
			this->Y = Right.Y;
			this->Name = Right.Name;
		}
		return *this;
	}
};

int main()
{
	_int2 test{ 1,4,"ù �׽�Ʈ ����" };		//�����ε��� ������ ȣ��

	//_int2 test2{ std::move(test) };
	//cout << test.Name;


	cout << "���� ���� \n";
	vector<_int2> arr{};

	//arr.emplace_back(test); //���������� move
	//arr.push_back(test);  //���������� = �����
	//_int2 test3{ test.Get() };


	//cout << test2.X << " " << test2.Y<<"\n\n";
	//cout << "�̹��� lvalue ���縦 �غ���\n";
	//_int2 test3(test);
	//cout << test3.X << " " << test3.Y << "\n\n";

	return 0;
}

