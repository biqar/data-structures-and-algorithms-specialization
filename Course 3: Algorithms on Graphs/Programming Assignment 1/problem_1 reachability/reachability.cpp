#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;

std::vector<int> visited(1005);

int reach(int n, vector<vector<int> > &adj, int x, int y) {
  //write your code here
  for(int i=0; i<=n; i+=1) visited[i] = 0;
  queue<int> q;

  visited[x] = 1;
  q.push(x);

  while(!q.empty()) {
    int curr = q.front(); q.pop();
    int sz = adj[curr].size();

    for(int i=0; i<sz; i+=1) {
        int next = adj[curr][i];
        if(visited[next] == 0) {
            visited[next] = 1;
            q.push(next);
        }
    }
  }

  return visited[y];
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(n, adj, x - 1, y - 1);
}
