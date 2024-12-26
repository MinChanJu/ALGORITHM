#include <iostream>

using namespace std;

string replace(string word, string pattern);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string word;
    cin >> word;

    word = replace(word, "c=");
    word = replace(word, "c-");
    word = replace(word, "dz=");
    word = replace(word, "d-");
    word = replace(word, "lj");
    word = replace(word, "nj");
    word = replace(word, "s=");
    word = replace(word, "z=");
    
    cout << word.length() << "\n";
}

string replace(string word, string pattern) {
    size_t pos;
    while ((pos = word.find(pattern)) != string::npos) {
        word.replace(pos, pattern.length(), ".");
    }
    return word;
}