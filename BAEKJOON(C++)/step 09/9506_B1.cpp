#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int N;

    while (true) {
        cin >> N;
        if (N == -1) break;
        int sum = 1;
        stringstream oper;
        oper << "1";
        for (int i = 2; i < N; i++) {
            if (N%i == 0) {
                sum += i;
                oper << " + " << i;
            }
        }
        if (sum == N) output << N << " = " << oper.str() << "\n";
        else output << N << " is NOT perfect.\n";
    }

    cout << output.str();
}