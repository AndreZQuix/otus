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

	Node* AddToTable(std::string key, int value) {
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
		return new_node;
	};

	void ResizeTable() {
		size_t old_capacity = capacity;
		capacity *= 2;
		Node** old_table = new Node*[old_capacity];
		for (size_t i = 0; i < old_capacity; i++) {
			old_table[i] = table[i];
		}
		table = new Node*[capacity];
		for (size_t i = 0; i < capacity; i++) {
			table[i] = nullptr;
		}
		for (size_t i = 0; i < old_capacity; i++) {
			if (old_table[i] != nullptr) {
				AddToTable(old_table[i]->key, old_table[i]->value);
			}
		}
		
		delete[] old_table;
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

		size++;
		return AddToTable(key, value);
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