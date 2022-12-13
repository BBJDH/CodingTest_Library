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
		cout << "기본 생성자 호출\n";
	}
	_int2(int const x, int const y, string const& name) :X{ x }, Y{ y }, Name{name}
	{
		cout << "매개변수 생성자 호출\n";
	}
	_int2(_int2 const& init)
	{//복사 생성자
		cout << "복사생성자 호출\n";
		*this = init;
	}
	_int2(_int2&& init)
	{//이동 생성자
		cout << "이동생성자 호출\n";
		*this = std::move(init);
	}

public:
	_int2 Get() const
	{// rvalue 반환
		cout << "rvalue 반환 호출\n";
		return *this; //만들어진건 lvalue 였는데 반환은 _int2로 rvalue라서 여기서 어떻게 바뀌는지는 찾지 못했어
	}

	_int2& operator =(_int2&& Right)
	{// 이동 복사 대입 연산자
		cout << "xvalue 복사\n";
		if (this != &Right)
		{
			this->X = Right.X;
			this->Y = Right.Y;
			this->Name = std::move(Right.Name);
		}
		return *this;
	}

	_int2& operator =(_int2 const& Right)
	{//복사 대입 연산자
		cout << "lvalue 복사 시행\n";
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
	_int2 test{ 1,4,"첫 테스트 생성" };		//오버로딩된 생성자 호출

	//_int2 test2{ std::move(test) };
	//cout << test.Name;


	cout << "벡터 생성 \n";
	vector<_int2> arr{};

	//arr.emplace_back(test); //내부적으로 move
	//arr.push_back(test);  //내부적으로 = 사용함
	//_int2 test3{ test.Get() };


	//cout << test2.X << " " << test2.Y<<"\n\n";
	//cout << "이번엔 lvalue 복사를 해보자\n";
	//_int2 test3(test);
	//cout << test3.X << " " << test3.Y << "\n\n";

	return 0;
}

