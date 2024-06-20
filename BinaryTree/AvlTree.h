#ifndef ABT_HEADER_
#define ABT_HEADER_

#include <iostream>
#include <functional>

template<typename T>
class AvlBinaryTree {
public:
	class Node {
	public:
		T key;
		Node* left;
		Node* right;
		int height;

		Node(T val) {
			key = val;
			left = right = nullptr;
			height = 0;
		};
	};

protected:
	Node* root;
	size_t size;

	int Height(Node* node) {
		if (node == nullptr) {
			return -1;
		}

		return node->height;
	};

	void UpdateHeight(Node* node) {
		if (node == nullptr) {
			return;
		}

		node->height = 1 + std::max(Height(node->right), Height(node->left));
	};

	int GetBalance(Node* node) {
		if (node == nullptr) {
			return 0;
		}

		return (Height(node->right) - Height(node->left));
	};

	Node* RotateLeft(Node* Y) {
		Node* X = Y->right;
		Node* Z = X->left;
		X->left = Y;
		Y->right = Z;
		UpdateHeight(Y);
		UpdateHeight(X);
		return X;
	};

	Node* RotateRight(Node* Y) {
		Node* X = Y->left;
		Node* Z = X->right;
		X->right = Y;
		Y->left = Z;
		UpdateHeight(Y);
		UpdateHeight(X);
		return X;
	};

	Node* Rebalance(Node* node) {
		UpdateHeight(node);
		int balance = GetBalance(node);
		if (std::abs(balance) >= 2) {
			if (balance > 1) {
				if (Height(node->right->right) > Height(node->right->left)) {
					node = RotateLeft(node);
				}
				else {
					node->right = RotateRight(node->right);
					node = RotateLeft(node);
				}
			}
			else {
				if (Height(node->left->left) > Height(node->left->right)) {
					node = RotateRight(node);
				}
				else {
					node = RotateLeft(node->left);
					node = RotateRight(node);
				}
			}
		}
		return node;
	};

	Node* Insert(Node* node, T key) {
		if (node == nullptr) {
			size++;
			return Rebalance(new Node(key));
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

		return Rebalance(node);
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

	Node* MostLeftChild(Node* node) {
		if (node->left == nullptr) {
			return node;
		}

		return MostLeftChild(node->left);
	};

	Node* Remove(Node* node, const T& key) {
		if (node == nullptr) {
			return nullptr;
		}

		if (key < node->key) {
			node->left = Remove(node->left, key);
		}
		else if (key > node->key) {
			node->right = Remove(node->right, key);
		}
		else {
			if (node->left == nullptr) {
				Node* temp = node->right;
				size--;
				delete node;
				node = temp;
			}
			else if (node->right == nullptr) {
				Node* temp = node->left;
				size--;
				delete node;
				node = temp;
			}
			else {
				Node* child = MostLeftChild(node->right);
				node->key = child->key;
				node->right = Remove(node->right, child->key);
			}
		}

		return Rebalance(node);
	};

public:
	AvlBinaryTree<T>() {
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

	void Remove(const T& key) {
		root = Remove(root, key);
	};

	void PrintHeights(Node* node) {
		if (node == nullptr) {
			return;
		}

		PrintHeights(node->left);
		std::cout << "\nKey: " << node->key << " Height : " << node->height;
		PrintHeights(node->right);
	};

	void PrintHeights() {
		PrintHeights(root);
	};
};

#endif // ! ABT_HEADER_