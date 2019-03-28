#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using std::string;
using std::vector;
using std::map;
using std::cin;

std::vector<vector<string>> elems(100005);
std::map<string, bool> m;
std::map<string, bool>::iterator mit;

struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {
    int bucket_count;
    // store all strings in one vector
    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }

public:
    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count) {}

    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query& query) {
        if (query.type == "check") {
            // use reverse order, because we append strings to the end
            int hindex = query.ind;
            int sz = elems[hindex].size();
            for (int i = sz - 1; i >= 0; i-=1) {
                std::cout << elems[hindex][i] << " ";
            }
            std::cout << "\n";
        } else {
            int hindex = hash_func(query.s);

            if (query.type == "find") {
                mit = m.find(query.s);
                writeSearchResult(mit != m.end());
            }
            else if (query.type == "add") {
                //std::cout << "add in index: " << hindex << "\n";
                mit = m.find(query.s);
                if (mit == m.end()) {
                    elems[hindex].push_back(query.s);
                    m[query.s] = true;
                }
            }
            else if (query.type == "del") {
                mit = m.find(query.s);
                if (mit != m.end()) {
                    m.erase(mit);
                    vector<string>::iterator it = std::find(elems[hindex].begin(), elems[hindex].end(), query.s);
                    elems[hindex].erase(it);
                }
            }
        }
    }

    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
