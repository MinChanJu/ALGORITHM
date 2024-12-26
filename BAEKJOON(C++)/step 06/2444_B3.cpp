#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    stringstream output;

    for (int i = 0; i < N; i++) {
        for (int j = 1; j < N-i; j++) {
            output << " ";
        }
        for (int j = 0; j <= 2*i; j++) {
            output << "*";
        }
        output << "\n";
    }
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            output << " ";
        }
        for (int j = 0; j <= (N-i-1)*2; j++) {
            output << "*";
        }
        output << "\n";        
    }
    
    cout << output.str();
}