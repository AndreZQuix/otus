#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <list>

class Graph {
	std::vector<std::vector<int>> matrix;

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
	Graph() {};
	Graph(const std::vector<std::vector<int>> matrix) : matrix(matrix) {};

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
};