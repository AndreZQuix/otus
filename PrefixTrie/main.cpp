#include "Trie.h"
#include <vector>
#include <iostream>
#include <regex>
#include <fstream>
#include <algorithm>
#include <cctype>

 int main() {
	Trie trie;
	std::map<std::string, int> domains = { {"moc.yss", 11}, {"moc.yek.olleh", 13},
		{"ur.olleh", 123}, {"ten.swen", 55}, {"ur.ll", 34}, {"efac", 42} };

	for (auto u : domains) {
		trie.Insert(u.first, u.second);
	}

	trie.Insert("ur.lleh.swen", 35);
	trie.Insert("ur.lleh.swen.tset", 37);
	trie.Insert("ur.lleh", 36);
	trie.Insert("moc.yek", 12);

	std::vector<std::string> urls = { "ur.lleh.sw?n", "ten.swen", "ur.olleh", "moc.yek.olleh", "moc.y??", "ur.ll*", "ur.ll*h.s?en", "moc.yek", "ur.lleh.swen", "ur.lleh",
		"ur.lleh.swen.tset.hello.???", "ur.lleh.swen.tset", "ef*ac", "????", "?????", "ef?.???"};
	for (size_t i = 0; i < urls.size(); i++) {
		auto nodes = trie.Search(urls[i]);
		if (nodes.empty()) {
			std::cout << urls[i] << " --- \n";
		}

		for (auto node : nodes) {
			std::cout << urls[i] << " - " << node->value << '\n';
		}
	}
};