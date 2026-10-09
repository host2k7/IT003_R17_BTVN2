#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

void doicho(long double& a, long double& b)
{
    long double temp = a;
    a = b;
    b = temp;
}

void heapify(vector<long double>& danhsach, int n, int i)
{
    int largest = i; // Khoi tao i la gia tri goc
    int left = 2*i + 1; // Con trai
    int right = 2*i + 2; // Con phai

    // Tim ra largest va day no len dau
    if (left < n && danhsach[left] > danhsach[largest])
    {
        largest = left;
    }

    if (right < n && danhsach[right] > danhsach[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        doicho(danhsach[i], danhsach[largest]);

        heapify(danhsach, n, largest);
    }
}

void Heapsort(vector<long double>& danhsach)
{
    int n = danhsach.size();

    // Build max heap
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(danhsach, n, i);
    }

    // Trich xuat phan tu ra khoi heap
    for (int i = n - 1; i > 0; i--)
    {
        doicho(danhsach[0], danhsach[i]);
        heapify(danhsach, i, 0);
    }
}

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
		Heapsort(danhsach);
		auto end = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(end - start);

		ofstream fout;
		fout.open("ketqua.txt", ios::out | ios::app);
		fout << "Done (Heap Sort) bộ dữ liệu thứ " << i + 1 << ": "<< duration.count() << endl;
		cout << "Done " << i + 1 << endl; 
	}
    return 0;
}