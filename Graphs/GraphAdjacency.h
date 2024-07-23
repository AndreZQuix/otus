#pragma once

#include "Graph.h"

class GraphAdjacency : Graph {
	std::vector<std::vector<int>> matrix;

public:
	GraphAdjacency() {};
	GraphAdjacency(std::vector<std::vector<int>> matrix) : matrix(matrix) {};
	GraphAdjacency(size_t vertexes_amount) {
		++vertexes_amount;
		matrix = std::vector<std::vector<int>>(vertexes_amount);
		for (size_t i = 0; i < vertexes_amount; i++) {
			matrix[i] = std::vector<int>(vertexes_amount);
		}
	};

	void AddEdge(int v1, int v2, int weight = 1) override {
		int max = std::max(v1, v2);
		if (max >= matrix.size()) {
			matrix.resize(++max);
			for (size_t i = 0; i < matrix.size(); i++) {
				matrix[i].resize(max);
			}
		}

		matrix[v1][v2] = weight;
	};

	void PrintEdges() const override {
		std::cout << " ";
		for (size_t i = 1; i < matrix.size(); i++) {
			std::cout << " " << i;
		}
		std::cout << '\n';

		for (size_t i = 1; i < matrix.size(); i++) {
			std::cout << i << " ";
			for (size_t j = 1; j < matrix.size(); j++) {
				std::cout << matrix[i][j] << " ";
			}
			std::cout << '\n';
		}
	};
};