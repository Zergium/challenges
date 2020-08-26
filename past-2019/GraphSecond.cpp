#include "GraphSecond.h"

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <deque>

using namespace std;

GraphSecond::GraphSecond()
{
}


GraphSecond::~GraphSecond()
{
}



struct Node {
	int id;
	vector<int> adjacent;
	bool visited;
};


class Graph2 {
public:
	int numNodes;
	std::map<int, Node> nodes;

	void addNode(int fromNode, int toNode) {
		Node& node = nodes[fromNode];
		node.id = fromNode;
		node.adjacent.push_back(toNode);
	}
};

bool checkPathExistence2(Graph2& g, int fromId, int toId) {
	cout << "---------------" << endl;
	int i = 0;
	for (auto& it: g.nodes) {
		i++;
		it.second.visited = false;
	}
	auto it = g.nodes.find(fromId);
	if(it == g.nodes.end()) {
		return false;
	}
	Node* pSourceNode = &(it->second);

	it = g.nodes.find(toId);
	if (it== g.nodes.end()) {
		return false;
	}
	Node* pTargetNode = &(it->second);

	deque<Node*> nodesToCheck;
	nodesToCheck.push_back(pSourceNode);
	pSourceNode->visited = true;

	while (!nodesToCheck.empty()) {
		Node* pNode = nodesToCheck.front();
		nodesToCheck.pop_front();

		cout << "node.id = " << pNode->id << ", in queue: ";
		for (auto pNode: nodesToCheck) {
			cout << pNode->id << ";";
		}
		cout << endl;

		for (int id: pNode->adjacent) {
			auto itAdj = g.nodes.find(id);
			if (itAdj != g.nodes.end()) {
				Node* next = &(itAdj->second);
				cout << "  next.id = " << next->id << endl;
				if (next == pTargetNode)
					return true;

				if (!next->visited) {
					nodesToCheck.push_back(next);
					next->visited = true;
				}
			}
		}
	}

	return false;
}

struct Record {
	int val;
	string str;
};
void map_test() {
	typedef map<int, Record> MapCheck;
	MapCheck map1 = {{1,{0, "1-01"}}, {5,{0, "1-05"}}, {9,{0, "1-09"}}};
	auto fnPrint=[&](const std::string& s) {
		cout << "map " << s << ": ";
		for (MapCheck::const_iterator it=map1.cbegin(); it!=map1.cend(); it++) {
			cout << it->first << ": " << "{" << it->second.val << ";";
			cout << "\"" << it->second.str.c_str() << "\"";
			cout << "}  ";
		}
		cout << endl;
	};

	fnPrint("initial");

	for (auto it : map1) {
		it.second.val = it.first * 10;
		it.second.str = "first";
	}
	fnPrint("after first");

	for (auto& it : map1) {
		it.second.val = it.first * 2;
		it.second.str = "second";
	}
	fnPrint("after second");

	for (MapCheck::iterator it = map1.begin(); it != map1.end(); it++) {
		it->second.val = it->first * 3;
		it->second.str = "third";
	}
	fnPrint("after third");

	for (MapCheck::iterator it = map1.begin(); it != map1.end(); it++) {
		pair<int, Record> r(*it);
		it->second.val = r.first * 4;
		it->second.str = "forth";
	}
	fnPrint("after forth");


}

void GraphSecond::do_test() {

	//map_test();

	Graph2 g;
	g.addNode(0, 1);
	g.addNode(0, 2);
	g.addNode(1, 3);
	g.addNode(1, 6);
	g.addNode(1, 7);
	g.addNode(1, 8);
	g.addNode(2, 3);
	g.addNode(3, 5);
	g.addNode(4, 0);
	g.addNode(5, 0);
	g.addNode(6, 0);
	g.addNode(7, 0);
	g.addNode(8, 9);
	g.addNode(9, 1);
	bool res = checkPathExistence2(g, 0, 4);
	cout << "check is " << (res?"true":"false") << endl;
}
