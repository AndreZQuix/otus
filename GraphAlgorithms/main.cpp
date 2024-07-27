#include "Graph.h"

int main() {
	Graph graph(std::vector<std::vector<int>> {
				{ 0, 1, 1, 0, 0, 0, 1 },
				{ 1, 0, 1, 1, 0, 0, 0 },
				{ 1, 1, 0, 0, 0, 0, 0 },
				{ 0, 1, 0, 0, 1, 0, 0 },
				{ 0, 0, 0, 1, 0, 1, 0 },
				{ 0, 0, 0, 0, 1, 0, 1 },
				{ 1, 0, 0, 0, 0, 1, 0 }
	});
	graph.PrintEdges();
	graph.DFS_no_orient(1, 7);
	std::cout << "\n";
	graph.BFS_no_orient(1, 3);
	std::cout << "\n";

	Graph graph2(std::vector<std::vector<int>> {
		{ 0, 1, 0, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 1 },
		{ 0, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1 },
		{ 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 0 }
	});
	graph2.PrintEdges();
	graph2.KahnSort();
	std::cout << "\n";

	Graph graph3;
	graph3.AddEdge(1, 4);
	graph3.AddEdge(1, 2);
	graph3.AddEdge(2, 6);
	graph3.AddEdge(3, 2);
	graph3.AddEdge(4, 6);
	graph3.AddEdge(6, 5);
	graph2.PrintEdges();
	graph2.TarjanSort();


};