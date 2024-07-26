#pragma once

#include "Graph.h"

class GraphList : Graph { // перечень ребер
	std::vector<std::pair<int, int>> list;

public:
	GraphList() {};

	void AddEdge(int v1, int v2, int weight = 1) override {
		bool edgeExists = std::find(list.begin(), list.end(), std::make_pair(v1, v2)) != list.end();
		if (edgeExists) {
			std::cout << "Edge " << v1 << " - " << v2 << " already exists \n";
			return;
		}

		list.push_back(std::make_pair(v1, v2));
	};

	void PrintEdges() const override {
		std::cout << "# B E \n";
		for (size_t i = 0; i < list.size(); i++) {
			std::cout << i + 1 << ' ' << list[i].first << ' ' << list[i].second << '\n';
		}
	};
};