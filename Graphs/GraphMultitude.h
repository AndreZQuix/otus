#pragma once

#include <map>

#include "Graph.h"

class GraphMultitude : Graph { // множество
	std::map<int, std::vector<std::pair<int, int>>> edges;

public:
	GraphMultitude() {};

	void AddEdge(int v1, int v2, int weight = 1) override {
		bool isVertexExists = false;
		auto v1Edges = edges.find(v1);
		if(v1Edges != edges.end()) {
			isVertexExists = std::find_if(v1Edges->second.begin(), v1Edges->second.end(), [v2](const auto& p) { return p.first == v2; }) != v1Edges->second.end();
		}

		if (isVertexExists) {
			std::cout << "Edge " << v1 << " - " << v2 << " already exists \n";
			return;
		}

		edges[v1].push_back(std::make_pair(v2, weight));
	};

	void PrintEdges() const override {
		for (const auto& vertex1 : edges) {
			for (const auto& vertex2 : vertex1.second) {
				std::cout << vertex1.first << " - " << vertex2.first << " " << vertex2.second << '\n';
			}
		}
	};
};