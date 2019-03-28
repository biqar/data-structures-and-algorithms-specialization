#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;
  int heap_size;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    heap_size = n;
    swaps_.clear();
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  int left(int i) { return (2*i + 1); }
  int right(int i) { return (2*i + 2); }

    void GenerateSwapsV1(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < heap_size && data_[l] < data_[i]) smallest = l;
        if (r < heap_size && data_[r] < data_[smallest]) smallest = r;
        if (smallest != i) {
            swap(data_[i], data_[smallest]);
            swaps_.push_back(make_pair(i, smallest));
            GenerateSwapsV1(smallest);
        }
    }

  void GenerateSwaps() {
    swaps_.clear();
    // The following naive implementation just sorts
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap,
    // but in the worst case gives a quadratic number of swaps.
    //
    // TODO: replace by a more efficient implementation
    for (int i = 0; i < data_.size(); ++i)
      for (int j = i + 1; j < data_.size(); ++j) {
        if (data_[i] > data_[j]) {
          swap(data_[i], data_[j]);
          swaps_.push_back(make_pair(i, j));
        }
      }
  }

 public:
  void Solve() {
    ReadData();
    for(int i=heap_size-1; i>=0; i-=1) {
        GenerateSwapsV1(i);
    }
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
