#include <iostream>
#include <vector>

using std::vector;

#define MAX 200005

int a[MAX];
int result[MAX];
long long int mergeAndCount(int left_b, int mid, int mid_1, int right_b) {
	int x=left_b, y=mid_1, i, k=0;
	long long int count=0;

	while((x<=mid) && (y<=right_b))
	{
		if(a[x] <= a[y])
			result[k] = a[x++];
		else
		{
			result[k] = a[y++];
			count += (mid-x+1);
		}
		k++;
	}

	while(x <= mid)
		result[k++] = a[x++];
	while(y <= right_b)
		result[k++] = a[y++];

	int j = 0;
	for(i=left_b; i<=right_b; i++)
		a[i] = result[j++];

	return count;
}


long long int countInversions( int left_b, int right_b) {
	int mid = (left_b + right_b)/2;
	long long int countLeft, countRight, countMerge;

	if (left_b >= right_b)
		return 0;

	countLeft = countInversions(left_b, mid);
	countRight = countInversions((mid+1), right_b);

	countMerge = mergeAndCount(left_b, mid, (mid+1), right_b);

	return(countLeft + countRight + countMerge);
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  //write your code here
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  //vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  //vector<int> b(a.size());
  long long int res = countInversions( 0, n-1);
  //std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
  std::cout << res << '\n';
}
