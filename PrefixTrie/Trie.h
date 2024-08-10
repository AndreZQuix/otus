#pragma once

#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <iostream>

class Node {
	std::map<char, std::shared_ptr<Node>> letters;

public:
	bool is_end;
	int value;
	size_t size;
	static const char asterix = '*';
	static const char question_mark = '?';

	Node() : is_end(false), value(0), size(0) {};

	std::shared_ptr<Node> Set(char ch) {
		if (letters.find(ch) == letters.end()) {
			letters[ch] = std::make_shared<Node>();
		}
		return letters[ch];
	};

	std::shared_ptr<Node> Get(char ch) {
		return letters.find(ch) == letters.end() ? nullptr : letters[ch];
	};

	std::map<char, std::shared_ptr<Node>> GetChildren() const {
		return letters;
	};
};

struct NodeComparer {
	bool operator() (std::shared_ptr<Node> const lhs, std::shared_ptr<Node> const rhs) const {
		return lhs->value < rhs->value;
	}
};

class Trie {
	std::shared_ptr<Node> root;

	void Insert(const std::string& key, const int value, bool is_first_time) {
		std::shared_ptr<Node> node = root;
		for (size_t i = 0; i < key.size(); i++) {
			node = node->Set(key[i]);
		}
		node->is_end = true;
		node->value = value;
		node->size = key.size();
	};

	void DestroyRecursive(std::shared_ptr<Node> node) {
		if (node != nullptr) {
			if (node->GetChildren().size() == 0) {
				node.reset();
				node = nullptr;
				return;
			}

			for (auto child : node->GetChildren()) {
				DestroyRecursive(child.second);
			}
		}
	};


	void HandleQuestionMark(const std::string& key, size_t index, bool contains_asterix, std::set<std::shared_ptr<Node>, NodeComparer>& nodes, std::shared_ptr<Node> node) {
		if (node == nullptr) {
			return;
		}

		auto children = node->GetChildren();
		for (auto ch : children) {
			bool same_size_no_asterix = key.size() == ch.second->size && (!contains_asterix);
			if (index < key.size() && (key.size() != ch.second->size)) {
				same_size_no_asterix *= (key[index] == '?' || ch.first == key[index]);
			}

			if (ch.second != nullptr && ch.second->is_end && same_size_no_asterix) {
				nodes.insert(ch.second);
			}
			node = ch.second;
			HandleQuestionMark(key, ++index, contains_asterix, nodes, node);
		}
	};

	void HandleAsterix(const std::string& key, std::set<std::shared_ptr<Node>, NodeComparer>& nodes, std::shared_ptr<Node> node) {
		if (node == nullptr) {
			return;
		}

		auto children = node->GetChildren();
		for (auto ch : children) {
			bool handle_asterix = true;
			if (node != nullptr && key.size() > node->size && node->is_end) {
				handle_asterix *= key[key.size() - 1] == '*';
			}

			if (ch.second != nullptr && ch.second->is_end && handle_asterix) {
				nodes.insert(ch.second);
			}
			node = ch.second;
			HandleAsterix(key, nodes, node);
		}
	};

	void StartsWith(const std::string& key, std::set<std::shared_ptr<Node>, NodeComparer>& nodes) {
		auto key_copy = key;
		std::shared_ptr<Node> node = root;
		bool contains_asterix = key_copy.find_first_of('*') != std::string::npos;
		for (size_t i = 0; i < key_copy.size(); i++) {
			if (key_copy[i] == '?') {
				HandleQuestionMark(key, i, contains_asterix, nodes, node);
				continue;
			}

			if (key_copy[i] == '*') {
				auto asterix_loc = key_copy.find_first_of('*');
				key_copy = key_copy.substr(0, asterix_loc + 1);
				HandleAsterix(key_copy, nodes, node);
			}

			if (node == nullptr) {
				continue;
			}
			node = node->Get(key_copy[i]);
			if (node == nullptr) {
				continue;
			}

			bool handle_asterix = true;
			if (key.size() > node->size && node->is_end) {
				handle_asterix *= key[node->size] == '*';
			}

			if (node->is_end && handle_asterix) {
				nodes.insert(node);
			}
		}

		return;
	};

public:
	Trie() {
		root = std::make_shared<Node>();
	};

	~Trie() {
		DestroyRecursive(root);
	};

	void Insert(const std::string& key, const int value) {
		Insert(key, value, true);
	}

	std::set<std::shared_ptr<Node>, NodeComparer> Search(const std::string& key) {
		std::set<std::shared_ptr<Node>, NodeComparer> nodes;
		StartsWith(key, nodes);
		StartsWith(key + ".*", nodes);
		return nodes;
	};

	void Delete(const std::string& key) {
		auto nodes = Search(key);
		if (nodes.empty()) {
			return;
		}

		for (auto n : nodes) {
			n->is_end = false;
			n->value = 0;
		}
	};
};