#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int v;
    cin >> v;
    int cnt = 0;
    for (int i = 0;i < N;i++) {
        if (A[i] == v) cnt++;
    }
    cout << cnt << "\n";
}