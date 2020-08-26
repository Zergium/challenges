#include "DummyTests.h"
#include <iostream>


DummyTests::DummyTests()
{
}


DummyTests::~DummyTests()
{
}

template <size_t N>
void call_example(int(&ar)[N]) {
	//void call_example(int ar[5]) {
	ar[3] = 77;
	std::cout << "inside: ";
	for (const auto a : ar)
	{
		std::cout << a << "-";
	}
	std::cout << std::endl;
}
/*static*/ void DummyTests::test01()
{
	int ar[] = { 1,2,3,4,5 };
	std::cout << "before: ";
	for (const auto a : ar)
	{
		std::cout << a << "-";
	}
	std::cout << std::endl;

	call_example(ar);

	std::cout << "after: ";
	for (const auto a : ar)
	{
		std::cout << a << "-";
	}
	std::cout << std::endl;

	std::cout << "done\n";
}

