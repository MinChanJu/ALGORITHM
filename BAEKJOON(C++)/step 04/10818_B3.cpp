#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    int X;
    int max = -1000000, min = 1000000;
    for (int i = 0; i < N; i++) {
        cin >> X;
        max = X > max ? X : max;
        min = X < min ? X : min;
    }

    cout << min << " " << max << "\n";
}