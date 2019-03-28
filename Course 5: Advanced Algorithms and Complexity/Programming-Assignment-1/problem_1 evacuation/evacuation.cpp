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

/* This class implements a bit unusual scheme for storing edges of the graph,
 * in order to retrieve the backward edge for a given edge quickly. */
// class FlowGraph {
// public:
//     struct Edge {
//         int from, to, capacity, flow;
//     };

// private:
//     /* List of all - forward and backward - edges */
//     vector<Edge> edges;

//     /* These adjacency lists store only indices of edges in the edges list */
//     vector<vector<size_t> > graph;

// public:
//     explicit FlowGraph(size_t n): graph(n) {}

//     void add_edge(int from, int to, int capacity) {
//         /* Note that we first append a forward edge and then a backward edge,
//          * so all forward edges are stored at even indices (starting from 0),
//          * whereas backward edges are stored at odd indices in the list edges */
//         Edge forward_edge = {from, to, capacity, 0};
//         Edge backward_edge = {to, from, 0, 0};
//         graph[from].push_back(edges.size());
//         edges.push_back(forward_edge);
//         graph[to].push_back(edges.size());
//         edges.push_back(backward_edge);
//     }

//     size_t size() const {
//         return graph.size();
//     }

//     const vector<size_t>& get_ids(int from) const {
//         return graph[from];
//     }

//     const Edge& get_edge(size_t id) const {
//         return edges[id];
//     }

//     void add_flow(size_t id, int flow) {
//         /* To get a backward edge for a true forward edge (i.e id is even), we should get id + 1
//          * due to the described above scheme. On the other hand, when we have to get a "backward"
//          * edge for a backward edge (i.e. get a forward edge for backward - id is odd), id - 1
//          * should be taken.
//          *
//          * It turns out that id ^ 1 works for both cases. Think this through! */
//         edges[id].flow += flow;
//         edges[id ^ 1].flow -= flow;
//     }
// };

// FlowGraph read_data() {
//     int vertex_count, edge_count;
//     std::cin >> vertex_count >> edge_count;
//     FlowGraph graph(vertex_count);
//     for (int i = 0; i < edge_count; ++i) {
//         int u, v, capacity;
//         std::cin >> u >> v >> capacity;
//         graph.add_edge(u - 1, v - 1, capacity);
//     }
//     return graph;
// }

// int max_flow(FlowGraph& graph, int from, int to) {
//     int flow = 0;
//     /* your code goes here */
//     return flow;
// }

const int MAX = 105;

int G[MAX][MAX], R[MAX][MAX];
int parent[MAX];
int n;

bool bfs(int s, int t) {
    int visited[MAX];
    CLR(visited);

    queue <int> q;
    q.push(s);
    visited[s] = 1;
    parent[s] = -1;

    while(!q.empty()) {
        int u = q.front(); q.pop();

        for(int v=0; v<n; v+=1) {
            if (visited[v]==0 && R[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = 1;
            }
        }
    }

    return (visited[t] == 1);
}

int max_flow(int s, int t) {
    int u, v;
    int max_flow = 0;

    while (bfs(s, t)) {
        int path_flow = INF;
        for (v=t; v!=s; v=parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, R[u][v]);
        }

        for (v=t; v != s; v=parent[v]) {
            u = parent[v];
            R[u][v] -= path_flow;
            R[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    CLR(G);
    CLR(R);

    int m;
    cin >> n >> m;

    for(int i=0; i<m; i+=1) {
      int x, y, w;
      cin >> x >> y >> w;
      x -= 1; y -= 1;
      G[x][y] += w;
      R[x][y] += w;
    }

    std::cout << max_flow(0, n - 1) << "\n";
    return 0;
}
