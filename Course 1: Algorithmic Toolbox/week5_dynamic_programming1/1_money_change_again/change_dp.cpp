#include <iostream>

int coins[3] = {1, 3, 4};
const int MX = 100000;

int _min(int a, int b) {
    return a < b ? a : b;
}

int get_change(int m) {
  int min_coin[m + 5];
  min_coin[0] = 0;
  for(int i = 1; i<=m; i+=1) {
    min_coin[i] = MX;
    for(int j=0; j<3; j+=1) {
      if(i >= coins[j]) {
        min_coin[i] = _min(min_coin[i], min_coin[i-coins[j]]+1);
      }
      else {
        break;
      }
    }
  }
  return min_coin[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
