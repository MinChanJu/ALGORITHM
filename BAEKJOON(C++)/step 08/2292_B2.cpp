#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int N;
    cin >> N;

    int layer = 1;
    N -= 1;
    while (6*layer < N) {
        N -= 6*layer;
        layer++;
    }

    if (N == 0) output << layer << "\n";
    else output << layer+1 << "\n";

    cout << output.str();
}