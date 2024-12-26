#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

bool compare(const int* a, const int* b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int N;
    cin >> N;

    int** pos = new int*[N];
    for (int i = 0; i < N; i++) {
        pos[i] = new int[2];
        cin >> pos[i][0] >> pos[i][1];
    }
    
    sort(pos, pos+N, compare);
    
    for (int i = 0; i < N; i++) output << pos[i][0] << " " << pos[i][1] << "\n";

    cout << output.str();
}

bool compare(const int* a, const int* b) {
    if (a[1] == b[1]) return a[0] < b[0];
    return a[1] < b[1];
}