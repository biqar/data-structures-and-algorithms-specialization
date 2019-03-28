#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

struct Rotation {
    int pos;
    string suffix;
};

bool comp(Rotation r1, Rotation r2) {
    return r1.suffix < r2.suffix;
}

string BWT(const string& text) {
    int sz = text.size();
    vector<Rotation> rot(sz);
    string result = "";

    for(int i=0; i<sz; i+=1) {
        rot[i].pos = i;
        rot[i].suffix = text.substr(i, sz-i);
    }

    sort(rot.begin(), rot.end(), comp);

    for(int i=0; i<sz; i+=1) {
        //std::cout << rot[i].pos << "\n";
        result += text[(rot[i].pos - 1 + sz) % sz];
    }

    // write your code here

    return result;
}

int main() {
  string text;
  cin >> text;
  cout << BWT(text) << endl;
  return 0;
}
