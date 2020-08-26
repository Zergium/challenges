#include "GraphFirst.h"

#include "Utils.h"

#include <iostream>
#include <vector>



GraphFirst::GraphFirst()
{
}


GraphFirst::~GraphFirst()
{
}

using namespace std;

class Graph {
public:
	Graph(int num) : m_numNodes(num), m_edges(num) {};

	void addNode(int fromNode, int toNode) {
		if (fromNode < 0 || fromNode >= m_numNodes) {
			throw exception("passed parameter is not in a valid range");
		}
		if (toNode < 0 || toNode >= m_numNodes) {
			throw exception("passed parameter is not in a valid range");
		}
		m_edges[fromNode].push_back(toNode);
	}

	int getNumNodes() const {
		return m_numNodes;
	}

	const vector<int>& getAdjacent(int node) const {
		return m_edges[node];
	}
private:
	int m_numNodes;
	vector< vector<int> > m_edges;
};

class GraphAlg {
private:
	static void BSDStep(Graph& g, int start, vector<bool>& visited) {
		cout << "node:" << start << " -> ";
		const vector<int>& vecAdj(g.getAdjacent(start));
		for (vector<int>::const_iterator it = vecAdj.begin(); it != vecAdj.end(); it++) {
			if (!visited[*it]) {
				visited[*it] = true;
				BSDStep(g, *it, visited);
			}
		}
	}
public:
	static void BSD(Graph& g, int startNode) {
		vector<bool> visited(g.getNumNodes());
		cout << "init, visited: " << vec2str(visited) << endl;
		visited[startNode] = true;
		BSDStep(g, startNode, visited);
		cout << endl;
		cout << "final, visited: " << vec2str(visited) << endl;
	}
};

/*static*/ void GraphFirst::test()
{
	try {

		std::cout << "GraphFirst" << std::endl;

		Graph g(6);
		g.addNode(0, 2);
		g.addNode(2, 1);
		g.addNode(1, 3);
		g.addNode(3, 1);
		g.addNode(3, 4);

		GraphAlg::BSD(g, 0);
	} catch (std::exception& ex) {
		cout << "ERROR:" << ex.what() << endl;
	}
}