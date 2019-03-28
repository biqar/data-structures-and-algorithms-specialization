#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }

#define ALL(p) p.begin(),p.end()
#define MP(x, y) make_pair(x, y)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;

/*class MaxMatching {
 public:
  void Solve() {
    vector<vector<bool>> adj_matrix = ReadData();
    vector<int> matching = FindMatching(adj_matrix);
    WriteResponse(matching);
  }

 private:
  vector<vector<bool>> ReadData() {
    int num_left, num_right;
    cin >> num_left >> num_right;
    vector<vector<bool>> adj_matrix(num_left, vector<bool>(num_right));
    for (int i = 0; i < num_left; ++i)
      for (int j = 0; j < num_right; ++j) {
        int bit;
        cin >> bit;
        adj_matrix[i][j] = (bit == 1);
      }
    return adj_matrix;
  }

  void WriteResponse(const vector<int>& matching) {
    for (int i = 0; i < matching.size(); ++i) {
      if (i > 0)
        cout << " ";
      if (matching[i] == -1)
        cout << "-1";
      else
        cout << (matching[i] + 1);
    }
    cout << "\n";
  }

  vector<int> FindMatching(const vector<vector<bool>>& adj_matrix) {
    // Replace this code with an algorithm that finds the maximum
    // matching correctly in all cases.
    int num_left = adj_matrix.size();
    int num_right = adj_matrix[0].size();
    vector<int> matching(num_left, -1);
    vector<bool> busy_right(num_right, false);
    for (int i = 0; i < num_left; ++i)
      for (int j = 0; j < num_right; ++j)
        if (matching[i] == -1 && !busy_right[j] && adj_matrix[i][j]) {
          matching[i] = j;
          busy_right[j] = true;
        }
    return matching;
  }
};*/

const int MAX = 105;


vector < int > G[MAX];
bool visited[MAX];
int Left[MAX], Right[MAX];

bool dfs(int u) {
    if(visited[u]) return false;
    visited[u] = true;
    int len = G[u].size(), i, v;
    for(i=0; i<len; i++) {
        v = G[u][i];
        if(Right[v]==-1) {
            Right[v] = u, Left[u] = v;
            return true;
        }
    }
    for(i=0; i<len; i++) {
        v = G[u][i];
        if(dfs(Right[v])) {
            Right[v] = u, Left[u] = v;
            return true;
        }
    }
    return false;
}

int match(int n) {
    int i, ret = 0;
    bool done;
    SET(Left); SET(Right);
    do {
        done = true; CLR(visited);
        for(i=0; i<n; i++) {
            if(Left[i]==-1 && dfs(i)) {
                done = false;
            }
        }
    } while(!done);
    for(i=0; i<n; i++) ret += (Left[i]!=-1);
    return ret;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  //MaxMatching max_matching;
  //max_matching.Solve();
  int num_left, num_right;
  cin >> num_left >> num_right;
  //vector<vector<bool>> adj_matrix(num_left, vector<bool>(num_right));
  for (int i = 0; i < num_left; ++i) {
    for (int j = 0; j < num_right; ++j) {
      int bit;
      cin >> bit;
      if(bit == 1) G[i].push_back(j);
    }
  }
  match(num_left);
  for (int i = 0; i < num_left; ++i) {
      if(i) cout << " ";
      if(Left[i] != -1) cout << Left[i] + 1;
      else cout << Left[i];
  }
  cout << endl;
  return 0;
}
