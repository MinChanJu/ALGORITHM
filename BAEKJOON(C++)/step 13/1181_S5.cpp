#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

bool compare(string a, string b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int N;
    cin >> N;
    
    string word[N];
    for (int i = 0; i < N; i++) {
        cin >> word[i];
    }

    sort(word, word+N, compare);
    
    string last = "";
    for (int i = 0; i < N; i++) {
        if (last != word[i]) {
            output << word[i] << "\n";
            last = word[i];
        }
    }

    cout << output.str();
}

bool compare(string a, string b) {
    if (a.length() == b.length()) return a < b;
    return a.length() < b.length();
}