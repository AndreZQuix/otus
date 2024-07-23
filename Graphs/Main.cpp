#include "GraphMultitude.h"
#include "GraphAdjacency.h"
#include "GraphList.h"
#include "GraphAdjacencyVec.h"
#include "GraphAdjacencyArr.h"
#include "GraphAdjacencyList.h"
#include "GraphStruct.h"

int main() {
	std::cout << "GraphMultitude \n";
	GraphMultitude grm;
	grm.AddEdge(1, 4);
	grm.AddEdge(1, 5);
	grm.AddEdge(2, 5);
	grm.AddEdge(2, 6);
	grm.AddEdge(3, 4);
	grm.AddEdge(3, 7);
	grm.AddEdge(3, 7);
	grm.AddEdge(7, 3);
	grm.PrintEdges();

	std::cout << "\nGraphAdjacency \n";
	GraphAdjacency gra;
	gra.AddEdge(1, 4);
	gra.AddEdge(1, 5);
	gra.AddEdge(2, 5);
	gra.AddEdge(2, 6);
	gra.AddEdge(3, 4);
	gra.AddEdge(3, 7);
	gra.AddEdge(3, 7);
	gra.AddEdge(7, 3);
	gra.PrintEdges();

	std::cout << "\nGraphList \n";
	GraphList grl;
	grl.AddEdge(1, 2);
	grl.AddEdge(1, 3);
	grl.AddEdge(2, 5);
	grl.AddEdge(3, 4);
	grl.AddEdge(4, 5);
	grl.AddEdge(5, 5);
	grl.PrintEdges();

	std::cout << "\nGraphAdjacencyVec \n";
	GraphAdjacencyVec grav;
	grav.AddEdge(1, 2);
	grav.AddEdge(1, 3);
	grav.AddEdge(2, 3);
	grav.AddEdge(2, 4);
	grav.AddEdge(2, 5);
	grav.AddEdge(3, 4);
	grav.AddEdge(4, 5);
	grav.PrintEdges();

	std::cout << "\nGraphAdjacencyArr \n";
	GraphAdjacencyArr graa;
	graa.AddEdge(1, 2);
	graa.AddEdge(1, 3);
	graa.AddEdge(2, 3);
	graa.AddEdge(2, 4);
	graa.AddEdge(2, 5);
	graa.AddEdge(3, 4);
	graa.AddEdge(4, 5);
	graa.PrintEdges();

	std::cout << "\nGraphAdjacencyList \n";
	GraphAdjacencyList gral;
	gral.AddEdge(1, 2);
	gral.AddEdge(2, 1);
	gral.AddEdge(1, 3);
	gral.AddEdge(3, 1);
	gral.AddEdge(2, 3);
	gral.AddEdge(3, 2);
	gral.AddEdge(2, 4);
	gral.AddEdge(4, 2);
	gral.AddEdge(2, 5);
	gral.AddEdge(5, 2);
	gral.AddEdge(3, 4);
	gral.AddEdge(4, 3);
	gral.AddEdge(4, 5);
	gral.AddEdge(4, 5);
	gral.AddEdge(5, 4);
	gral.PrintEdges();

	std::cout << "\nGraphStruct \n";
	GraphStruct grs;
	grs.AddEdge(1, 2);
	grs.AddEdge(2, 1);
	grs.AddEdge(1, 3);
	grs.AddEdge(3, 1);
	grs.AddEdge(2, 3);
	grs.AddEdge(3, 2);
	grs.AddEdge(2, 4);
	grs.AddEdge(4, 2);
	grs.AddEdge(2, 5);
	grs.AddEdge(5, 2);
	grs.AddEdge(3, 4);
	grs.AddEdge(4, 3);
	grs.AddEdge(4, 5);
	grs.AddEdge(5, 4);
	grs.AddEdge(4, 5);
	grs.PrintEdges();
};