#include <iostream>
#include <sstream>

using namespace std;

int isPalindrome(const string& s);
int recursion(const string& s, int l, int r);

int cnt = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int T;
    cin >> T;

    while (T--) {
        string str;
        cin >> str;

        output << isPalindrome(str) << " " << cnt << "\n";
        cnt = 0;
    }

    cout << output.str();
}

int isPalindrome(const string& str) {
    return recursion(str, 0, str.size() - 1);
}

int recursion(const string& str, int l, int r) {
    cnt++;
    if (l >= r) return 1;
    else if (str[l] != str[r]) return 0;
    else return recursion(str, l + 1, r - 1);
}