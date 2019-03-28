#include <string>
#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::vector;
using std::string;

typedef map<char, int> edges;
typedef vector<edges> trie;

trie build_trie(vector<string> & patterns) {
  trie t(10005);
  // write your code here
  int node = 1;
  int sz = patterns.size();
  for(int i=0; i<sz; i+=1) {
    int psz = patterns[i].size();
    int curr = 0;
    for(int j=0; j<psz; j+=1) {
        std::map<char, int>::iterator it = t[curr].find(patterns[i][j]);
        if(it == t[curr].end()) {
            t[curr][patterns[i][j]] = node;
            curr = node;
            node += 1;
        } else {
            curr = t[curr][patterns[i][j]];
        }
    }
  }
  return t;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<string> patterns;
  for (size_t i = 0; i < n; i++) {
    string s;
    std::cin >> s;
    patterns.push_back(s);
  }

  trie t = build_trie(patterns);
  for (size_t i = 0; i < t.size(); ++i) {
    for (const auto & j : t[i]) {
      std::cout << i << "->" << j.second << ":" << j.first << "\n";
    }
  }

  return 0;
}
