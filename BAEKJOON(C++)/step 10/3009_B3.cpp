#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    if (x1 == x2) {
        if (y1 == y3) output << x3 << " " << y2 << "\n";
        else output << x3 << " " << y1 << "\n";
    } else if (x1 == x3) {
        if (y1 == y2) output << x2 << " " << y3 << "\n";
        else output << x2 << " " << y1 << "\n";
    } else {
        if (y1 == y2) output << x1 << " " << y3 << "\n";
        else output << x1 << " " << y2 << "\n";
    }
    
    cout << output.str();
}