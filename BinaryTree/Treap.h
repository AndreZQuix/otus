#ifndef TREAP_HEADER_
#define TREAP_HEADER_

#include <iostream>
#include <functional>

template<typename T>
class Treap {
public:
	class Node {
	public:
		T key;
		int priority;
		Node* left;
		Node* right;

		Node(T val) {
			key = val;
			priority = std::rand();
			left = right = nullptr;
		};
	};

private:
	Node* root;
	size_t size;

	typedef void (*node_action)(T);

	void Iterate(Node* node, node_action action) {
		if (node == nullptr) {
			return;
		}

		Iterate(node->left, action);
		action(node->key);
		Iterate(node->right, action);
	};

	Node* Merge(Node* l, Node* r) {
		if (l == nullptr) {
			return r;
		}

		if (r == nullptr) {
			return l;
		}

		if (l->priority > r->priority) {
			root = l;
			Merge(root->right, l->right, r);
		}
		else {
			root = r;
			Merge(root->left, l, r->left);
		}
	};

	void Split(Node* source_tree, int x_key, Node* left_tree, Node* right_tree) {
		if (source_tree == nullptr) {
			left_tree = right_tree = nullptr;
			return;
		}

		if (x_key >= source_tree->key) {
			left_tree = source_tree;
			Split(source_tree->right, x_key, source_tree->right, right_tree);
		}
		else {
			right_tree = root;
			Split(source_tree->left, x_key, left_tree, source_tree->left);
		}
	};

	Node* Insert(Node* curr_root, Node* new_node) {
		if (curr_root == nullptr) {
			return new_node;
		}

		if (new_node->priority > curr_root->priority) {
			Split(curr_root, new_node->key, new_node->left, new_node->right);
			return new_node;
		}
		else {
			if (new_node->key < curr_root->key) {
				curr_root->left = Insert(curr_root->left, new_node);
			}
			else {
				curr_root->right = Insert(curr_root->right, new_node);
			}
			return curr_root;
		}
	};

public:
	Treap<T>() {
		size = 0;
		root = nullptr;
	};

	size_t Size() {
		return size;
	};

	void Insert(T value) {
		Node* new_node = new Node(value);
		root = Insert(root, new_node);
	};

	void Iterate(node_action action) {
		Iterate(root, action);
	};

	void Remove(const T& key) {
		if (root == nullptr) {
			return;
		}

		if (root->key == key) {
			root = Merge(root, root->left, root->right);
		}
		else {
			if (key < root->key) {
				Remove(root->left, key);
			}
			else {
				Remove(root->right, key);
			}
		}
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
};

#endif // ! TREAP_HEADER_