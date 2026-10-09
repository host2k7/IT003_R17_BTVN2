<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void merge(vector<long double>& danhsach, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	vector<long double> L(n1), R(n2);

	for (int i = 0; i < n1; i++) L[i] = danhsach[left + i];
	for (int j = 0; j < n2; j++) R[j] = danhsach[mid + 1 + j];

	int i = 0, j = 0;
	int k = left;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			danhsach[k] = L[i];
			i++;
		}

		else
		{
			danhsach[k] = R[j];
			j++;
		}

		k++;
	}

	while (i < n1)
	{
		danhsach[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		danhsach[k] = R[j];
		j++;
		k++;
	}
}

void MergeSort(vector<long double>& danhsach, int left, int right)
{
	if (left >= right)
		return;

	int mid = left + (right - left) / 2;
	MergeSort(danhsach, left, mid);
	MergeSort(danhsach, mid + 1, right);
	merge(danhsach, left, mid, right);
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
		MergeSort(danhsach, 0, danhsach.size() - 1);
		auto end = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(end - start);
		
		ofstream fout;
		fout.open("ketqua.txt", ios::out | ios::app);
		fout << "Done (Merge Sort) bộ dữ liệu thứ " << i + 1 << ": "<< duration.count() << endl;
		cout << "Done " << i + 1 << endl; 
    }
	return 0;
=======
#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void merge(vector<long double>& danhsach, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	vector<long double> L(n1), R(n2);

	for (int i = 0; i < n1; i++) L[i] = danhsach[left + i];
	for (int j = 0; j < n2; j++) R[j] = danhsach[mid + 1 + j];

	int i = 0, j = 0;
	int k = left;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			danhsach[k] = L[i];
			i++;
		}

		else
		{
			danhsach[k] = R[j];
			j++;
		}

		k++;
	}

	while (i < n1)
	{
		danhsach[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		danhsach[k] = R[j];
		j++;
		k++;
	}
}

void MergeSort(vector<long double>& danhsach, int left, int right)
{
	if (left >= right)
		return;

	int mid = left + (right - left) / 2;
	MergeSort(danhsach, left, mid);
	MergeSort(danhsach, mid + 1, right);
	merge(danhsach, left, mid, right);
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
		MergeSort(danhsach, 0, danhsach.size() - 1);
		auto end = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(end - start);
		
		ofstream fout;
		fout.open("ketqua.txt", ios::out | ios::app);
		fout << "Done (Merge Sort) bộ dữ liệu thứ " << i + 1 << ": "<< duration.count() << endl;
		cout << "Done " << i + 1 << endl; 
    }
	return 0;
>>>>>>> 81f20c7 (day len)
}