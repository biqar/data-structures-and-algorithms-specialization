#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int const Letters =    4;
int const NA      =   -1;

struct Node {
	Node *next [Letters];

	Node () {
		//fill (next, next + Letters, NULL);
		for(int i=0; i<Letters; i+=1) next[i] = NULL;
	}

	bool isLeaf () const {
	    return (next[0] == NULL && next[1] == NULL && next[2] == NULL && next[3] == NULL);
	}
};

int letterToIndex (char letter) {
	switch (letter) {
		case 'A': return 0; break;
		case 'C': return 1; break;
		case 'G': return 2; break;
		case 'T': return 3; break;
		default: assert (false); return -1;
	}
}

vector <int> solve (const string& text, int n, const vector <string>& patterns) {
	vector <int> result;

	Node *cur, *trie = new Node();
	int sz = patterns.size();
	for(int i=0; i<sz; i+=1) {
        cur = trie;
        int psz = patterns[i].size();
        for(int j=0; j<psz; j+=1) {
            int idx = letterToIndex(patterns[i][j]);
            if(cur->next[idx] == NULL) {
                cur->next[idx] = new Node();
            }
            cur = cur->next[idx];
        }
	}

	int tsz = text.size();
	for(int i=0; i<tsz; i+=1) {
        cur = trie;
        //std::cout << "i: " << i << "\n";
        for(int j=i; j<tsz; j+=1) {
            int idx = letterToIndex(text[j]);
            //std::cout << "idx: " << idx << " " << text[j] << "\n";
            if(cur->next[idx] != NULL) {
                //std::cout << "idx: " << idx << " exist, going to next" << "\n";
                cur = cur->next[idx];

                if(cur->next[0] == NULL && cur->next[1] == NULL
                && cur->next[2] == NULL && cur->next[3] == NULL) {
                    //std::cout << "match found in pos: " << i << "\n";
                    result.push_back(i);
                    break;
                }
            } else {
               break;
            }
        }
	}

	return result;
}

int main (void) {
	string t;
	cin >> t;

	int n;
	cin >> n;

	vector <string> patterns (n);
	for (int i = 0; i < n; i++) {
		cin >> patterns[i];
	}

	vector <int> ans;
	ans = solve (t, n, patterns);

	for (int i = 0; i < (int) ans.size (); i++) {
		cout << ans[i];
		if (i + 1 < (int) ans.size ()) {
			cout << " ";
		}
		else {
			cout << endl;
		}
	}

	return 0;
}
