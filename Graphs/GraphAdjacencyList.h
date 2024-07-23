#pragma once

#include "Graph.h"

struct VertexNode {
	int vertex;
	VertexNode* next;

	VertexNode(int v) : vertex(v), next(nullptr) {};
};

class GraphAdjacencyList : Graph { // список смежности
	std::vector<VertexNode*> vec;

public:
	GraphAdjacencyList() {};

	void AddEdge(int v1, int v2, int weight = 1) override {
		int max = std::max(v1, v2);
		if (max >= vec.size()) {
			vec.resize(++max);
		}

		VertexNode* new_node = new VertexNode(v2);
		if (vec[v1] == nullptr) {
			vec[v1] = new_node;
			return;
		}

		VertexNode* temp = vec[v1];
		while (temp->next != nullptr && temp->vertex != v2) {
			temp = temp->next;
		}

		if (temp->vertex == v2) {
			std::cout << "Edge " << v1 << " - " << v2 << " already exists\n";
			return;
		}
		temp->next = new_node;
	};

	void PrintEdges() const override {
		std::cout << "#\n";
		for (size_t i = 1; i < vec.size(); i++) {
			std::cout << i << " | ";
			VertexNode* temp = vec[i];
			while (temp != nullptr) {
				std::cout << temp->vertex << " ";
				temp = temp->next;
			}
			std::cout << '\n';
		}
	};
};