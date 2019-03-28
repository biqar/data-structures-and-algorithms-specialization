#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using std::vector;

// int binary_search(const vector<int> &a, int x) {
//   int left = 0, right = (int)a.size();
//   //write your code here
// }

int binary_search_recur(const vector<int> &a, int st, int nd, int x) {
  if (nd < st) return - 1;
  int mid = st + (nd - st) / 2;

  if (x == a[mid]) return mid;

  if (x < a[mid]) {
    return binary_search_recur(a, st, mid - 1, x);
  }
  else {
    return binary_search_recur(a, mid + 1, nd, x);
  }
}

int binary_search_ite(const vector<int> &a, int x, int n) {
    int st = 0, nd = n;
    while (st <= nd) {
        int mid = st + (nd - st) / 2;
        if (x == a[mid]) return mid;
        else if (x < a[mid]) nd = mid - 1;
        else st = mid + 1;
    }
    return -1;
}

// int linear_search(const vector<int> &a, int x) {
//   for (size_t i = 0; i < a.size(); ++i) {
//     if (a[i] == x) return i;
//   }
//   return -1;
// }

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  sort(a.begin(), a.end());
//   for (int i = 0; i < n; ++i) {
//     std::cout << a[i] << " ";
//   }
//   std::cout << "\n";
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    //if(i) std::cout << ' ';
     std::cout << binary_search_recur(a, 0, n-1, b[i]) << ' ';
    //std::cout << binary_search_ite(a, b[i], n) << ' ';
  }
  //std::cout << "\n";
}
