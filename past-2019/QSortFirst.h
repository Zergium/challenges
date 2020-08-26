#pragma once

#include <vector>

class QSortFirst
{
public:
	QSortFirst();
	~QSortFirst();

	static void sort(std::vector<int>& v);

	static void test_sort();
};

