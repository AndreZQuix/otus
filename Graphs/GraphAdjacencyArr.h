#pragma once

#include "Graph.h"

class GraphAdjacencyArr : Graph { // массив смежности
	std::vector<std::vector<int>> vec;

public:
	GraphAdjacencyArr() {};

	void AddEdge(int v1, int v2, int weight = 1) override {
		int max = std::max(v1, v2);
		if (max >= vec.size()) {
			vec.resize(++max);
		}

		vec[v1].push_back(v2);
		vec[v2].push_back(v1);
	};

	void PrintEdges() const override {
		std::cout << "#   Max\n";
		for (size_t i = 1; i < vec.size(); i++) {
			std::cout << i << " | ";
			for (size_t j = 0; j < vec[i].size(); j++) {
				std::cout << vec[i][j] << " ";
			}
			std::cout << '\n';
		}
	};
};