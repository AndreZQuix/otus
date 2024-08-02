#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <set>

class Edge {
	int begin;
	int end;
	int weight;

public:
	Edge(int begin, int end, int weight) : begin(begin), end(end), weight(weight) {};
	int Begin() const { return begin; }
	int End() const { return end; }
	int Weight() const { return weight; }
	bool operator<(const Edge& edge) const { return weight < edge.weight; }
};

class Graph {
	std::vector<std::vector<int>> matrix;
	std::vector<int> parents;
	int minimal_weight;

	bool DFS_util(int begin, int end, std::stack<int>& path, std::vector<bool>& visited) {
		visited[begin] = true;

		if (begin == end) {
			return true;
		}

		for (size_t i = 0; i < matrix.size(); i++) {
			if (visited[i]) {
				continue;
			}

			if (matrix[begin][i] == 0) {
				continue;
			}

			if (DFS_util(i, end, path, visited)) {
				path.push(i);
				return true;
			}
		}

		return false;
	}

	bool DFS_with_stack(int vertex, std::stack<int>& stack, std::vector<bool>& visited) {
		visited[vertex] = true;
		for (size_t i = 0; i < matrix.size(); i++) {
			if (matrix[vertex][i] == 0) {
				continue;
			}

			if (!visited[i]) {
				if (!DFS_with_stack(i, stack, visited)) {
					return false;
				}
			}
		}
		stack.push(vertex);
		return true;
	};

	void DFS_Kosaraju(int vertex, std::stack<int>& stack, std::vector<bool>& visited) {
		if (visited[vertex]) {
			return;
		}
		visited[vertex] = true;
		for (size_t i = 0; i < matrix.size(); i++) {
			if (matrix[vertex][i] == 0) {
				continue;
			}

			DFS_Kosaraju(i, stack, visited);
		}
		stack.push(vertex);
	};

	enum VERTEX_STATE {
		NONE, VISITED, COMPLETED
	};

public:
	Graph() : minimal_weight(0) {};
	Graph(const std::vector<std::vector<int>> matrix) : matrix(matrix), minimal_weight(0) {};

	size_t Size() const { return matrix.size(); };

	int GetParent(int vertex) {
		if (parents[vertex] == vertex) return vertex;
		return GetParent(parents[vertex]);
	};

	void AddEdge(int v1, int v2, int weight = 1) {
		v1--;
		v2--;
		int max = std::max(v1, v2);
		if (max >= matrix.size()) {
			matrix.resize(++max);
			for (size_t i = 0; i < matrix.size(); i++) {
				matrix[i].resize(max);
			}
		}

		matrix[v1][v2] = weight;
	};

	void PrintEdges() const {
		std::cout << " ";
		for (size_t i = 0; i < matrix.size(); i++) {
			std::cout << " " << i + 1;
		}
		std::cout << '\n';

		for (size_t i = 0; i < matrix.size(); i++) {
			std::cout << i + 1 << " ";
			for (size_t j = 0; j < matrix.size(); j++) {
				std::cout << matrix[i][j] << " ";
			}
			std::cout << '\n';
		}
	};

	bool DFS_no_orient(int begin, int end) {
		std::stack<int> path;
		std::vector<bool> visited = std::vector<bool>(matrix.size());
		if (!DFS_util(begin - 1, end - 1, path, visited)) {
			std::cout << "DFS path from " << begin << " to " << end << " is not found";
			return false;
		}
		path.push(begin - 1);

		std::string path_str;
		while (!path.empty()) {
			path_str += std::to_string(path.top() + 1) + " ";
			path.pop();
		}

		std::cout << "DFS path from " << begin << " to " << end << " is " << path_str;
		return true;
	};

	bool BFS_no_orient(int begin, int end) {
		begin--;
		end--;

		std::vector<bool> visited = std::vector<bool>(matrix.size());
		visited[begin] = true;
		std::queue<int> queue;
		queue.push(begin);

		std::stack<int> path;
		while (!queue.empty()) {
			int current = queue.front();
			queue.pop();
			path.push(current);
			for (size_t i = 0; i < matrix.size(); i++) {
				if (matrix[current][i] == 0) {
					continue;
				}

				if (visited[i]) {
					continue;
				}

				if (i == end) {
					break;
				}

				queue.push(i);
				visited[i] = true;
			}
		}

		if (!path.empty()) {
			std::string path_str;
			while (!path.empty()) {
				path_str += std::to_string(path.top() + 1) + " ";
				path.pop();
			}
			std::cout << "BFS path from " << begin + 1 << " to " << end + 1 << " is " << path_str << '\n';
		}
		else {
			std::cout << "BFS path from " << begin + 1 << " to " << end + 1 << " is not found \n";
		}
		
		return path.empty();
	};

	bool KahnSort() {
		bool is_any = false;
		size_t column_deleted_count = 0;
		std::queue<int> path;
		std::vector<VERTEX_STATE> visited = std::vector<VERTEX_STATE>(matrix.size());
		do {
			for (size_t i = 0; i < matrix.size(); i++) {
				int sum = 0;
				if (visited[i] != VERTEX_STATE::NONE) {
					column_deleted_count++;
					continue;
				}
				for (size_t j = 0; j < matrix.size(); j++) {
					if (visited[j] != VERTEX_STATE::COMPLETED) {
						sum += matrix[j][i];
					}
				}

				if (sum == 0) {
					visited[i] = VERTEX_STATE::COMPLETED;
					path.push(i);
					is_any = true;
				}
			}
		} while (is_any && column_deleted_count < matrix.size());

		std::string path_str;
		while (!path.empty()) {
			path_str += std::to_string(path.front() + 1) + " ";
			path.pop();
		}
		std::cout << "Kahn topological sorting: " << path_str << '\n';

		return column_deleted_count == matrix.size();
	};

	bool TarjanSort() {
		std::stack<int> path;
		std::vector<bool> visited = std::vector<bool>(matrix.size());
		for (int i = 0; i < matrix.size(); i++) {
			if (!visited[i]) {
				if (!DFS_with_stack(i, path, visited)) {
					return false;
				}
			}
		}

		std::string path_str;
		while (!path.empty()) {
			path_str += std::to_string(path.top() + 1) + " ";
			path.pop();
		}
		std::cout << "Tarjan topological sorting: " << path_str << '\n';
		return true;
	};

	bool Kosaraju(std::list<std::list<int>>& components) {
		Graph rev;
		for (size_t i = 0; i < matrix.size(); i++) {
			for (size_t j = 0; j < matrix.size(); j++) {
				rev.AddEdge(j + 1, i + 1, matrix[i][j]);
			}
		}

		std::cout << "Reversed graph: \n";
		rev.PrintEdges();

		std::stack<int> path;
		std::vector<bool> visited = std::vector<bool>(matrix.size());
		for (int i = 0; i < matrix.size(); i++) {
			if (!visited[i]) {
				if (!rev.DFS_with_stack(i, path, visited)) {
					return false;
				}
			}
		}

		std::stack<int> stack;
		visited = std::vector<bool>(matrix.size());
		while (!path.empty()) {
			int vertex = path.top();
			path.pop();
			std::list<int> vertexes;
			DFS_Kosaraju(vertex, stack, visited);
			while (!stack.empty()) {
				int v = stack.top() + 1;
				vertexes.push_back(v);
				stack.pop();
			}
			if (!vertexes.empty()) {
				components.push_back(vertexes);
			}
		}

		return true;
	};

	std::multiset<Edge> Kruskal() {
		std::multiset<Edge> ret;

		int min_weight = 0;
		std::multiset<Edge> set;
		for (size_t i = 0; i < matrix.size(); i++) {
			for (size_t j = i + 1; j < matrix.size(); j++) {
				if (matrix[i][j] == 0)
					continue;
				Edge edge = Edge(i, j, matrix[i][j]);
				set.emplace(edge);
			}
		}
		for (size_t i = 0; i < matrix.size(); i++) {
			parents.push_back(i);
		}
		
		for (const auto& e : set) {
			int beg = GetParent(e.Begin());
			int end = GetParent(e.End());
			if (end == beg) {
				continue;
			}

			ret.emplace(e);
			min_weight += e.Weight();
			parents[end] = beg;
		}

		std::cout << "Kruskal's result: \n";
		for (const auto& r : ret) {
			std::cout << r.Begin() + 1 << " - " << r.End() + 1 << ": " << r.Weight() << "\n";
		}

		return ret;
	};

	int FullWeight() const {
		int weight = 0;
		for (size_t i = 0; i < matrix.size(); i++) {
			for (size_t j = 0; j < matrix.size(); j++) {
				weight += matrix[i][j];
			}
		}
		return weight;
	};

	Edge SearchMinimalEdge(std::vector<bool>& visited) {
		int weight_min_edge = FullWeight();
		int begin = 0;
		int end = 0;
		for (size_t i = 0; i < matrix.size(); i++) {
			if (!visited[i]) {
				continue;
			}

			for (size_t j = 0; j < matrix.size(); j++) {
				if (visited[j]) {
					continue;
				}

				if (matrix[i][j] == 0) {
					continue;
				}

				if (matrix[i][j] < weight_min_edge) {
					weight_min_edge = matrix[i][j];
					begin = i;
					end = j;
				}
			}
		}

		minimal_weight += weight_min_edge;
		return Edge(begin, end, weight_min_edge);
	};

	std::multiset<Edge> Prim() {
		std::vector<bool> visited = std::vector<bool>(matrix.size());
		size_t count = 0;
		int weight_full = FullWeight();
		std::multiset<Edge> edges;
		while (count < matrix.size()) {
			Edge edge = SearchMinimalEdge(visited);
			if (edge.Begin() != edge.End()) {
				edges.emplace(edge);
			}
			visited[edge.End()] = true;
			count++;
		}

		std::cout << "Prim's result: \n";
		for (const auto& r : edges) {
			std::cout << r.Begin() + 1 << " - " << r.End() + 1 << ": " << r.Weight() << "\n";
		}

		return edges;
	};

	int GetMinDistance(std::vector<int>& dest, std::vector<bool>& visited) {
		int min = INT_MAX;
		for (size_t i = 0; i < matrix.size(); i++) {
			if (visited[i]) {
				continue;
			}

			if (min == INT_MAX || dest[i] < dest[min]) {
				min = i;
			}
		}

		return min;
	};
	
	std::vector<int> Dijkstra(int startVertex) {
		startVertex--;
		std::vector<int> ways = std::vector<int>(matrix.size());
		std::vector<bool> visited = std::vector<bool>(matrix.size());
		for (size_t i = 0; i < ways.size(); i++) {
			ways[i] = INT_MAX;
		}
		ways[startVertex] = 0;

		int min = 0;
		for (size_t i = 0; i < ways.size(); i++) {
			min = GetMinDistance(ways, visited);
			visited[min] = true;
			for (size_t j = 0; j < matrix.size(); j++) {
				if (visited[j]) {
					continue;
				}

				if (matrix[min][j] == 0) {
					continue;
				}

				int weight = ways[min] + matrix[min][j];
				if (weight < ways[j]) {
					ways[j] = weight;
				}
			}
		}

		return ways;
	};
};