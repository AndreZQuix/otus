#pragma once

#include <iostream>
#include <unordered_map>

class HashTable {
	struct Node {
		std::string key;
		int value;

		Node(std::string key, int value) : key(key), value(value) {};
	};

	Node** table;
	size_t capacity;
	size_t size;
	Node* del_node;

public:
	HashTable(size_t capacity) : capacity(capacity), size(0) {
		table = new Node * [capacity];
		for (size_t i = 0; i < capacity; i++) {
			table[i] = nullptr;
		}
		del_node = new Node("DELETED", -1);
	};

	~HashTable() {
		for (size_t i = 0; i < capacity; i++) {
			if (table[i] != nullptr && table[i] != del_node) {
				delete table[i];
				table[i] = nullptr;
			}
		}

		delete del_node;
	};

	friend std::ostream& operator<< (std::ostream& stream, const HashTable& table) {
		for (size_t i = 0; i < table.capacity; i++) {
			if (table.table[i] != nullptr) {
				stream << table.table[i]->key << " " << table.table[i]->value << '\n';
			}
			else {
				stream << "NULL \n";
			}
		}

		return stream;
	};

private:
	size_t GenerateHash(const std::string& str) const {
		return std::hash<std::string>{}(str) % capacity;
	};

	void ResizeTable() {
		size_t new_capacity = capacity * 2;
		Node** new_table = new Node * [new_capacity];
		for (size_t i = 0; i < capacity; i++) {
			new_table[i] = table[i];
		}

		for (size_t i = capacity; i < new_capacity; i++) {
			new_table[i] = nullptr;
		}

		delete[] table;
		table = new_table;
		capacity = new_capacity;
	};

public:
	
	size_t Size() const {
		return size;
	};

	size_t Capacity() const {
		return capacity;
	};

	Node* Insert(std::string key, int value) {
		if (size >= capacity / 2) {
			ResizeTable();
		}

		size_t target_index = 0;
		size_t hash_index = GenerateHash(key);
		if (table[hash_index] == nullptr || table[hash_index] == del_node) {
			target_index = hash_index;
		}
		else {
			size_t quadro = 1;
			size_t i = (hash_index + quadro * quadro) % capacity;
			while (quadro < capacity) {
				if (table[i] == nullptr || table[i] == del_node) {
					target_index = i;
					break;
				}
				i = (i + quadro * quadro) % capacity;
				quadro++;
			}
		}

		Node* new_node = new Node(key, value);
		table[target_index] = new_node;
		size++;
		return new_node;
	};

	bool Remove(const std::string& key) {
		size_t target_index = 0;
		bool is_found = false;
		size_t hash_index = GenerateHash(key);
		if (table[hash_index] != nullptr && table[hash_index]->key == key) {
			target_index = hash_index;
			is_found = true;
		}
		else {
			size_t quadro = 1;
			size_t i = (hash_index + quadro * quadro) % capacity;
			while (quadro < capacity) {
				if (table[i] != nullptr && table[i]->key == key) {
					target_index = i;
					is_found = true;
					break;
				}
				i = (i + quadro * quadro) % capacity;
				quadro++;
			}
		}

		if (is_found == false) {
			return false;
		}

		delete table[target_index];
		table[target_index] = del_node;
		size--;
		return true;
	};
};