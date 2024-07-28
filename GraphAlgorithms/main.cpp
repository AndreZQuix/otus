#include "Graph.h"

int main() {
	Graph simple_graph;
	simple_graph.AddEdge(1, 2);
	simple_graph.AddEdge(2, 5);
	simple_graph.AddEdge(5, 3);
	simple_graph.AddEdge(3, 4);
	simple_graph.AddEdge(6, 3);
	simple_graph.AddEdge(8, 9);
	simple_graph.AddEdge(6, 7);
	simple_graph.AddEdge(7, 9);
	simple_graph.AddEdge(9, 10);
	simple_graph.AddEdge(2, 10);
	simple_graph.PrintEdges();
	std::cout << "\n";

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
	graph3.PrintEdges();
	graph3.TarjanSort();
	std::cout << '\n';

	Graph graph4(std::vector<std::vector<int>> {
		{ 0, 1, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 0, 1, 1, 0, 0 },
		{ 0, 0, 0, 1, 0, 0, 1, 0 },
		{ 0, 0, 1, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 1, 0 },
		{ 0, 0, 0, 0, 0, 1, 0, 0 },
		{ 0, 0, 0, 1, 0, 0, 1, 0 },
	});
	graph4.PrintEdges();
	std::list<std::list<int>> result;
	graph4.Kosaraju(result);
	std::cout << "Strongly connected components: ";
	for (const auto& lst : result) {
		for (const auto v : lst) {
			std::cout << v << " ";
		}
		std::cout << "| ";
	}
};