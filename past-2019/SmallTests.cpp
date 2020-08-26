#include <tchar.h>

//-------------------------------------------------

#include <iostream>
#include <string>

class Name {
public:
	Name(const char* szName) throw()
		: m_sName(szName) {
	}
	Name(const std::string& sName) throw()
		: m_sName(sName) {
	}

	const std::string& name() const {
		return m_sName;
	}

private:
	std::string m_sName;
};

Name getDefaultName() {
	return Name("Mr.Brown");
}

Name& getOptionalName() {
	return Name("Mr.Green");
}

void testDefaultFirst() {
	const Name name(getDefaultName());
	std::cout << "D1: name: " << name.name() << std::endl;
}

void testDefaultSecond() {
	const Name& name(getDefaultName());
	std::cout << "D2: name: " << name.name() << std::endl;
}

void testOptionalFirst() {
	const Name name(getOptionalName());
	std::cout << "O1: name: " << name.name() << std::endl;
}

void testOptionalSecond() {
	const Name& name(getOptionalName());
	std::cout << "O2: name: " << name.name() << std::endl;
}
//-------------------------------------------------

int _tmain(int argc, _TCHAR* argv[])
{
	testDefaultFirst();
	testDefaultSecond();
	testOptionalFirst();
	testOptionalSecond();
	int d;
	std::cin >> d;
	return 0;
}

