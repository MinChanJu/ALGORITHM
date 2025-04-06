#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

inline void dfs(vector<int> start, vector<int> link, int p, int idx);

vector<vector<int>> S;
int N;
int MIN = 1000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        vector<int> tmp;
        for (int j = 0; j < N; j++) {
            int x;
            cin >> x;
            tmp.push_back(x);
        }
        S.push_back(tmp);
    }

    vector<int> start, link;

    dfs(start, link, 0, 0);
    
    cout << MIN << "\n";
}

inline void dfs(vector<int> start, vector<int> link, int p, int idx) {
    if (p == N/2) {
        int ss = 0;
        for (int i = 0; i < start.size(); i++) {
            for (int j = 0; j < start.size(); j++) {
                if (i == j) continue;
                ss += S[start[i]][start[j]];
            }
        }

        for (int i = idx; i < N; i++) {
            link.push_back(i);
        }

        int ll = 0;
        for (int i = 0; i < link.size(); i++) {
            for (int j = 0; j < link.size(); j++) {
                if (i == j) continue;
                ll += S[link[i]][link[j]];
            }
        }

        if (ss >= ll) {
            if (ss-ll < MIN) MIN = ss-ll;
        } else {
            if (ll-ss < MIN) MIN = ll-ss;
        }
        
        return;
    }

    if (idx == N) return;

    start.push_back(idx);
    dfs(start, link, p+1, idx+1);
    start.pop_back();
    
    link.push_back(idx);
    dfs(start, link, p, idx+1);
    link.pop_back();
}