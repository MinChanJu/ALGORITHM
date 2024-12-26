#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int N;
    cin >> N;

    for (int i = 2; i*i <= N; i++) {
        while (N%i == 0) {
            output << i << "\n";
            N /= i;
        }
    }

    if (N > 1) output << N << "\n";
    
    cout << output.str();
}