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
	std::cout << '\n';

	Graph graph5;
	graph5.AddEdge(1, 2, 2);
	graph5.AddEdge(2, 1, 2);
	graph5.AddEdge(1, 3, 2);
	graph5.AddEdge(3, 1, 2);
	graph5.AddEdge(1, 5, 1);
	graph5.AddEdge(5, 1, 1);
	graph5.AddEdge(1, 7, 3);
	graph5.AddEdge(7, 1, 3);
	graph5.AddEdge(3, 2, 3);
	graph5.AddEdge(2, 3, 3);
	graph5.AddEdge(2, 4, 3);
	graph5.AddEdge(4, 2, 3);
	graph5.AddEdge(4, 5, 2);
	graph5.AddEdge(5, 4, 2);
	graph5.AddEdge(5, 6, 4);
	graph5.AddEdge(6, 5, 4);
	graph5.AddEdge(6, 7, 2);
	graph5.AddEdge(7, 6, 2);
	graph5.PrintEdges();
	graph5.Kruskal();
	graph5.Prim();
	std::cout << '\n';

	Graph graph6(std::vector<std::vector<int>> {
		{ 0, 7, 9, 0, 0, 14 },
		{ 7, 0, 10, 15, 0, 0 },
		{ 9, 10, 0, 11, 0, 2 },
		{ 0, 15, 11, 0, 6, 0 },
		{ 0, 0, 0, 6, 0, 9 },
		{ 14, 0, 2, 0, 9, 0 },
	});
	graph6.PrintEdges();
	std::cout << "\nDijkstra's result: \n";
	for (size_t i = 1; i <= graph6.Size(); i++) {
		std::cout << "Vertex " << i << " : ";
		std::vector<int> result = graph6.Dijkstra(i);
		for (size_t j = 0; j < result.size(); j++) {
			std::cout << result[j] << " ";
		}
		std::cout << '\n';
	}
	
};