#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include<mutex>
#include<atomic>
#include<condition_variable>

using namespace std;
std::mutex mtx;
int counterA = 0;
int counterC = 0;
int counterG = 0;
int counterT = 0;
std::string seq;
std::string letter;


void count(std::string &seq, int start, int end)
{
	for (int i = start; i < end; i++)
	{
		if (seq[i] == 'A')
		{
			std::lock_guard<std::mutex> lock(mtx);
			counterA++;
			//lock.unlock();
		}
		else if (seq[i] == 'C')
		{
			std::lock_guard<std::mutex> lock(mtx);
			counterC++;
			//lock.unlock();
		}
		else if (seq[i] == 'G')
		{
			std::lock_guard<std::mutex> lock(mtx);
			counterG++;
			//lock.unlock();
		}
		else if (seq[i] == 'T')
		{
			std::lock_guard<std::mutex> lock(mtx);
			counterT++;
			//lock.unlock();
		}
	}
}

int main()
{
	std::vector<std::thread>threads;
	std::string seq = "CTGATAGTTT";
	int start = 0;
	int sectionlength = seq.length() / 2;
	int end = sectionlength;
	
	for (int i = 0; i < 2; i++)
	{
		int start = i * sectionlength;
		threads.emplace_back(count, ref(seq), start, end);
		end = seq.length() / (i + 1);
	}

	for (std::thread& t : threads) 
	{
		t.join();
	}
	std::cout << "A frequency: " << counterA << endl;
		std::cout << "C frequency: " << counterC << endl;
		std::cout << "G frequency: " << counterG << endl;
		std::cout << "T frequency: " << counterT << endl;

}


