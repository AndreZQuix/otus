#pragma once

//#include <string>
//#include <map>
//#include <algorithm>
//#include <set>
//#include <iostream>
//
//class Node {
//	std::map<char, Node*> letters;
//
//public:
//	bool is_end;
//	bool is_domain_mask;
//	int value;
//	size_t size;
//	static const char question_mark = '?';
//	static const char asterix = '*';
//
//	Node() : is_end(false), value(0), is_domain_mask(false), size(0) {};
//
//	Node* Set(char ch) {
//		if (letters.find(ch) == letters.end()) {
//			letters[ch] = new Node();
//		}
//		return letters[ch];
//	};
//
//	Node* Get(char ch, bool& is_question_mark) {
//		//if (letters.find(question_mark) == letters.end()) {
//		//	
//		//	return letters.find(ch) == letters.end() ? nullptr : letters[ch];
//		//}
//		//is_question_mark = true;
//		//return letters[question_mark];
//		return letters.find(ch) == letters.end() ? nullptr : letters[ch];
//	};
//
//	std::map<char, Node*> GetChildren() const {
//		return letters;
//	};
//};
//
//class Trie {
//	Node* root;
//
//public:
//	Trie() {
//		root = new Node();
//	};
//
//	void Insert(const std::string& key, const int value, bool is_domain_mask) {
//		Node* node = root;
//		size_t asterix_loc = key.find_first_of(Node::asterix);
//		size_t question_mark_loc = key.find_first_of(Node::question_mark);
//		std::string new_key = key;
//		if (asterix_loc != std::string::npos && asterix_loc < question_mark_loc) {
//			new_key = key.substr(0, asterix_loc);
//		}
//
//		for(char ch : new_key) {
//			node = node->Set(ch);
//		}
//		node->is_end = true;
//		node->is_domain_mask = is_domain_mask;
//		node->value = value;
//		node->size = new_key.size();
//	};
//
//	void IterateAsterix(std::set<Node*>& ret, Node* node) {
//		if (node == nullptr) {
//			return;
//		}
//
//		for (auto child : node->GetChildren()) {
//			if (child.second != nullptr && child.second->is_end) {
//				ret.insert(child.second);
//			}
//			node = child.second;
//			IterateAsterix(ret, node);
//		}
//	};
//
//	void IterateQuestionMark(std::set<Node*>& ret, Node* node) {
//		if (node == nullptr) {
//			return;
//		}
//
//		for (auto child : node->GetChildren()) {
//			if (child.second != nullptr && child.second->is_end) {
//				ret.insert(child.second);
//			}
//			node = child.second;
//			IterateQuestionMark(ret, node);
//		}
//	};
//
//	 void StartsWith(const std::string& key, std::set<Node*>& nodes) {
//		Node* node = root;
//		for (char ch : key) {
//			if (ch == '*') {
//				IterateAsterix(nodes, node);
//			}
//
//			bool is_question_mark = false;
//			node = node->Get(ch, is_question_mark);
//			if (is_question_mark) {
//				IterateQuestionMark(nodes, node);
//			}
//
//			if (node == nullptr) {
//				return;
//			}
//			bool shorter_than_test_dom_domain_mask = node->is_domain_mask && node->size < key.size(); // handle domain masks
//			if (node->is_end && (node->size >= key.size() || shorter_than_test_dom_domain_mask)) {
//				nodes.insert(node);
//			}
//		}
//
//		return;
//	};
//
//	std::set<Node*> Search(const std::string& key) {
//		std::set<Node*> nodes;
//		StartsWith(key, nodes);
//		StartsWith(key + ".*", nodes);
//		return nodes;
//	};
//};

#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <iostream>

class Node {
	std::map<char, Node*> letters;

public:
	bool is_end;
	int value;
	size_t size;
	static const char asterix = '*';
	static const char question_mark = '?';

	Node() : is_end(false), value(0), size(0) {};

	Node* Set(char ch) {
		if (letters.find(ch) == letters.end()) {
			letters[ch] = new Node();
		}
		return letters[ch];
	};

	Node* Get(char ch, bool& is_question_mark) {
		//if (letters.find(question_mark) == letters.end()) {
		//	
		//	return letters.find(ch) == letters.end() ? nullptr : letters[ch];
		//}
		//is_question_mark = true;
		//return letters[question_mark];
		//return letters.find(ch) == letters.end() ? letters.find(asterix) == letters.end() ? letters[asterix] : nullptr : letters[ch];
		return letters.find(ch) == letters.end() ? nullptr : letters[ch];
	};

	std::map<char, Node*> GetChildren() const {
		return letters;
	};
};

struct NodeComparer {
	bool operator() (Node* const lhs, Node* const rhs) const
	{
		return lhs->value < rhs->value;
	}
};

class Trie {
	Node* root;

	void Insert(const std::string& key, const int value, bool is_first_time) {
		Node* node = root;
		for (size_t i = 0; i < key.size(); i++) {
			node = node->Set(key[i]);
		}
		node->is_end = true;
		node->value = value;
		node->size = key.size();

		if (is_first_time) {
			Insert(key + ".*", value, false);
		}
	};

public:
	Trie() {
		root = new Node();
	};

	void Insert(const std::string& key, const int value) {
		Insert(key, value, true);
	}

	void IterateAsterix(std::set<Node*, NodeComparer>& ret, Node* node) {
		if (node == nullptr) {
			return;
		}

		for (auto child : node->GetChildren()) {
			if (child.second != nullptr && child.second->is_end) {
				ret.insert(child.second);
			}
			node = child.second;
			IterateAsterix(ret, node);
		}
	};

	void IterateQuestionMark(std::set<Node*, NodeComparer>& ret, Node* node) {
		if (node == nullptr) {
			return;
		}

		for (auto child : node->GetChildren()) {
			if (child.second != nullptr && child.second->is_end) {
				ret.insert(child.second);
			}
			node = child.second;
			IterateQuestionMark(ret, node);
		}
	};

	void StartsWith(const std::string& key, std::set<Node*, NodeComparer>& nodes, bool is_domain_mask) {
		Node* node = root;
		for (size_t i = 0; i < key.size(); i++) {
			if (key[i] == '*') {
				IterateAsterix(nodes, node);
			}

			bool is_question_mark = false;
			node = node->Get(key[i], is_question_mark);
			if (is_question_mark) {
				IterateQuestionMark(nodes, node);
			}

			if (node == nullptr) {
				return;
			}
			bool shorter_than_test_dom_domain_mask = is_domain_mask && node->size < key.size(); // handle domain masks
			bool has_asterix = key[i+1] == '*';
			bool deal_with_asterix = ((has_asterix && node->size < key.size()) || (node->size > key.size() && !has_asterix));
			if (node->is_end && (node->size >= key.size() || shorter_than_test_dom_domain_mask) && deal_with_asterix) {
				nodes.insert(node);
			}
		}

		return;
	};

	std::set<Node*, NodeComparer> Search(const std::string& key, bool is_domain_mask) {
		std::set<Node*, NodeComparer> nodes;
		StartsWith(key, nodes, is_domain_mask);
		StartsWith(key + ".*", nodes, is_domain_mask);
		return nodes;
	};
};