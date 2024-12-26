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
    
    int X[N];
    int sortX[N];
    for (int i = 0; i < N; i++) {
        cin >> X[i];
        sortX[i] = X[i];
    }
    
    sort(sortX, sortX+N);

    map<int, int> dict;
    
    int cnt = 0;
    for (int i = 1; i < N; i++) {
        if (sortX[i] != sortX[i-1]) {
            dict[sortX[i-1]] = cnt;
            cnt++;
        }
    }
    dict[sortX[N-1]] = cnt;
    
    for (int i = 0; i < N; i++) {
        output << dict[X[i]] << " ";
    }
    
    output << "\n";

    cout << output.str();
}