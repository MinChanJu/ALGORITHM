#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long N;
    int B;
    cin >> N >> B;

    stringstream output;

    int trans = 0;
    while (N != 0) {
        if (N%B >= 10) output << (char) (N%B+55);
        else output << N%B;
        N /= B;
    }
    string str = output.str();
    reverse(str.begin(), str.end());

    cout << str << "\n";
}