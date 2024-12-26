#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int N, K;
    cin >> N >> K;
    
    int cnt = 0;
    int j = 0;
    for (int i = 1; i <= N; i++) {
        if (N%i == 0) {
            cnt++;
            if (cnt == K) j = i;
        }
    }

    output << j << "\n";

    cout << output.str();
}