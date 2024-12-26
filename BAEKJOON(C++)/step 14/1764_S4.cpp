#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int N, M, cnt = 0;
    string name;
    cin >> N >> M;

    unordered_map<string, int> listen;

    for (int i = 0; i < N; i++) {
        cin >> name;
        listen[name]++;
    }

    string see[M];
    for (int i = 0; i < M; i++) {
        cin >> name;
        see[i] = name;
    }

    sort(see, see+M);

    for (int i = 0; i < M; i++) {
        if (listen[see[i]] == 1) {
            cnt++;
            output << see[i] << "\n";
        }
    }

    cout << cnt << "\n" << output.str();
}