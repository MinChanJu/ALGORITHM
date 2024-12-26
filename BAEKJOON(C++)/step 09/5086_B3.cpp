#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int A, B;
    while (true) {
        cin >> A >> B;
        if (A == 0) break;

        if (A > B && A%B == 0) output << "multiple\n";
        else if (A < B && B%A == 0) output << "factor\n";
        else output << "neither\n";
    }

    cout << output.str();
}