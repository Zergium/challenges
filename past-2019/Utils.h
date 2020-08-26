#pragma once

#include <ostream>
#include <vector>
#include <sstream>

class Utils
{
private:
	Utils();
	~Utils();
public:
	static std::vector<int> create_random_data(int n, int max);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec)
{
	for (auto& el : vec)
	{
		os << el << ' ';
	}
	return os;
}

std::ostream& operator<<(std::ostream& os, const std::vector<bool>& vec);
std::string vec2str(const std::vector<bool>& v);