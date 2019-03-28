#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::string;
using std::vector;

const int MAX = 1000005;

int overlap[MAX];
string pattern, text;

// Find all occurrences of the pattern in the text and return a
// vector with all positions in the text (starting from 0) where
// the pattern starts in the text.
vector<int> find_pattern() {
  vector<int> result;
  // Implement this function yourself
  int sz = text.size();
  int m = pattern.size();
  for(int i = 0, j = 0; i<sz; i+=1) {
      while(true) {
          if(text[i] == pattern[j]) {
              j++;
              if(j == m) {
                  result.push_back(i-m+1);
                  j = overlap[j];
              }
              break;
          }
          else if(j == 0) break;
          else j = overlap[j];
      }
  }
  return result;
}

void computeOverlap() {
    overlap[0] = -1;
    int sz = pattern.size();
    for(int i=0; i<sz; i+=1) {
        overlap[i+1] = overlap[i] + 1;
        while(overlap[i+1] > 0 && pattern[i] != pattern[overlap[i+1]-1]) {
            overlap[i+1] = overlap[overlap[i+1]-1] + 1;
        }
    }
}

int main() {
  cin >> pattern;
  cin >> text;
  computeOverlap();
  vector<int> result = find_pattern();
  for (int i = 0; i < result.size(); ++i) {
    printf("%d ", result[i]);
  }
  printf("\n");
  return 0;
}
