#include "Trie.h"
#include <vector>
#include <iostream>
#include <regex>
#include <fstream>
#include <algorithm>
#include <cctype>

 //hello.key.com -> key.com, bye.hello.key.com, hello.key.com
 //if asterix -> trim until last asterix: *.hello.*ey.com -> ey.com
 //question mark -> ignore

 //прогонять алгоритм несколько раз для макс.матчинга
 //ТОЛЬКО доменные маски матчатся на более короткие тестовые домены
 //url hell.ru dom news.hell.ru - no
 //url news.hell.ru dom hell.ru - yes

using namespace std;

std::string gen_random(const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLM*?NOPQRSTUVWXYZ"
        "abcdefghijkl*?mnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return tmp_s;
}

std::vector<string> GenerateDomains(size_t size) {
    vector<string> ret;
    for (size_t i = 0; i < size; i++) {
        ret.push_back("moc." + gen_random(12));
    }
    return ret;
};

using namespace std;
int main() {
	//std::vector<std::string> test_domains;
	//ifstream ifs("C:\\Users\\User\\domains.txt");
	//std::string str;
	//while (ifs >> str) {
	//	if (std::all_of(str.begin(), str.end(), ::isdigit)) {
	//		continue;
	//	}
	//	test_domains.push_back(str);
	//}

	//auto urls = "moc.dlrow.oll*h";
 //   cout << "Loaded" << endl;

	//Trie trie;
	//for (size_t i = 0; i < test_domains.size(); i++ ) {
	//	trie.Insert(test_domains[i], i, false);
	//}
	//cout << "Inserted" << endl;
	//auto nodes = trie.Search(urls);
	//if (!nodes.empty()) {
	//	for (auto n : nodes) {
	//		cout << n->value << endl;
	//	}
	//}


	//for (size_t i = 0; i < test_domains.size(); i++) {
	//	auto nodes = trie.Search(urls[i]);
	//	if (!nodes.empty()) {
	//		std::cout << "Match" << std::endl;
	//	}
	//	if (nodes.empty()) {
	//		std::cout << urls[i] << " --- \n";
	//	}

	//	for (auto node : nodes) {
	//		std::cout << urls[i] << " - " << node->value << '\n';
	//	}
	//}


	//Trie trie;
	//std::map<std::string, int> urls = { {"moc.y??", 11}, {"moc.yek.olleh", 13},
	//	{"ur.olleh", 123}, {"ten.swen", 55}, {"ur.lleh.sw?n", 34}};

	//for (auto u : urls) {
	//	trie.Insert(u.first, u.second, false);
	//}

	//urls["ur.lleh.swen.tset"] = 35;
	//trie.Insert("ur.lleh.swen.tset", 35, true);
	//trie.Insert("ur.lleh.swen.tset", 35, false);
	//trie.Insert("ur.lleh.swen.tset.hello.???", 36, false);
	//urls["ur.lleh"] = 21;
	//trie.Insert("ur.lleh", 21, true);
	//urls["ur.lleh.swen"] = 33;
	//trie.Insert("ur.lleh.swen", 33, true);
	//urls["moc.yek"] = 12;
	//trie.Insert("moc.yek", 12, false);
	//urls["ur.ll*h.s?en"] = 77;
	//trie.Insert("ur.ll*h.s?en", 77, true);
	//urls["ur.ll*"] = 88;
	//trie.Insert("ur.ll*", 88, true);

	//std::vector<std::string> test_domains = { "moc.yek", "moc.sek", "moc.yss", "ur.olleh", "ten.swen", "ur.ll", "ur.lleh.swen", "ur.lleh"};
	//for (size_t i = 0; i < test_domains.size(); i++) {
	//	auto nodes = trie.Search(test_domains[i]);
	//	if (nodes.empty()) {
	//		std::cout << test_domains[i] << " --- \n";
	//	}

	//	for (auto node : nodes) {
	//		std::cout << test_domains[i] << " - " << node->value << '\n';
	//	}
	//}
	
	Trie trie;
	std::map<std::string, int> domains = { {"moc.yss", 11}, {"moc.yek.olleh", 13},
		{"ur.olleh", 123}, {"ten.swen", 55}, {"ur.ll", 34}, {"cafe", 42} };

	for (auto u : domains) {
		trie.Insert(u.first, u.second);
	}

	trie.Insert("ur.lleh.swen", 35);
	trie.Insert("ur.lleh.swen.tset", 37);
	trie.Insert("ur.lleh", 36);
	trie.Insert("moc.yek", 12);

	std::vector<std::string> urls = { "ur.lleh.sw?n", "ten.swen", "ur.olleh", "moc.yek.olleh", "moc.y??", "ur.ll*", "ur.ll*h.s?en", "moc.yek", "ur.lleh.swen", "ur.lleh", 
		"ur.lleh.swen.tset.hello.???", "ur.lleh.swen.tset", "ca*fe" };
	for (size_t i = 0; i < urls.size(); i++) {
		auto nodes = trie.Search(urls[i], true);
		if (nodes.empty()) {
			std::cout << urls[i] << " --- \n";
		}

		for (auto node : nodes) {
			std::cout << urls[i] << " - " << node->value << '\n';
		}
	}

	//Trie trie;
	//std::map<std::string, int> urls = { {"key.com", 11},
	//	{"hello.ru", 123}, {"news.net", 55}, {"hell.ru", 21}, {"news.hell.ru", 33} };

	//for (auto u : urls) {
	//	trie.Insert(u.first, u.second, false);
	//}

	//urls["test.news.hell.ru"] = 34;
	//trie.Insert("test.news.hell.ru", 34, true);
	//trie.Insert("test.news.hell.ru", 34, true);

	//std::vector<std::string> test_domains = { "key.com", "hello.ru", "news.net", "ll.ru", "news.hell.ru" };
	//for (size_t i = 0; i < test_domains.size(); i++) {
	//	auto nodes = trie.StartsWith(test_domains[i]);
	//	if (nodes.empty()) {
	//		std::cout << test_domains[i] << " --- \n";
	//	}

	//	for (auto node : nodes) {
	//		std::cout << test_domains[i] << " - " << node->value << '\n';
	//	}
	//}
};

//using namespace std;
//
//int main()
//{
//    regex star_replace("\\*");
//    regex questionmark_replace("\\?");
//    auto domains = GenerateDomains(700000);
//	domains.push_back("*.hello.w??ld.com");
//	auto url = "*.hello.w??ld.com";
//    cout << "Loaded" << endl;
//
//    for (size_t i = 0; i < domains.size(); i++) {
//		string data = url;
//		string pattern = domains[i];
//		auto wildcard_pattern = regex_replace(
//			regex_replace(pattern, star_replace, ".*"),
//			questionmark_replace, ".");
//
//		//cout << "Wildcard: " << pattern << " Regex: " << wildcard_pattern << endl;
//
//		regex wildcard_regex(wildcard_pattern);
//
//		if (regex_match(data, wildcard_regex))
//			cout << "Match!" << endl;
//    }
//    
//
//    cout << "End" << endl;
//    return 0;
//}
