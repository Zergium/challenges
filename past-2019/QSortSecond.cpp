#include "QSortSecond.h"

#include <iostream>
#include <vector>
#include <algorithm>

#include "Utils.h"

QSortSecond::QSortSecond()
{
}


QSortSecond::~QSortSecond()
{
}

void sort_2(int d[], int lo, int hi)
{
	if (lo < hi)
	{
		int p = d[hi];
		int idx = lo;
		for (int i = lo; i < hi; i++)
		{
			if (d[i] < p)
			{
				std::swap(d[idx], d[i]);
				idx++;
			}
		}
		std::swap(d[idx], d[hi]);

		sort_2(d, lo, idx - 1);
		sort_2(d, idx + 1, hi);
	}
}

void sort_2(std::vector<int>& v)
{
	sort_2(v.data(), 0, v.size() - 1);
}


/*static*/
void QSortSecond::do_test()
{
	std::cout << __FUNCTION__ " start...\n";

	for (int i = 0; i < 20; i++)
	{
		//std::vector<int> ar_org = {93, 75, 62};
		//std::vector<int> ar = {3,1, 2};
		std::vector<int> ar_org = Utils::create_random_data(1000, 100);
		std::vector<int> ar_custom(ar_org);
		::sort_2(ar_custom);
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
