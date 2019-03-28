#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using std::vector;
using std::pair;

#define edge pair< int, int >
#define MAX 205

int n, m;
vector< pair< double, edge > > GRAPH, MST;
int parent[MAX];

double weight(int x1, int y1, int x2, int y2) {
  return sqrt((double)(x1 - x2) * (x1 - x2) + (double)(y1 - y2) * (y1 - y2));
}

int findset(int x, int *parent) {
    if(x != parent[x]) parent[x] = findset(parent[x], parent);
    return parent[x];
}

void init(vector<int> x, vector<int> y) {
    for(int i=1; i<=n; i++) parent[i] = i;

    m = 0;
    for(int i=0; i<n; i+=1) {
        for(int j=i+1; j<n; j+=1) {
            GRAPH.push_back(pair< double, edge >(weight(x[i], y[i], x[j], y[j]), edge(i+1, j+1)));
            m += 1;
        }
    }
}

double minimum_distance() {
    double result = 0.0;
    //write your code here
    int i, pu, pv;
    sort(GRAPH.begin(), GRAPH.end());
    for(i=0; i<m; i+=1) {
        pu = findset(GRAPH[i].second.first, parent);
        pv = findset(GRAPH[i].second.second, parent);
        if(pu != pv) {
            MST.push_back(GRAPH[i]);
            result += GRAPH[i].first;
            //std::cout << GRAPH[i].first << " ";
            parent[pu] = parent[pv];
        }
    }
    //std::cout << "\n";
    return result;
}

int main() {
  std::cin >> n;
  vector<int> x(n+1), y(n+1);
  for (int i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  init(x, y);
  std::cout << std::setprecision(10) << minimum_distance() << std::endl;
}
