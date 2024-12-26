#include <iostream>
#include <sstream>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    string S;
    cin >> S;

    unordered_set<string> part;
    for (int i = 0; i < S.length(); i++) {
        for (int j = S.length()-i; j > 0; j--) {
            part.insert(S.substr(i,j));
        }
    }
    
    output << part.size() << "\n";

    cout << output.str();
}