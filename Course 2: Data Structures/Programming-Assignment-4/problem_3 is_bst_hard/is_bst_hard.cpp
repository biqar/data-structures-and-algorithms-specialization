#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::stack;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

vector<Node> tree;

const long long int BIG_NUMBER = (long long int) 1 << 50;

bool IsBinarySearchTree(const vector<Node>& tree) {
  // Implement correct algorithm here
  stack<int> st;
  int curr = 0;
  while (!st.empty() || curr != -1) {
		// if current node is not null, push it to the stack (defer it)
		// and move to its left child
		std::cout << curr << "\n";
		if (curr != -1) {
			st.push(curr);
			int val = tree[curr].key;
			curr = tree[curr].left;
			if(curr != -1 && tree[curr].key > val) return false;
		}
		else {
			// else if current node is null, we pop an element from stack,
			// print it and finally set current node to its right child
			curr = st.top(); st.pop();
			int val = tree[curr].key;
			//result.push_back(key[curr]);

			curr = tree[curr].right;
			if(curr != -1 && tree[curr].key < val) return false;
		}
	}
  return true;
}

bool IsBinarySearchTreeV1(int n, long long int mn, long long int mx) {
    if(n == -1) return true;

    if(tree[n].key < mn || tree[n].key >= mx) return false;

    return IsBinarySearchTreeV1(tree[n].left, mn, tree[n].key) && IsBinarySearchTreeV1(tree[n].right, tree[n].key, mx);
}

int main() {
  int nodes;
  cin >> nodes;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (nodes == 0 || IsBinarySearchTreeV1(0, -BIG_NUMBER, BIG_NUMBER)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
