#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int N;
    cin >> N;
    
    int count[10001];
    for (int i = 0; i < 10001; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        count[num]++;
    }

    for (int i = 0; i < 10001; i++) {
        while (count[i]) {
            cout << i << "\n";
            count[i]--;
        }
    }

    cout << output.str();
}