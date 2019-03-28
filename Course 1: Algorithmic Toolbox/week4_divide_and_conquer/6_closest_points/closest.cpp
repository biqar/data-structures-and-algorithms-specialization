#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using std::vector;
using std::string;
using std::pair;
using std::min;
using std::sort;

const int MM = 10^5 + 5;

struct point { // Creates normal 2D point
  double x, y;
  point() {}
  point( double xx, double yy ) { x = xx, y = yy;}
};

point p[MM], s1[MM], s2[MM];

bool sortX(point &a, point &b) { return ( a.x == b.x ) ? a.y < b.y : a.x < b.x; }
bool sortY(point &a, point &b) { return ( a.y == b.y ) ? a.x < b.x : a.y < b.y; }

// double minimal_distance(vector<int> x, vector<int> y) {
//   //write your code here
//   return 0.;
// }

double Distance( point a, point b ) {
  //std::cout << a.x << " " << a.y << "\n";
  //std::cout << b.x << " " << b.y << "\n";
  double ret = sqrt( ( a.x - b.x ) * ( a.x - b.x ) + (a.y - b.y ) * ( a.y - b.y ) );
  //std::cout << ret << "\n\n";
  return ret;
}

double Distance( int i, int j ) {
  //std::cout << s1[i].x << " " << s1[i].y << "\n";
  //std::cout << s2[j].x << " " << s2[j].y << "\n";
  double ret = sqrt( ( s1[i].x - s2[j].x ) * ( s1[i].x - s2[j].x ) + (s1[i].y - s2[j].y ) * ( s1[i].y - s2[j].y ) );
  //std::cout << ret << "\n\n";
  return ret;
}

double _min(double a, double b) {
    return a < b ? a : b;
}

double closestPair( int k1, int k2 ){
  double d, d2 ,d3;
  if(k2-k1+1 == 1) return 0;
  if(k2-k1+1 == 2) return Distance(p[k1], p[k2]);
  if(k2-k1+1 == 3) {
      d = Distance( p[k1], p[k1+1] );
      d2 = Distance( p[k1+1], p[k1+2]);
      d3 = Distance( p[k1+2], p[k1]);
      return min( min(d, d2), d3 );
    }
    int k, ns1, ns2;
    k = (k1 + k2) / 2;
    d = closestPair(k1 , k);
    d2 = closestPair(k+1 , k2);
    //std::cout << "d: " << d << ", d2: " << d2 << "\n";

    if(d > d2) d = d2;
    ns1 = ns2 = 0;
    for(int i = k; i>=k1 ; i--) {
      if( p[k].x - p[i].x > d ) break;
      s1[ ns1++ ] = p[i];
      std::cout << p[i].x << " " << p[i].y << "\n";
    }
    std::cout << "\n";
    sort(s1, s1+ns1, sortY);
    for(int i=0;i<ns1;i++) {
        std::cout << s1[i].x << " " << s1[i].y << "\n";
    }
    std::cout << "\n";
    std::cout << s1[0].x << " " << s1[0].y << "\n\n";

    for(int i = k+1; i<=k2 ; i++) {
      if( p[i].x - p[k].x > d ) break;
      s2[ ns2++ ] = p[i];
      std::cout << p[i].x << " " << p[i].y << "\n";
    }
    std::cout << "\n";

    std::cout << s1[0].x << " " << s1[0].y << "\n\n";

    sort(s2, s2+ns2, sortY);

    for(int i=0;i<ns2;i++) {
        std::cout << s2[i].x << " " << s2[i].y << "\n";
    }
    std::cout << "\n";

    std::cout << s1[0].x << " " << s1[0].y << "\n\n";

    std::cout << ns1 << " <-> " << ns2 << "\n\n";

    for(int i=0;i<ns1;i++) {
      for(int j=0;j<ns2;j++) {
        //std::cout << s1[ii].x << " " << s1[ii].y << "\n";
        //std::cout << s2[j].x << " " << s2[j].y << "\n";
        //std::cout << "calling to calculate distace\n";
        if(s2[j].y - s1[i].y > d) break;
        d = _min( d, Distance( s1[i], s2[j] ) );
        //std::cout << i << " to " << j << "\n\n";
        //d = _min( d, Distance( i, j ) );
        //std::cout << "distance: " << Distance( s1[i], s2[j] ) << "\n";
        //std::cout << "d: " << d << "\n";
        //std::cout << "\n";
      }
    }
    return d;
}

//tried and failed
//Failed case #3/23: (Wrong answer)
//Input: 4 0 0 5 6 3 4 7 2 Your output: 0.000000000 Correct output: 2.828427125
//(Time used: 0.22/2.00, memory used: 22540288/536870912.)
int main() {
  int n;
  std::cin >> n;
  double x, y;
  for (int i = 0; i < n; i++) {
    std::cin >> p[i].x >> p[i].y;
  }
  sort( p, p+n, sortX );
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << closestPair(0, n-1) << "\n";
  return 0;
}
