#pragma once

#include "Graph.h"

class GraphAdjacencyVec : Graph { // вектор смежности
	std::vector<std::vector<int>> vec;

public:
	GraphAdjacencyVec() {};

	void AddEdge(int v1, int v2, int weight = 1) override {
		int max = std::max(v1, v2);
		if (max >= vec.size()) {
			vec.resize(max);
			for (size_t i = 0; i < vec.size(); i++) {
				vec[i].resize(max);
			}
		}

		auto real_index_v1 = v1 - 1;
		for (size_t i = 0; i < vec[real_index_v1].size(); i++) {
			if (vec[real_index_v1][i] == 0) {
				vec[real_index_v1][i] = v2;
				break;
			}
		}

		auto real_index_v2 = v2 - 1;
		for (size_t i = 0; i < vec[real_index_v2].size(); i++) {
			if (vec[real_index_v2][i] == 0) {
				vec[real_index_v2][i] = v1;
				break;
			}
		}
	};

	void PrintEdges() const override {
		std::cout << "#   Max\n";
		for (size_t i = 0; i < vec.size(); i++) {
			std::cout << i + 1 << " | ";
			for (size_t j = 0; j < vec[i].size(); j++) {
				std::cout << vec[i][j] << " ";
			}
			std::cout << '\n';
		}
	};
};