#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int cnt = 0;
    int sz = stops.size();
    stops.push_back(dist);
    sz += 1;
    //cout << sz << "\n";
    int cur = 0;
    for(int i=0; i<sz; i+=1) {
      //cout << "i: " << i << ", current: " << cur << "\n";
      if(stops[i] - cur == tank) {
          cnt += 1;
          cur = stops[i];
          //cout << "stop1: " << i << "\n";
      }
      else if(stops[i] - cur < tank) {
        if(i+1<sz && stops[i+1] - cur > tank) {
          cnt += 1;
          cur = stops[i];
          //cout << "stop2: " << i << "\n";
        }
      }
      else {
        return -1;
      }
    }
    return cnt;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
