#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
	double Age;
	double Data()
	{
		return this->Age;
	};
	Person()
	{
		this->Age = 0.0;
	};
	Person(double old)
	{
		this->Age = old;
	};
	
	Person(int old) : Person(static_cast<double>(old))
	{

	};
	Person(std::string old) : Person(std::stod(old))
	{

	};
};

int main()
{
	Person defaultAge;
	Person doubleAge(20.5);
	Person stringAge("20");
	Person intAge(20);

	std::cout << defaultAge.Data() << std::endl;
	std::cout << doubleAge.Data() << std::endl;
	std::cout << stringAge.Data() << std::endl;
	std::cout << intAge.Data() << std::endl;

	return 0;
}

