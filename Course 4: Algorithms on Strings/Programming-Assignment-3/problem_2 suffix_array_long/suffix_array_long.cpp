#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::string;
using std::vector;
using std::sort;

const int MAXN = 1 << 18;
const int MAXL = 18;

int n, stp, mv, suffix[MAXN], tmp[MAXN];
int sum[MAXN], cnt[MAXN], rank[MAXL][MAXN];
string text;

inline bool equal(const int &u, const int &v){
    if(!stp) return text[u] == text[v];
    if(rank[stp-1][u] != rank[stp-1][v]) return false;
    int a = u + mv < n ? rank[stp-1][u+mv] : -1;
    int b = v + mv < n ? rank[stp-1][v+mv] : -1;
    return a == b;
}

void update(){
    int i, rnk;
    for(i = 0; i < n; i++) sum[i] = 0;
    for(i = rnk = 0; i < n; i++) {
        suffix[i] = tmp[i];
        if(i && !equal(suffix[i], suffix[i-1])) {
            rank[stp][suffix[i]] = ++rnk;
            sum[rnk+1] = sum[rnk];
        }
        else rank[stp][suffix[i]] = rnk;
        sum[rnk+1]++;
    }
}

void Sort() {
    int i;
    for(i = 0; i < n; i++) cnt[i] = 0;
    memset(tmp, -1, sizeof tmp);
    for(i = 0; i < mv; i++){
        int idx = rank[stp - 1][n - i - 1];
        int x = sum[idx];
        tmp[x + cnt[idx]] = n - i - 1;
        cnt[idx]++;
    }
    for(i = 0; i < n; i++){
        int idx = suffix[i] - mv;
        if(idx < 0)continue;
        idx = rank[stp-1][idx];
        int x = sum[idx];
        tmp[x + cnt[idx]] = suffix[i] - mv;
        cnt[idx]++;
    }
    update();
    return;
}

inline bool cmp(const int &a, const int &b){
    if(text[a] != text[b]) return text[a] < text[b];
    return false;
}

void SortSuffix() {
    int i;
    for(i = 0; i < n; i++) tmp[i] = i;
    sort(tmp, tmp + n, cmp);
    stp = 0;
    update();
    ++stp;
    for(mv = 1; mv < n; mv <<= 1) {
        Sort(); stp++;
    }
    stp--;
    for(i = 0; i <= stp; i++) rank[i][n] = -1;
}

// Build suffix array of the string text and
// return a vector result of the same length as the text
// such that the value result[i] is the index (0-based)
// in text where the i-th lexicographically smallest
// suffix of text starts.
vector<int> BuildSuffixArray(const string& text) {
  vector<int> result;
  // Implement this function yourself
  return result;
}

int main() {
  cin >> text;
  n = text.size();
  //vector<int> suffix_array = BuildSuffixArray(text);
  SortSuffix();
//   for (int i = 0; i < suffix_array.size(); ++i) {
//     cout << suffix_array[i] << ' ';
//   }
    for (int i = 0; i < n; ++i) {
        cout << suffix[i] << ' ';
    }
  cout << endl;
  return 0;
}
