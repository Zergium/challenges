#include "Utils.h"
#include <random>
#include <algorithm>
#include <functional>


Utils::Utils()
{
}


Utils::~Utils()
{
}

std::vector<int> Utils::create_random_data(int n, int max)
{
	std::random_device r;
	std::seed_seq seed{r(), r(), r(), r(), r(), r(), r(), r()};
	std::mt19937 eng(seed); // a source of random arr

	std::uniform_int_distribution<int> dist(0, max);
	std::vector<int> v(n);

	generate(begin(v), end(v), std::bind(dist, eng));
	return v;
}



std::ostream& operator<<(std::ostream& os, const std::vector<bool>& vec)
{
	for (const auto& el : vec)
	{
		os << (el ? "1" : "0") << ' ';
	}
	return os;
}

std::string vec2str(const std::vector<bool>& v) {
	std::stringstream ss;
	for (bool b : v) {
		ss << (b ? "1" : "0") << " ";
	}
	return ss.str();
}
