#include <iostream>

using namespace std;

int Num_S{};
string func[6]{ "add","remove","check","toggle","all", "empty" };
enum class Func
{
	add = 0, remove, check, toggle, all, empty,
};

void Call_Func(Func const Comand_Func/*, int const Value_S*/)
{
	int Mask_S = 0;
	switch (Comand_Func)
	{
	case Func::add:
	{
		cin >> Mask_S;
		Num_S |= 1 << Mask_S;
		break;
	}
	case Func::remove:
	{
		cin >> Mask_S;
		Num_S &= ~(1 << Mask_S);
		break;
	}
	case Func::check:
	{
		cin >> Mask_S;
		if (Num_S & (1 << Mask_S))
			cout << "1" << "\n";
		else
			cout << "0" << "\n";


		break;
	}
	case Func::toggle:
	{
		cin >> Mask_S;

		Num_S ^= 1 << Mask_S;
		break;
	}
	case Func::all:
	{

		Num_S = (1 << 21) - 1;
		break;
	}
	case Func::empty:
	{

		Num_S = 0;
		break;
	}
	default:
		break;
	}
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int TestCase = 0;
	cin >> TestCase;
	while (TestCase--)
	{
		string Comand_Func{};
		int Value_S = 0;
		cin >> Comand_Func /*>> Value_S*/;
		for (int i = 0; i < 6; i++)
		{
			if (func[i] == Comand_Func)
			{
				Call_Func(static_cast<Func>(i)/*, Value_S*/);
				break;
			}
		}

	}




	return 0;
}
