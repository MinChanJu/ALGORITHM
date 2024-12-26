#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    string S;
    while (getline(cin, S)) {
        output << S << "\n";
    }

    cout << output.str();
}