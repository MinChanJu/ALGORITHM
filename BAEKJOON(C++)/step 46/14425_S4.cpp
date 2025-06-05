#include <iostream>
#include <sstream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int N, M;
    cin >> N >> M;

    map<string, int> S;
    string tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        S[tmp] = 1;
    }

    int cnt = 0;
    for (int i = 0; i < M; i++) {
        cin >> tmp;
        cnt += S[tmp];
    }
    
    output << cnt << "\n";

    cout << output.str();
}