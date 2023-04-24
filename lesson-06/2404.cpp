//szablony - template - zagniezdzanie klasy wewnatrz interfejsu
#include<iostream>
#include <string>
#include <memory>
#include <sstream>
#include <cassert>
using namespace std;

class Sequence
{
public:
	virtual int Length() = 0;
};

class FakeSequence : public Sequence //klasa implemetuje sequence
{
public:
	int Length() override
	{
		return 100;
	}
};

class Gene
	{
	private: //powinno byc private, enkapsulacja - wartosci sa niedostepne bezposrednio dla uzytkownika
		string name_;
		shared_ptr<Sequence> sequence_;

	public:
		//konstruktor 
		Gene(string name, shared_ptr<Sequence> sequence) :
			sequence_(sequence), name_(name) {};

		string JSON() //
		{
			stringstream ss;
			ss << "{" << "\"name\":" << name_ << "\"," << "\"length\": \"" << sequence_->Length() << "}"; //+ spacje
			return ss.str(); //zwracamy takie cos co zrobi z tego jednego string
		}





	};

	int main()
	{
		shared_ptr<Sequence> fake_seq = make_shared<FakeSequence>();
		Gene gene("BALF5", fake_seq);
		cout << gene.JSON() << endl;
		//assert(fake_seq->Length()==100); sprawdzamy czy oczekiwany rezultat jest spelniony - dodac biblioteke cassert
		return 0;
	}
