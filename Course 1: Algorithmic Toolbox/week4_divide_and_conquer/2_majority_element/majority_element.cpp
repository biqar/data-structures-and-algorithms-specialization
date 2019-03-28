#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using std::vector;
using std::map;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  return -1;
}

int main() {
  int n, x;
  map<int, int> m;
  std::cin >> n;
  map<int, int>::iterator it;
  //vector<int> a(n);
  for (int i = 0; i < n; i++) {
    //std::cin >> a[i];
    std::cin >> x;

    it = m.find(x);
    if (it != m.end()) m[x] += 1;
    else m[x] = 1;
  }

  int mx = -1;
  for ( it = m.begin(); it != m.end(); it++) {
      if(mx < it->second) mx = it->second;
  }
  std::cout << (mx > n/2) << '\n';
}
