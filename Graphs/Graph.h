#pragma once

#include <vector>
#include <iostream>

class Graph {
	virtual void AddEdge(int v1, int v2, int weight = 1) = 0;
	virtual void PrintEdges() const = 0;
};