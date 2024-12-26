#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

inline void canto(int s, int e);

string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int N;

    while (cin >> N) {
        int size = (int) pow(3, N);

        str = "";
        for (int i = 0; i < size; i++) str += "-";

        canto(0, size-1);

        output << str << "\n";
    }

    cout << output.str();
}

inline void canto(int s, int e) {
    if (s == e) return;

    int dx = (e-s+1)/3;
    for (int i = s+dx; i < s+dx+dx; i++) {
        str[i] = ' ';
    }

    canto(s, s+dx-1);
    canto(s+dx+dx, e);
}