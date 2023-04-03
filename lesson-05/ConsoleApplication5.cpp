#include <iostream>
#include <string>
using namespace std;

class myName
{
public:
	virtual string Name() = 0;
};
//kontstruntor ustawiajacy wartosc pola nick
class nickname : public myName //prywatne pole nick
{
public:
	string Name() //metoda wypisuje wartosc pola nick
	{
		return "Julka";
	}
};
//analogicznie
class fullname : public myName
{
public:
	string Name()
	{
		return "Julia Ordecka";
	}
};

int main()
{
	nickname name1;
	fullname name2;
	myName* ptr;
	ptr = &name1;
	cout << "Nickname - " << ptr->Name();
	ptr = &name2;
	cout << "\nFull name - " << ptr->Name();
	return 0;
}

