#include <iostream>
#include <functional>
#include <chrono>
#include <vector>
#include <random>
#include <algorithm>

#include "BinaryTree.h"
#include "AvlTree.h"
#include "Treap.h"
#include "SplayTree.h"

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

void FillTree(AvlBinaryTree<int>& tree, const std::vector<int>& numbers) {
	for (int i = 0; i < numbers.size(); i++) {
		tree.Insert(numbers[i]);
	}
};

void FillTree(SplayTree<int>& tree, const std::vector<int>& numbers) {
	for (int i = 0; i < numbers.size(); i++) {
		tree.Insert(numbers[i]);
	}
};

void CheckBinaryTrees() {
	const int size = 1000000;

	BinaryTree<int> tree1;
	std::vector<int> randomNumbers = GetNumbersVector(size, true);

	auto start = std::chrono::high_resolution_clock::now();
	FillTree(tree1, randomNumbers);
	auto finish = std::chrono::high_resolution_clock::now();
	auto time = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
	std::cout << "First tree with random numbers fill time: " << time << " ms. Size: " << tree1.Size() << "\n";

	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < size / 10; i++) {
		tree1.Search(randomNumbers[i]);
	}
	finish = std::chrono::high_resolution_clock::now();
	time = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
	std::cout << "First tree with random numbers search time: " << time << " ms.\n";

	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < size / 10; i++) {
		tree1.Remove(randomNumbers[i]);
	}
	finish = std::chrono::high_resolution_clock::now();
	time = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
	std::cout << "First tree with random numbers remove time: " << time << " ms. Size: " << tree1.Size() << "\n";

	BinaryTree<int> tree2;
	std::vector<int> numbers = GetNumbersVector(size, false);

	start = std::chrono::high_resolution_clock::now();
	FillTree(tree2, numbers);
	finish = std::chrono::high_resolution_clock::now();
	time = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
	std::cout << "Second tree with numbers fill time: " << time << " ms. Size: " << tree2.Size() << "\n";

	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < size / 10; i++) {
		tree2.Search(numbers[i]);
	}
	finish = std::chrono::high_resolution_clock::now();
	time = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
	std::cout << "Second tree with numbers search time: " << time << " ms.\n";

	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < size / 10; i++) {
		tree2.Remove(numbers[i]);
	}
	finish = std::chrono::high_resolution_clock::now();
	time = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
	std::cout << "Second tree with numbers remove time: " << time << " ms. Size: " << tree2.Size() << "\n";
};

void CheckAvlBinaryTrees() {
	const int size = 100000;

	AvlBinaryTree<int> tree1;
	std::vector<int> randomNumbers = GetNumbersVector(size, true);

	auto start = std::chrono::high_resolution_clock::now();
	FillTree(tree1, randomNumbers);
	auto finish = std::chrono::high_resolution_clock::now();
	auto time = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
	std::cout << "First avl tree with random numbers fill time: " << time << " ms. Size: " << tree1.Size() << "\n";

	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < size / 10; i++) {
		tree1.Search(randomNumbers[i]);
	}
	finish = std::chrono::high_resolution_clock::now();
	time = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
	std::cout << "First avl tree with random numbers search time: " << time << " ms.\n";

	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < size / 10; i++) {
		tree1.Remove(randomNumbers[i]);
	}
	finish = std::chrono::high_resolution_clock::now();
	time = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
	std::cout << "First avl tree with random numbers remove time: " << time << " ms. Size: " << tree1.Size() << "\n";

	AvlBinaryTree<int> tree2;
	std::vector<int> numbers = GetNumbersVector(size, false);

	start = std::chrono::high_resolution_clock::now();
	FillTree(tree2, numbers);
	finish = std::chrono::high_resolution_clock::now();
	time = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
	std::cout << "Second avl tree with numbers fill time: " << time << " ms. Size: " << tree2.Size() << "\n";

	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < size / 10; i++) {
		tree2.Search(numbers[i]);
	}
	finish = std::chrono::high_resolution_clock::now();
	time = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
	std::cout << "Second avl tree with numbers search time: " << time << " ms.\n";

	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < size / 10; i++) {
		tree2.Remove(numbers[i]);
	}
	finish = std::chrono::high_resolution_clock::now();
	time = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
	std::cout << "Second avl tree with numbers remove time: " << time << " ms. Size: " << tree2.Size() << "\n";
};

void CheckSplayTrees() {
	const int size = 100000;

	SplayTree<int> tree1;
	std::vector<int> randomNumbers = GetNumbersVector(size, false);

	auto start = std::chrono::high_resolution_clock::now();
	FillTree(tree1, randomNumbers);
	auto finish = std::chrono::high_resolution_clock::now();
	auto time = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
	std::cout << "First splay tree with random numbers fill time: " << time << " ms. Size: " << tree1.Size() << "\n";

	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < size / 10; i++) {
		tree1.Search(randomNumbers[i]);
	}
	finish = std::chrono::high_resolution_clock::now();
	time = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
	std::cout << "First splay tree with random numbers search time: " << time << " ms.\n";

	SplayTree<int> tree2;
	std::vector<int> numbers = GetNumbersVector(size, false);

	start = std::chrono::high_resolution_clock::now();
	FillTree(tree2, numbers);
	finish = std::chrono::high_resolution_clock::now();
	time = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
	std::cout << "Second splay tree with numbers fill time: " << time << " ms. Size: " << tree2.Size() << "\n";

	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < size / 10; i++) {
		tree2.Search(numbers[i]);
	}
	finish = std::chrono::high_resolution_clock::now();
	time = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
	std::cout << "Second splay tree with numbers search time: " << time << " ms.\n";
};

int main() {
	CheckSplayTrees();
};