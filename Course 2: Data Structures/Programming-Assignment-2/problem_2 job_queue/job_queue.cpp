#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using std::vector;
using std::priority_queue;
using std::cin;
using std::cout;

struct Node {
    int pos;
    long long int val;
    Node(long long int val, int pos) : val(val), pos(pos) {}
};

struct CompareNode {
    bool operator()(Node const& n1, Node const& n2) {
        if(n1.val == n2.val) return n1.pos > n2.pos;
        return n1.val > n2.val;
    }
};

std::vector<int> v(100005);
std::vector<int> assigned_workers(100005);
std::vector<long long> start_times(100005);
std::priority_queue<Node, std::vector<Node>, CompareNode> pq;

class JobQueue {
 private:
  int num_workers;
  int m;

  void WriteResponse() const {
    for (int i = 0; i < m; ++i) {
      cout << assigned_workers[i] << " " << start_times[i] << "\n";
    }
  }

  /*void ReadData() {
    //int m;
    cin >> num_workers >> m;
    //v.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> v[i];
  }*/

  void ReadData() {
    //std::ios_base::sync_with_stdio(false);
    std::cin >> num_workers >> m;
    //v.resize(m);

    //std::cout << v.size() << "\n";
    for(int i=0; i<m; i+=1) {
        int tmp;
        cin >> tmp;
        v[i] = tmp;
        //std::cout << i << jobs[i] << "\n";
    }
    //std::cout << "pora shesh\n";
    for(int i = 0; i < num_workers; i+=1) {
        pq.push(Node(0, i));
    }
    //std::cout << "pora shesh\n";
  }

  void AssignJobsV1() {
    // TODO: replace this code with a faster algorithm.
    int curr_job = 0;
    //int sz = jobs.size();

    while(curr_job < m) {
        Node n = pq.top(); pq.pop();
        //std::cout << "ekhono ghurtechi\n";
        assigned_workers[curr_job] = n.pos;
        start_times[curr_job] = n.val;
        pq.push(Node(n.val+v[curr_job], n.pos));
        curr_job += 1;
    }
  }

 public:
  void Solve() {
    ReadData();
    //AssignJobs();
    AssignJobsV1();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
