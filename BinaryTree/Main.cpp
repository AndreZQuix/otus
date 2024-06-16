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
	const int size = 10000;
	BinaryTree<int> tree1;
	std::vector<int> randomNumbers = GetNumbersVector(size, true);
	FillTree(tree1, randomNumbers);
	std::cout << "First tree size: " << tree1.Size() << "\n";

	for (int i = 0; i < size / 10; i++) {
		tree1.Search(randomNumbers[i]);
	}

	for (int i = 0; i < size / 10; i++) {
		tree1.Remove(randomNumbers[i]);
	}
	std::cout << "First tree size after removing: " << tree1.Size() << "\n";

	BinaryTree<int> tree2;
	std::vector<int> numbers = GetNumbersVector(size, false);
	FillTree(tree2, numbers);
	std::cout << "\nSecond tree size: " << tree2.Size() << "\n";

	for (int i = 0; i < size / 10; i++) {
		tree2.Search(numbers[i]);
	}

	for (int i = 0; i < size / 10; i++) {
		tree2.Remove(numbers[i]);
	}
	std::cout << "Second tree size after removing: " << tree2.Size() << "\n";
	
};