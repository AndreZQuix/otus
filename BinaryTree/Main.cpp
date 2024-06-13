#include <iostream>
#include <functional>

#include "BinaryTree.h"

template<typename T>
void PrintNodeValue(T data) {
	std::cout << data << ' ';
};

int main() {
	BinaryTree<int> tree;
	tree.Insert(51);
	tree.Insert(41);
	tree.Insert(28);
	tree.Insert(2);
	tree.Insert(1);
	tree.Insert(17);
	tree.Insert(42);
	tree.Insert(80);
	tree.Insert(55);
	tree.Insert(55);
	tree.Iterate(&PrintNodeValue);
};