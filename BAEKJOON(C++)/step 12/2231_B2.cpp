#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int N, k = 1;
    cin >> N;
    
    for (int i = 1; i < N; i++) {
        int sum = 0;
        int sub = i;
        while (sub != 0) {
            sum += sub%10;
            sub /= 10;
        }
        if (sum + i == N) {
            k = 0;
            output << i << "\n";
            break;
        } 
    }

    if (k) output << "0\n";
    
    cout << output.str();
}