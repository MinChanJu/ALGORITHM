#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int a, b, c;
    while (true) {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) break;

        int maximum = max(a, max(b, c));
        if (maximum*2 < a+b+c) {
            if (a == b && b == c) output << "Equilateral\n";
            else if (a == b || b == c || a == c) output << "Isosceles\n";
            else output << "Scalene\n";
        } else output << "Invalid\n";
    }

    cout << output.str();
}