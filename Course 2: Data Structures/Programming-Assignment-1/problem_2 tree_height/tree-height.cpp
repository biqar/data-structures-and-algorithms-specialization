#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using std::queue;
using std::vector;

class Node;

class Node {
public:
    int key;
    Node *parent;
    std::vector<Node *> children;

    Node() {
      this->parent = NULL;
    }

    void setParent(Node *theParent) {
      parent = theParent;
      parent->children.push_back(this);
    }
};


int main_with_large_stack_space() {
  std::ios_base::sync_with_stdio(0);
  int n;
  std::cin >> n;

  std::vector<Node> nodes;
  nodes.resize(n);
  for (int child_index = 0; child_index < n; child_index++) {
    int parent_index;
    std::cin >> parent_index;
    if (parent_index >= 0)
      nodes[child_index].setParent(&nodes[parent_index]);
    nodes[child_index].key = child_index;
  }

  // Replace this code with a faster implementation
  int maxHeight = 0;
  for (int leaf_index = 0; leaf_index < n; leaf_index++) {
    int height = 0;
    for (Node *v = &nodes[leaf_index]; v != NULL; v = v->parent)
      height++;
    maxHeight = std::max(maxHeight, height);
  }

  std::cout << maxHeight << std::endl;
  return 0;
}

int main_with_large_stack_space_v1() {
  std::ios_base::sync_with_stdio(0);
  int n;
  int root;
  queue<int> q;
  std::cin >> n;

  std::vector<vector<int>> nodes;
  std::vector<int> dist;
  nodes.resize(n);
  dist.resize(n);
  for (int child_index = 0; child_index < n; child_index++) {
    int parent_index;
    std::cin >> parent_index;
    if (parent_index >= 0) {
        nodes[parent_index].push_back(child_index);
    }
    else {
        root = child_index;
    }
  }

  q.push(root);
  dist[root] = 0;
  // Replace this code with a faster implementation
  int maxHeight = 0;

  while(!q.empty()) {
    int cur = q.front();
    q.pop();
    int sz = nodes[cur].size();
    //std::cout << "parent: " << cur << " -> ";
    //if(sz) maxHeight += 1;
    for(int i=0; i<sz; i+=1) {
        dist[nodes[cur][i]] = dist[cur] + 1;
        if(dist[nodes[cur][i]] > maxHeight) maxHeight = dist[nodes[cur][i]];
        q.push(nodes[cur][i]);
        //std::cout << nodes[cur][i] << " ";
    }
    //std::cout<< "\n";
  }

  std::cout << maxHeight + 1 << std::endl;
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }

#endif
  return main_with_large_stack_space_v1();
}
