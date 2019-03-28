#include <iostream>
#include <string>

using std::string;

#define max_len 202

//char str1[max_len], str2[max_len];
int edit_value[max_len][max_len];

int _min(int a, int b) {
    return (a < b) ? a : b;
}

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  int len1 = str1.size();
  int len2 = str2.size();
  edit_value[0][0] = 0;

  for(int i=0 ; i<=len1 ; i++) edit_value[i][0] = i;
  for(int j=0 ; j<=len2 ; j++) edit_value[0][j] = j;

  for(int i=1 ; i<=len1 ; i++) {
    for(int j=1 ; j<=len2 ; j++) {
        int val = (str1[i-1] == str2[j-1]) ? 0 : 1;
        edit_value[i][j] = _min(edit_value[i-1][j-1]+val,
          _min(edit_value[i-1][j]+1, edit_value[i][j-1]+1));
  	}
  }
  return edit_value[len1][len2];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
