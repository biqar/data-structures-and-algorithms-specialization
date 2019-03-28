#include <iostream>
#include <vector>

using std::vector;
using std::pair;

std::vector<int> vis(1005);
std::vector<int> visCurr(1005);
vector<vector<int> > adj(1005, vector<int>());

bool acyclicRec(int curr) {
    if(vis[curr] == 0) {
        vis[curr] = visCurr[curr] = 1;
        int sz = adj[curr].size();
        for(int i=0; i<sz; i+=1) {
            int next = adj[curr][i];
            if(vis[next] == 0 && acyclicRec(next)) return true;
            else if (visCurr[next]) return true;
        }
    }
    visCurr[curr] = 0;
    return false;
}

int acyclic(int n) {
  //write your code here
  for(int i=0; i<n; i+=1) {
      vis[i] = 0;
      visCurr[i] = 0;
  }

  for(int i=0; i<n; i+=1) {
      if(acyclicRec(i)) return 1;
  }
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(n);
}
