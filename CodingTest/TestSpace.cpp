#include <iostream>
#include <memory>

using  namespace  std;


struct A
{
	~A() { cout << "A Destructor Call!\n"; }
	weak_ptr<struct B> Content;
};

struct B
{
	~B() { cout << "B Destructor Call!\n"; }
	weak_ptr<struct A> Content;
};

int main()
{
	shared_ptr<A> TestA = make_shared<A>();
	{
		shared_ptr<B> TestB = make_shared<B>();

		cout << TestA.use_count()<<"\n";
		cout << TestB.use_count() << "\n";
	}

	return 0;
}