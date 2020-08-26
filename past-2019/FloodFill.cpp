#include "FloodFill.h"

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

FloodFill::FloodFill()
{
}

FloodFill::~FloodFill()
{
}

namespace first_attempt {

struct Point {
	Point(int ai, int aj) : i(ai), j(aj) {  };
	int i;
	int j;
};

static const vector<pair<int, int> > neighbour_shift =
{ {-1,0,}, {0, -1}, {+1,0}, {0,+1} };

int flood(const vector<vector<int> > & grid, vector< vector<bool> > & used, const Point& start) {
	auto isValid = [&](const Point& p) -> bool {
		return p.i < grid[0].size() && p.j < grid.size() && !used[p.j][p.i];
	};
	int amount = 0;
	deque<Point> to_check;
	int color = grid[start.j][start.i];
	used[start.j][start.i] = true;
	to_check.push_back(start);
	while (!to_check.empty()) {
		Point p = to_check.front();
		to_check.pop_front();

		amount++;

		for (const pair<int,int>& shift: neighbour_shift) {
			Point neighbour(p);
			neighbour.i += shift.first;
			neighbour.j += shift.second;
			if (isValid(neighbour)) {
				if (grid[neighbour.j][neighbour.i] == color) {
					used[neighbour.j][neighbour.i] = true;
					to_check.push_back(neighbour);
				}
			}
		}
	}
	cout << "INFO: found " << amount << " cells for " << color << endl;
	return amount;
}

int findLargestZone( const vector< vector< int > >& grid) {
	int m = grid.size();
	if (m < 1) return 0;

	int n = grid[0].size();
	if (n < 1) return 0;

	int bestAmount = 0;
	vector<vector<bool> > used(m, vector<bool>(n, false));

	for (int j=0; j<m; ++j) {
		for (int i = 0; i < n; ++i) {
			if (!used[j][i]) {
				int amount = flood(grid, used, Point(i, j));
				if (amount > bestAmount) {
					bestAmount = amount;
				}
			} else {
				cout << "INFO: skip " << j << ", " << i << " -> already used." << endl;
			}
		}
	}
	return bestAmount;
}


}



struct Coord {
	Coord(int ai, int aj) : i(ai), j(aj) {};
	Coord operator+(const Coord& other) {
		return Coord(this->i + other.i, this->j + other.j);
	}
	int i, j;
};

static vector<Coord> neighbourds_shift = {
	{-1,0},
	{0,-1},
	{1,0},
	{0,1}, };

class Grid {
public:
	Grid(const vector<vector< int > >& field) : m_grid(field) {};
	vector<vector< int > > m_grid;
};





void FloodFill::do_test() {
	cout << "flood done" << endl;

	vector< vector< int > > grid =
	{
		{ 1,2,2,2,2,2, },
		{ 1,0,1,0,1,1, },
		{ 1,2,3,4,4,4, },
		{ 1,2,4,4,2,4, },
	};

	int amount = first_attempt::findLargestZone(grid);

	cout << "largest zone: " << amount << endl;

}








