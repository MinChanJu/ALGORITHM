#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int N;
    cin >> N;
    
    map<int, int> dict;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        dict[x] = 1;
    }

    int M;
    cin >> M;

    int num[M];
    for (int i = 0; i < M; i++) cin >> num[i];
    
    for (int i = 0; i < M; i++) {
        output << dict[num[i]] << " ";
    }
    
    output << "\n";

    cout << output.str();
}