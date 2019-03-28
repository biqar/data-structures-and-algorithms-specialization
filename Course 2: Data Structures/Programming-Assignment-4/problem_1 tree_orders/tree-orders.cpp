#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using std::vector;
using std::stack;
using std::ios_base;
using std::cin;
using std::cout;

class TreeOrders {
  int n;
  vector <int> key;
  vector <int> left;
  vector <int> right;

public:
  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    }
  }


  vector <int> in_order() {
    vector<int> result;
    stack<int> st;
    // Finish the implementation
    // You may need to add a new recursive method to do that
    int curr = 0;
    while (!st.empty() || curr != -1)
	{
		// if current node is not null, push it to the stack (defer it)
		// and move to its left child
		if (curr != -1) {
			st.push(curr);
			curr = left[curr];
		}
		else {
			// else if current node is null, we pop an element from stack,
			// print it and finally set current node to its right child
			curr = st.top(); st.pop();
			result.push_back(key[curr]);

			curr = right[curr];
		}
	}

    return result;
  }

  vector <int> pre_order() {
    vector<int> result;
    stack<int> st;
    // Finish the implementation
    // You may need to add a new recursive method to do that
    int curr = 0;
    while (!st.empty() || curr != -1) {
		if (curr != -1) {
			st.push(curr);
			result.push_back(key[curr]);
			curr = left[curr];
		}
		else {
			// else if current node is null, we pop an element from stack,
			// print it and finally set current node to its right child
			curr = st.top(); st.pop();
			curr = right[curr];
		}
	}

    return result;
  }

  vector <int> post_order() {
    vector<int> result;
    stack<int> st;
    // Finish the implementation
    // You may need to add a new recursive method to do that
    int curr = 0;
    while(true) {
        while(curr != -1) {
            st.push(curr);
            st.push(curr);
            curr = left[curr];
        }

        // Check for empty stack
        if(st.empty()) break;
        curr = st.top(); st.pop();

        if(!st.empty() && st.top() == curr) curr = right[curr];
        else {
            result.push_back(key[curr]);
            curr = -1;
        }
    }

    return result;
  }
};

void print(vector <int> a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}

int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  print(t.in_order());
  print(t.pre_order());
  print(t.post_order());
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

  return main_with_large_stack_space();
}

