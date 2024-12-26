#include <iostream>
#include <sstream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int N;
    cin >> N;

    map<string, int> S;
    string name, tmp;
    for (int i = 0; i < N; i++) {
        cin >> name >> tmp;
        if (tmp == "enter") S[name] = 1;
        else S[name] = 0;

    }

    for (auto pair = S.rbegin(); pair != S.rend(); pair++) {
        if (pair->second == 1) output << pair->first << "\n";
    }
    
    cout << output.str();
}