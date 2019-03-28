#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::string;
using std::vector;

struct Rotation {
    int pos;
    string suffix;
};

bool comp(Rotation r1, Rotation r2) {
    return r1.suffix < r2.suffix;
}

// Build suffix array of the string text and
// return a vector result of the same length as the text
// such that the value result[i] is the index (0-based)
// in text where the i-th lexicographically smallest
// suffix of text starts.
vector<int> BuildSuffixArray(const string& text) {
    vector<int> result;
    // Implement this function yourself
    int sz = text.size();
    vector<Rotation> rot(sz);

    for(int i=0; i<sz; i+=1) {
        rot[i].pos = i;
        rot[i].suffix = text.substr(i, sz-i);
    }

    sort(rot.begin(), rot.end(), comp);

    for(int i=0; i<sz; i+=1) {
        //std::cout << rot[i].pos << "\n";
        result.push_back(rot[i].pos);
    }
    return result;
}

int main() {
  string text;
  cin >> text;
  vector<int> suffix_array = BuildSuffixArray(text);
  for (int i = 0; i < suffix_array.size(); ++i) {
    cout << suffix_array[i] << ' ';
  }
  cout << endl;
  return 0;
}
