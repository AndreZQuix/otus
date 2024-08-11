#include <iostream>
#include <string>

#include <vector>
#include <fstream>
#include <algorithm>

bool IsMatch(std::string url, std::string domain, bool is_domain_mask) {
    if (url[0] == '*') {
		return true;
	}

    size_t size = url.size() <= domain.size() ? url.size() : domain.size();
	size_t asterix_loc = url.find_first_of('*');
	if (asterix_loc != std::string::npos) {
		url = url.substr(0, asterix_loc + 1);
        size -= size - asterix_loc;
	}

    if (url[url.size() - 1] == '*') {
        size--;
    }

	bool is_match = false;
    bool url_ends_with_asterix = url[url.size() - 1] == '*';
	bool handle_longer_match = url.size() == domain.size();
	if (url.size() > domain.size()) {
		handle_longer_match = url[domain.size()] == '.';
	}
	else if (url.size() < domain.size()) {
		handle_longer_match = (domain[url.size()] == '.' && is_domain_mask) || url_ends_with_asterix;
	}

	for (int i = 0; i < size; i++) {
		if ((url[i] == '?' || url[i] == domain[i])) {
			is_match = true;
			continue;
		}
        is_match = false;
		break;
	}
	return is_match * handle_longer_match;
};

using namespace std;
bool isMatch(string s, string p)
{
    // dry run this sample case on paper , if unable to
    // understand what soln does
    // p = "a*bc" s = "abcbc"
    int sIdx = 0, pIdx = 0, lastWildcardIdx = -1,
        sBacktrackIdx = -1, nextToWildcardIdx = -1;
    while (sIdx < s.size()) {
        if (pIdx < p.size()
            && (p[pIdx] == '?' || p[pIdx] == s[sIdx])) {
            // chars match
            ++sIdx;
            ++pIdx;
        }
        else if (pIdx < p.size() && p[pIdx] == '*') {
            // wildcard, so chars match - store index.
            lastWildcardIdx = pIdx;
            nextToWildcardIdx = ++pIdx;
            sBacktrackIdx = sIdx;

            // storing the pidx+1 as from there I want to
            // match the remaining pattern
        }
        else if (lastWildcardIdx == -1) {
            // no match, and no wildcard has been found.
            return false;
        }
        else {
            // backtrack - no match, but a previous wildcard
            // was found.
            pIdx = nextToWildcardIdx;
            sIdx = ++sBacktrackIdx;
            // backtrack string from previousbacktrackidx +
            // 1 index to see if then new pidx and sidx have
            // same chars, if that is the case that means
            // wildcard can absorb the chars in b/w and still
            // further we can run the algo, if at later stage
            // it fails we can backtrack
        }
    }
    for (int i = pIdx; i < p.size(); i++) {
        if (p[i] != '*')
            return false;
    }
    return true;
    // true if every remaining char in p is wildcard
}
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
 //   cout << "Loaded" << endl;

    std::vector<std::string> urls = { "moc.o??eh", "efac", "????", "*", "ef*", "e?fac", "moc.*", "*ac", "moc.olleh", "moc.olleh.tset.????", "moc.s??n", 
        "moc.s??n.m*d", "moc.eruz", "moc.?????*"}; // last bug
    std::vector<std::string> domains = { "moc.olleh", "efac", "moc.olleh.tset.swen", "moc.olleh.tset", "moc.swen.mod", "moc.eruza" };
    for (auto u : urls) {
        for (auto d : domains) {
            if (IsMatch(u, d, true)) {
		        std::cout << "Match " << u << " - " << d << std::endl;
            }
            else {
                std::cout << "NO MATCH " << u << " - " << d << std::endl;
            }
        }
    }

    //std::string u = "*ac";
    //std::string d = "moc.olleh.tset";
    //if (isMatch(u, d)) {
    //    std::cout << "Match " << u << " - " << d << std::endl;
    //}
    //else {
    //    std::cout << "NO MATCH " << u << " - " << d << std::endl;
    //}

	//for (size_t i = 0; i < test_domains.size(); i++) {
	//	std::string url = "moc.rl??*";
	//	if (IsMatch(url, test_domains[i], true)) {
	//		std::cout << "Match " << test_domains[i] << std::endl;
	//	}

 //       isMatch(test_domains[i], url);
 //       isMatch(test_domains[i], url);
	//}
};