#include <iostream>
#include <vector>

using std::vector;

#define MAXC 1000
int A[MAXC],B[MAXC];
int lenA,lenB;
int dp[MAXC][MAXC];
bool visited[MAXC][MAXC];

// int lcs2(vector<int> &a, vector<int> &b) {
//   //write your code here
//   return std::min(std::min(a.size(), b.size()), c.size());
// }

int _max(int a, int b) {
  return a > b ? a : b;
}

int lcs(int i, int j) {
	if(i == lenA or j == lenB) return 0;
	if(visited[i][j])return dp[i][j];

	int ans=0;
	if(A[i]==B[j]) ans=1+lcs(i+1,j+1);
	else {
		int val1=lcs(i+1,j);
		int val2=lcs(i,j+1);
		ans=_max(val1,val2);
	}
	visited[i][j]=1;
	return dp[i][j] = ans;
}

int main() {
  std::cin >> lenA;
  for (int i = 0; i < lenA; i++) {
    std::cin >> A[i];
  }

  std::cin >> lenB;
  for (int i = 0; i < lenB; i++) {
    std::cin >> B[i];
  }

  std::cout << lcs(0, 0) << std::endl;
}
