#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using std::vector;
using std::queue;
using std::stack;
using std::pair;

std::vector<int> in(10005), tin(10005), circuit;
std::vector<int> visited(10005);
std::vector<int> G[10005], T[10005];
int n, m;

void dfs(int u) {
    visited[u] = 1;

    int sz = G[u].size();
    for (int i=0; i<sz; i+=1) {
        int v = G[u][i];
        if(visited[v] == 0) dfs(v);
    }
}

void tdfs(int u) {
    visited[u] = 1;

    int sz = T[u].size();
    for (int i=0; i<sz; i+=1) {
        int v = T[u][i];
        if(visited[v] == 0) tdfs(v);
    }
}

bool isSC() {
    int ii;
    for (ii=0; ii<n; ii+=1) {
        if (G[ii].size() > 0) break;
    }

    dfs(ii);

    for(int i=0; i<n; i+=1) {
        if(G[i].size() > 0 && visited[i] == 0) return false;
    }

    // Mark all the vertices as not visited (For second DFS)
    for (int i=0; i<n; i+=1) {
        visited[i] = 0;
    }

    tdfs(ii);

    for(int i=0; i<n; i+=1) {
        if (G[i].size() > 0 && visited[i] == 0) return false;
    }

    return true;
}

bool isEulerianCycle() {
    if (isSC() == false) return false;

    for (int i=0; i<n; i+=1) {
        if(G[i].size() != in[i]) return false;
    }
    return true;
}

void findEulerianCycle() {
    stack<int> st;

    st.push(0);
    int u = 0;

    while(!st.empty()) {
        if(tin[u]) {
            st.push(u);

            int v = G[u].back();
            tin[u]--;
            G[u].pop_back();
            u = v;
        }

        else {
            circuit.push_back(u);
            u = st.top(); st.pop();
        }
    }

    bool isFirst = true;
    int csz = circuit.size() - 1;
    for (int i=csz; i>=1; i-=1) {
        if(!isFirst) std::cout<<" ";
        std::cout << circuit[i] + 1;
        isFirst = false;
    }
    std::cout << "\n";
}

int main() {
  std::cin >> n >> m;

  for(int i=0; i<n; i+=1) {
    in[i] = 0;
    tin[i] = 0;
    visited[i] = 0;
  }

  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    x -= 1;
    y -= 1;
    G[x].push_back(y);
    in[y] += 1;

    T[y].push_back(x);
    tin[x] += 1;
  }
  if(isEulerianCycle()) {
    std::cout << 1 << "\n";
    findEulerianCycle();
  }
  else {
    std::cout << 0 << "\n";
  }
}
