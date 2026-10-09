#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

int main()
{
    string filename[10] = {"day1.txt", "day2.txt","day3.txt","day4.txt","day5.txt", "day6.txt",
	"day7.txt","day8.txt","day9.txt","day10.txt"};

	for (int i = 0; i < 10; i++)
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
		sort(danhsach.begin(), danhsach.end());
		auto end = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(end - start);

		ofstream fout;
		fout.open("ketqua.txt", ios::out | ios::app);
		fout << "Done (C++ Sort) bộ dữ liệu thứ " << i + 1 << ": "<< duration.count() << endl;
		cout << "Done " << i + 1 << endl; 
	}
}