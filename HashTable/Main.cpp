#include "HashTable.h"
#include <iostream>

int main() {
	HashTable table(5);
	table.Insert("hello", 15);
	table.Insert("news", 20);
	table.Insert("hello", 10);
	table.Insert("hello", 11);
	table.Insert("test", 11);
	table.Insert("another", 11);
	std::cout << table;
	std::cout << "\nSize is " << table.Size() << ". Capacity is " << table.Capacity();

	std::cout << "\nRemoving\n";
	table.Remove("hello");
	table.Remove("hello");
	table.Remove("hello");
	table.Remove("news");
	table.Insert("hello", 21);
	std::cout << table;
	std::cout << "\nSize is " << table.Size() << ". Capacity is " << table.Capacity();
};