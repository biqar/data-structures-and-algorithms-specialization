#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

#define MAX 100001
#define INF (1<<20)
#define pii pair< int, int >
#define pb(x) push_back(x)

struct comp {
    bool operator() (const pii &a, const pii &b) {
        return a.second > b.second;
    }
};

priority_queue< pii, vector< pii >, comp > Q;
vector< pii > G[MAX];
int D[MAX];
bool F[MAX];

int distance(int nodes, int starting, int nd) {
  int i, u, v, w, sz;

  for(i=0; i<nodes; i++) D[i] = INF;
  D[starting] = 0;
  Q.push(pii(starting, 0));

  while(!Q.empty()) {
      u = Q.top().first;
      Q.pop();
      if(F[u]) continue;
      sz = G[u].size();
      for(i=0; i<sz; i++) {
          v = G[u][i].first;
          w = G[u][i].second;
          if(!F[v] && D[u]+w < D[v]) {
              D[v] = D[u] + w;
              Q.push(pii(v, D[v]));
          }
      }
      F[u] = 1;
  }

  if(F[nd]) return D[nd];
  return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    G[x-1].pb(pii(y-1, w));
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(n, s, t);
}
