#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int N;
    cin >> N;

    int cnt = 0;
    int cur = 665, k;
    while (cnt != N) {
        cur++;
        k = cur;
        while (k > 600) {
            if (k%1000 == 666) {
                cnt++;
                break;
            }
            k /= 10;
        }
    }

    output << cur << "\n";

    cout << output.str();
}