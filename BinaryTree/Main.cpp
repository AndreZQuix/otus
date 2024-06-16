#include <iostream>
#include <functional>
#include <chrono>
#include <vector>
#include <random>
#include <algorithm>

#include "BinaryTree.h"

template<typename T>
void PrintNodeValue(T data) {
	std::cout << data << ' ';
};

std::vector<int> GetNumbersVector(int size, bool random) {
	std::vector<int> numbers;
	for (int i = 0; i < size; i++) {
		numbers.push_back(i);
	}

	if (random) {
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(seed));
	}

	return numbers;
};

void FillTree(BinaryTree<int>& tree, const std::vector<int>& numbers) {
	for (int i = 0; i < numbers.size(); i++) {
		tree.Insert(numbers[i]);
	}
};

int main() {
	//const int size = 100000;

	//BinaryTree<int> tree1;
	//std::vector<int> randomNumbers = GetNumbersVector(size, true);

	//auto start = std::chrono::high_resolution_clock::now();
	//FillTree(tree1, randomNumbers);
	//auto finish = std::chrono::high_resolution_clock::now();
	//auto time = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
	//std::cout << "First tree with random numbers fill time: " << time << " ms. Size: " << tree1.Size() << "\n";

	//start = std::chrono::high_resolution_clock::now();
	//for (int i = 0; i < size / 10; i++) {
	//	tree1.Search(randomNumbers[i]);
	//}
	//finish = std::chrono::high_resolution_clock::now();
	//time = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
	//std::cout << "First tree with random numbers search time: " << time << " ms.\n";

	//start = std::chrono::high_resolution_clock::now();
	//for (int i = 0; i < size / 10; i++) {
	//	tree1.Remove(randomNumbers[i]);
	//}
	//finish = std::chrono::high_resolution_clock::now();
	//time = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
	//std::cout << "First tree with random numbers remove time: " << time << " ms. Size: " << tree1.Size() << "\n";

	//BinaryTree<int> tree2;
	//std::vector<int> numbers = GetNumbersVector(size, false);

	//start = std::chrono::high_resolution_clock::now();
	//FillTree(tree2, numbers);
	//finish = std::chrono::high_resolution_clock::now();
	//time = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
	//std::cout << "Second tree with numbers fill time: " << time << " ms. Size: " << tree2.Size() << "\n";

	//start = std::chrono::high_resolution_clock::now();
	//for (int i = 0; i < size / 10; i++) {
	//	tree2.Search(numbers[i]);
	//}
	//finish = std::chrono::high_resolution_clock::now();
	//time = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
	//std::cout << "Second tree with numbers search time: " << time << " ms.\n";

	//start = std::chrono::high_resolution_clock::now();
	//for (int i = 0; i < size / 10; i++) {
	//	tree2.Remove(numbers[i]);
	//}
	//finish = std::chrono::high_resolution_clock::now();
	//time = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
	//std::cout << "Second tree with numbers remove time: " << time << " ms. Size: " << tree2.Size() << "\n";

	BinaryTree<int> tree;
	tree.Insert(51);
	tree.Insert(41);
	tree.Insert(28);
	tree.Insert(2);
	tree.Insert(1);
	tree.Insert(17);
	tree.Insert(42);
	tree.Insert(80);
	tree.Insert(84);
	tree.Insert(89);
	tree.Insert(55);
	tree.Insert(55);
	tree.Iterate(&PrintNodeValue);
	std::cout << std::endl;
	std::cout << tree.Search(51);
	std::cout << tree.Search(1);
	std::cout << tree.Search(28);
	std::cout << tree.Search(89);
	std::cout << tree.Search(100);
	std::cout << std::endl;
	tree.Remove(51);
	tree.Remove(1);
	tree.Remove(28);
	tree.Remove(89);
	tree.Remove(42);
	tree.Remove(100);
	tree.Iterate(&PrintNodeValue);
	std::cout << tree.Size();
};