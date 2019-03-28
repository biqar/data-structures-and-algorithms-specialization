#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

bool comp(Segment s1, Segment s2) {
    return (s1.end < s2.end);
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  sort(segments.begin(), segments.end(), comp);
  int cur = segments[0].end;
  points.push_back(cur);
  int sz = segments.size();

  for (int i = 0; i < sz; i++) {
    if((cur < segments[i].start) || (cur > segments[i].end)) {
      cur = segments[i].end;
      points.push_back(cur);
    }
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (int i = 0; i < n; i++) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
