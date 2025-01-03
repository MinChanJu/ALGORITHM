#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

inline void dfs(int p, int m, int x, int d, int sum, int idx);

vector<int> num;
int N;
int MAX = -1000000000;
int MIN = 1000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        num.push_back(x);
    }
    
    int p, m, x, d;
    cin >> p >> m >> x >> d;

    dfs(p, m, x, d, num[0], 1);

    cout << MAX << "\n" << MIN << "\n";
}

inline void dfs(int p, int m, int x, int d, int sum, int idx) {
    if (idx == N) {
        if (sum > MAX) MAX = sum;
        if (sum < MIN) MIN = sum;
        return;
    }

    if (p != 0) dfs(p-1, m, x, d, sum+num[idx], idx+1);
    if (m != 0) dfs(p, m-1, x, d, sum-num[idx], idx+1);
    if (x != 0) dfs(p, m, x-1, d, sum*num[idx], idx+1);
    if (d != 0) dfs(p, m, x, d-1, sum/num[idx], idx+1);
}