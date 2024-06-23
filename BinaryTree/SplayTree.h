#ifndef SPLAY_HEADER_
#define SPLAY_HEADER_

#include <iostream>
#include <functional>

template<typename T>
class SplayTree {
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

	Node* RightRotate(Node* x) {
		Node* y = x->left;
		x->left = y->right;
		y->right = x;
		return y;
	};

	Node* LeftRotate(Node* x) {
		Node* y = x->right;
		x->right = y->left;
		y->left = x;
		return y;
	};

	Node* Splay(Node* root_tree, T key) {
		if (root_tree == nullptr || root_tree->key == key) {
			return root_tree;
		}

		if (root_tree->key > key) {
			if (root_tree->left == nullptr) {
				return root_tree;
			}

			if (root_tree->left->key > key) {
				root_tree->left->left = Splay(root_tree->left->left, key);
				root_tree = RightRotate(root_tree);
			}
			else if (root_tree->left->key < key) {
				root_tree->left->right = Splay(root_tree->left->right, key);
				if (root_tree->left->right != nullptr) {
					root_tree->left = LeftRotate(root_tree->left);
				}
			}
			return (root_tree->left == nullptr) ? root_tree : RightRotate(root_tree);
		}
		else {
			if (root_tree->right == nullptr) {
				return root_tree;
			}

			if (root_tree->right->key > key) {
				root_tree->right->left = Splay(root_tree->right->left, key);
				if (root_tree->right->left != nullptr) {
					root_tree->right = RightRotate(root_tree->right);
				}
			}
			else if (root_tree->right->key < key) {
				root_tree->right->right = Splay(root_tree->right->right, key);
				root_tree = LeftRotate(root);
			}
			return (root_tree->right == nullptr) ? root_tree : LeftRotate(root_tree);
		}
	};

	Node* Insert(Node* root_tree, T key) {
		if (root_tree == nullptr) {
			size++;
			return new Node(key);
		}

		root_tree = Splay(root_tree, key);
		if (root_tree->key == key) {
			return root_tree;
		}

		Node* node = new Node(key);
		size++;
		if (root_tree->key > key) {
			node->right = root_tree;
			node->left = root_tree->left;
			root_tree->left = nullptr;
		}
		else {
			node->left = root_tree;
			node->right = root_tree->right;
			root_tree->right = nullptr;
		}
		return node;
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
		Node* temp = node;
		while (temp->left != nullptr) {
			temp = temp->left;
		}
		return temp;
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

		return node;
	};

public:
	SplayTree() {
		root = nullptr;
		size = 0;
	};

	void Insert(T value) {
		root = Insert(root, value);
	};

	size_t Size() const {
		return size;
	};

	void Iterate(node_action action) {
		Iterate(root, action);
	};

	bool SearchSplay(const T& key) {
		return Splay(root, key) != nullptr;
	};

	bool Search(const T& key) const {
		Node* temp = root;
		while (temp != nullptr) {
			if (temp->key == key) {
				return true;
			}
			else if (temp->key > key) {
				temp = temp->left;
			}
			else {
				temp = temp->right;
			}
		}
		return false;
	};

	void Remove(const T& key) {
		root = Remove(root, key);
	};
};


#endif // ! SPLAY_HEADER_