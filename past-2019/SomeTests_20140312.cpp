// SomeTests_20140312.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

std::string getName() {
	std::string result;
	result	= "10";
	result	+= "5";
	return result;
}

void test1() {
	std::string temp = getName();
	std::cout << temp << std::endl;
}

//static int g_counter = 0;
//
//class Name {
//public:
//	Name(const char* szName) throw() {
//		m_number = ++g_counter;
//		m_buffer = nullptr;
//		if (nullptr != szName) {
//			int len(strlen(szName));
//			if (len > 0) {
//				int size = len + 2;
//				m_buffer = new char[size];
//				strncpy_s(m_buffer, size, szName, len+1);
//			}
//		}
//		std::cout << "created instance #" << m_number << ", " << m_buffer << std::endl;
//	}
//	Name(const std::string& sName) throw() {
//		m_number = ++g_counter;
//		m_buffer = nullptr;
//		if (sName.size() > 0) {
//			int size = sName.size() + 2;
//			m_buffer = new char[size];
//			strncpy_s(m_buffer, size, sName.data(), sName.size()+1);
//		}
//		std::cout << "created instance #" << m_number << ", " << m_buffer << std::endl;
//	}
//	~Name() {
//		std::cout << "freed instance #" << m_number << ", " << m_buffer << std::endl;
//		delete[] m_buffer;
//	}
//
//	const char* name() const {
//		return m_buffer;
//	}
//
//private:
//	//std::string m_sName;
//	char* m_buffer;
//	int m_number;
//};
//
//Name getDefaultName() {
//	return Name("Mr.Brown");
//}
//
//Name& getOptionalName() {
//	return Name("Mr.Green");
//}
//
//void testDefaultFirst() {
//	const Name name(getDefaultName());
//	std::cout << "D1: name: " << name.name() << std::endl;
//}
//
//void testDefaultSecond() {
//	//Name& name(getDefaultName());
//	Name& name = getDefaultName();
//	std::cout << "D2: name: " << name.name() << std::endl;
//	std::cout << "end of fn" << std::endl;
//}
//
//void testOptionalFirst() {
//	const Name name(getOptionalName());
//	std::cout << "O1: name: " << name.name() << std::endl;
//}
//
//void testOptionalSecond() {
//	const Name& name(getOptionalName());
//	std::cout << "O2: name: " << name.name() << std::endl;
//}
//

//void test2() {
//	std::cout << "=====" << std::endl;
//	testDefaultFirst();
//	testDefaultSecond();
//	//testOptionalFirst();
//	//testOptionalSecond();
//	std::cout << "=====" << std::endl;
//}

class Fred {
public:
	Fred(int n) : v(n) {}
	std::vector<int> v;
};

void test3() {
	Fred f(1);
	f.v[0]	= 5;
	std::cout << f.v[0] << std::endl;
	f		= 7;						// is this legal?
	std::cout << f.v[0] << std::endl;	// what is output here?
}

void reverse(std::string& str) {
	std::reverse(str.begin(), str.end());
}

class A {
	int x;
};

class B {
	int y;
};

void test4() {
	char*	ptr		= new char[300];
	strcpy(ptr, "0123456789");
	int*	x		= (int*)ptr;
	x += 2;
	char*	ptr2	= (char*)x;
	std::cout << *ptr2 << std::endl;

#define PRINT_LEN(x) std::cout << #x << ": " << sizeof(x) << std::endl;

	PRINT_LEN(char);
	PRINT_LEN(short);
	PRINT_LEN(int);
	PRINT_LEN(long);
	PRINT_LEN(long long);
	PRINT_LEN(float);
	PRINT_LEN(double);
	PRINT_LEN(size_t);
	PRINT_LEN(void*);
	PRINT_LEN(long long*);

} // test4

const char* getTitle()
{
	static std::string result("Engine");
	return result.c_str();
}

struct Foo {
	virtual ~Foo() {}
	int x;
	Foo() {
		static int x(0);
		this->x = ++x;
	}
};

int _tmain(int argc, _TCHAR* argv[]) {
	Foo* fa = new Foo[10];
	std::cout << "x: " << (*(fa+10)).x << std::endl;
	delete fa;
	return 0;
}

//return;

//std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

//int k = 0;
//for (int i=0; i<981231410; i++) {
//	k+=i*2;
//}

//std::chrono::high_resolution_clock::time_point finish = std::chrono::high_resolution_clock::now();

//std::cout << "k: " << k << "\n";

//std::cout << "default      : " << (finish-start).count() << "\n";
//std::cout << "nanoseconds  : " << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << " ns\n";
//std::cout << "microseconds : " << std::chrono::duration_cast<std::chrono::microseconds>(finish-start).count() << " micros\n";
//std::cout << "milliseconds : " << std::chrono::duration_cast<std::chrono::milliseconds>(finish-start).count() << " ms\n";
//std::cout << "seconds      : " << std::chrono::duration_cast<std::chrono::seconds>(finish-start).count() << " s\n";

//std::cout << "----";
//std::chrono::milliseconds acc;
//for (int i = 0; i<5; i++) {
//	acc += std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
//	std::cout << "step "<< i << ": " << acc.count() << " milliseconds\n";
//}

