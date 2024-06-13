#ifndef BT_HEADER_
#define BT_HEADER_

#include <iostream>
#include <functional>

template<typename T>
class BinaryTree {
public:
	class Node {
	public:
		T key;
		Node* left;
		Node* right;

		Node(T val) {
			key = val;
			left = right = nullptr;
		};
	};

private:
	Node* root;
	size_t size;

	Node* Insert(Node* node, T key) {
		if (node == nullptr) {
			size++;
			return new Node(key);
		}

		if (node->key == key) {
			return node;
		}

		if (node->key > key) {
			node->left = Insert(node->left, key);
		}
		else {
			node->right = Insert(node->right, key);
		}

		return node;
	};

	bool Search(Node* node, const T& key) const {
		if (node == nullptr) {
			return false;
		}

		if (node->key == key) {
			return true;
		}

		if (node->key > key) {
			return Search(node->left, key);
		}
		else {
			return Search(node->right, key);
		}
	};

	typedef void (*node_action)(T);

	void Iterate(Node* node, node_action action) {
		if (node == nullptr) {
			return;
		}

		Iterate(node->left, action);
		action(node->key);
		Iterate(node->right, action);
	};

public:
	BinaryTree<T>() {
		size = 0;
		root = nullptr;
	};

	size_t Size() {
		return size;
	};

	void Insert(T key) {
		root = Insert(root, key);
	};

	bool Search(const T& key) const {
		return Search(root, key);
	};

	void Iterate(node_action action) {
		Iterate(root, action);
	};
};

#endif // ! BT_HEADER_