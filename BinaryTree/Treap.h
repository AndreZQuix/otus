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

	void Merge(Node* curr_root, Node* l, Node* r) {
		if (l == nullptr) {
			curr_root = r;
			return;
		}

		if (r == nullptr) {
			curr_root = l;
			return;
		}

		if (l->priority > r->priority) {
			Merge(l->right, l->right, r);
			curr_root = l;
		}
		else {
			Merge(r->left, l, r->left);
			curr_root = r;
		}
	};

	void Split(Node* curr_root, int x_key, Node* left_tree, Node* right_tree) {
		if (curr_root == nullptr) {
			left_tree = right_tree = nullptr;
			return;
		}

		if (x_key >= curr_root->key) {
			Split(curr_root->right, x_key, curr_root->right, right_tree);
			left_tree = curr_root;
		}
		else {
			Split(curr_root->left, x_key, left_tree, curr_root->left);
			right_tree = curr_root;
		}
	};

	Node* Insert(Node* curr_root, Node* new_node) {
		if (curr_root == nullptr) {
			size++;
			curr_root = new_node;
		}
		else if (new_node->priority > curr_root->priority) {
			size++;
			Split(curr_root, new_node->key, new_node->left, new_node->right);
			curr_root = new_node;
		}
		else {
			curr_root = Insert(curr_root->key <= new_node->key ? curr_root->right : curr_root->left, new_node);
		}

		return curr_root;
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
			Merge(root, root->left, root->right);
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