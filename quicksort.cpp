#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void doicho(long double& a, long double& b)
{
	long double temp = a;
	a = b;
	b = temp;
}

int partition(vector<long double>& danhsach, int low, int high)
{
	doicho(danhsach[low + (high - low) / 2], danhsach[high]);
	long double pivot = danhsach[high];
	int i = low - 1;

	for (int j = low; j < high; j++)
	{
		if (danhsach[j] < pivot)
		{
			i++;
			doicho(danhsach[i], danhsach[j]);
		}
	}

	doicho(danhsach[i + 1], danhsach[high]);
	return i + 1;
}

void Quick_sort(vector<long double>& danhsach, int low, int high)
{
	if (low >= high) return;

	int pi = partition(danhsach, low, high);

	Quick_sort(danhsach, low, pi - 1);
	Quick_sort(danhsach, pi + 1, high);
}

int main()
{
	string filename[10] = {"day1.txt", "day2.txt","day3.txt","day4.txt","day5.txt", "day6.txt",
	"day7.txt","day8.txt","day9.txt","day10.txt"};

	for (int i = 0; i< 10; i++)
	{
		string name = filename[i];
		vector<long double> danhsach;
		ifstream inFile(name);
		long double temp;

		while (inFile >> temp)
		{
			danhsach.push_back(temp);
		}

		//Tinh thoi gian chay thuat toan
		auto start = high_resolution_clock::now();
		Quick_sort(danhsach, 0, danhsach.size() - 1);
		auto end = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(end - start);

		ofstream fout;
		fout.open("ketqua.txt", ios::out | ios::app);
		fout << "Done (Quick Sort) bộ dữ liệu thứ " << i + 1 << ": "<< duration.count() << endl;
		cout << "Done " << i + 1 << endl; 
	}
	return 0;
}