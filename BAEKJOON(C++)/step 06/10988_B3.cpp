#include <iostream>

using namespace std;

bool isPalindrome(string word);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string word;
    cin >> word;
    
    if (isPalindrome(word)) cout << 1 << "\n";
    else cout << 0 << "\n";
}

bool isPalindrome(string word) {
    int N = word.length();
    for (int i = 0; i < N/2; i++) {
        if (word[i] != word[N-i-1]) return false;
    }
    return true;
}