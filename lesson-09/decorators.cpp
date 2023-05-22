#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class IntegerSequence
{
public:
	virtual vector<int> Numbers() = 0;
};

class VectorSequence : public IntegerSequence
{
public:
	vector<int> sequence;
	VectorSequence(vector<int>& seq) : sequence(seq)
	{

	}
		vector <int> Numbers() override
	{
		return sequence;
	}


};

class PositiveSequence : public IntegerSequence
{
public:
	IntegerSequence* sequence;
	vector<int> Positive;
	Positive = sequence->Numbers;

	PositiveSequence()
	{

	}

	vector<int> Numbers() override
	{
		for (int i : sequence->Numbers())
		{
			if (i > 0)
			{
				Positive.push_back(i);
			}
		}
	}
	return Positive;
	 

};

class EvenSequence : public IntegerSequence
{
public:
	IntegerSequence* sequence;
	vector<int> Even;
	Even = sequence->Numbers;

	EvenSequence()
	{

	}


	vector<int> Numbers() override
	{
		for (int i : sequence->Numbers())
		{
			if ((i % 2) == 0)
				Even.push_back(i);
		}
	}
	return Even;
};

class SortedSequence : public IntegerSequence
{
public:
	IntegerSequence* sequence;
	vector<int> Sorted;
	SortedSequence()


	vector<int> Numbers() override
	{
		sort(Sorted.begin(), Sorted.end());
	}
	return Sorted;
};

int main()
{

	vector<int> sequence = { -5, 4, 3, 2 };
	IntegerSequence* sequence = VectorSequence(sequence);
	//sequence = PositiveSequence(sequence);
	//sequence = SortedSequence(sequence);
	//sequence = EvenSequence(sequence);

	for (int i : sequence->Numbers())
	{
		cout << i << endl;
	}

}

