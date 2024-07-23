#pragma once

#include <map>

#include "Graph.h"

class GraphStruct : Graph { // структура с оглавлением
	std::map<int, int> struct_table;
	std::vector<int> vertexes;
	int max_vertex;

public:
	GraphStruct() : max_vertex(0) {};

	void AddEdge(int v1, int v2, int weight = 1) override {
		auto beg_r = struct_table.find(v1);
		auto temp = beg_r;
		auto end_index = beg_r == struct_table.end() ? beg_r == struct_table.begin() ? 0 : (--temp)->second : beg_r->second;
		auto beg_index = beg_r == struct_table.end() ? end_index : (--beg_r) == struct_table.end() ? end_index : beg_r->second;

		for (int i = beg_index; i != end_index; i++) {
			if (vertexes[i] == v2) {
				std::cout << "Edge " << v1 << " - " << v2 << " already exists\n";
				return;
			}
		}

		if (max_vertex < v1) {
			max_vertex = v1;
		}
		for (int i = v1; i <= max_vertex; i++) {
			if (struct_table[i] == 0) {
				struct_table[i] = struct_table[i - 1];
			}
			struct_table[i]++;
		}
		vertexes.insert(vertexes.begin() + end_index, v2);
	};

	void PrintEdges() const override {
		std::cout << "\n";
		for (int i = 0; i < struct_table.size() - 1; i++) {
			std::cout << i + 1 << ' ';
		}
		std::cout << "\n";
		for (int i = 0; i < struct_table.size() - 1; i++) {
			std::cout << struct_table.at(i) << ' ';
		}

		std::cout << "\n\n";
		for (int i = 0; i < vertexes.size(); i++) {
			std::cout << i << ' ';
		}
		std::cout << "\n";
		for (int i = 0; i < vertexes.size(); i++) {
			std::cout << vertexes[i] << ' ';
		}
	};
};