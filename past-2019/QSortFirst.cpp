#include "QSortFirst.h"

#include <iostream>
#include <functional>
#include <algorithm>
#include <random>

#include "Utils.h"

QSortFirst::QSortFirst()
{
}


QSortFirst::~QSortFirst()
{
}

void exsort(int arr[], int low, int high) //TODO bad [] place
{
	if (low < high)
	{
		int p = arr[(high + low) / 2]; // arr[low]; // 
		int i = low - 1;
		int j = high + 1;
		while (true)
		{
			do { i++; }
			while (arr[i] < p);
			do { j--; }
			while (arr[j] > p);
			if (i < j)
			{
				std::swap(arr[i], arr[j]);
			}
			else break;
		}
		exsort(arr, low, j);
		exsort(arr, j + 1, high);
	}
}

void sort2(int d[], int lo, int r)
{
	if (lo < r)
	{
		int p = d[r];
		int i = lo;
		for (int k = lo; k < r; k++)
		{
			if (d[k] < p)
			{
				std::swap(d[k], d[i]);
				i++;
			}
		}
		std::swap(d[i], d[r]);

		sort2(d, lo, i - 1);
		sort2(d, i + 1, r);
	}
}

int partition(int* arr, int low, int high)
{
	int p = arr[low]; // arr[(high + low) / 2];
	int i = low - 1;
	int j = high + 1;
	while (true)
	{
		do { i++; }
		while (arr[i] < p);
		do { j--; }
		while (arr[j] > p);
		if (i >= j)
			return j;
		else
			std::swap(arr[i], arr[j]);
	}
}

void sort(int arr[], int low, int high)
{
	if (low < high)
	{
		int p = partition(arr, low, high);
		sort(arr, low, p);
		sort(arr, p + 1, high);
	}
}

void QSortFirst::sort(std::vector<int>& v) //TODO & missed
{
	// ::exsort(v.data(), 0, v.size() - 1); //TODO () missed
	sort2(v.data(), 0, v.size() - 1);
}


/*static */
void QSortFirst::test_sort()
{
	std::cout << __FUNCTION__ " start...\n";

	//std::vector<int> ar = { 1,2,9,8,3,4,7,6 };
	//std::vector<int> ar = {1,2,2,2,2,2,1,1,1,2,2};
	for (int i = 0; i < 10; i++)
	{
		//std::vector<int> ar_org = { 93,75, 62 };
		//std::vector<int> ar = {3,1, 2};
		std::vector<int> ar_org = Utils::create_random_data(15, 100);
		std::vector<int> ar_custom(ar_org);
		QSortFirst::sort(ar_custom);
		std::vector<int> ar_perfect(ar_org);
		std::sort(ar_perfect.begin(), ar_perfect.end());
		bool is_ok = ar_custom == ar_perfect;
		std::cout << "***** sorting works? " << (is_ok ? "true" : "false") << std::endl;
		if (!is_ok)
		{
			std::cout << "origin: " << ar_org << std::endl;
			std::cout << "cst sorted: " << ar_custom << std::endl;
			std::cout << "std sorted: " << ar_perfect << std::endl;
		}
	}
	std::cout << __FUNCTION__ " done\n";
}
