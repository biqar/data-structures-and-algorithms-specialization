#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

std::vector<int> vsited(100005);
std::vector<int> dist(100005);

int distance(int n, vector<vector<int> > &adj, int s, int t) {
  //write your code here
  queue<int> q;

  for(int i=0; i<=n; i+=1) {
    vsited[i] = 0;
    dist[i] = 10000005;
  }

  vsited[s] = 1;
  dist[s] = 0;
  q.push(s);

  while(!q.empty()) {
    int curr = q.front(); q.pop();
    int sz = adj[curr].size();

    //std::cout << "curr: " << curr << "\n";

    for(int i=0; i<sz; i+=1) {
      int next = adj[curr][i];
      if(vsited[next] == 0) {
          //std::cout << "next: " << next << "";
        dist[next] = dist[curr] + 1;
        vsited[next] = 1;
        q.push(next);
      }
    }
    //std::cout << "\n";
  }

  if(vsited[t]) return dist[t];
  return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;

//   for(int i=0; i<n; i+=1) {
//       std::cout << "i: " << i << " -> ";
//       for(int j=0; j<adj[i].size(); j+=1) {
//           std::cout << adj[i][j] << " ";
//       }
//       std::cout << "\n";
//   }

  std::cout << distance(n, adj, s, t);
}
