#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int x, y, w, h;
    cin >> x >> y >> w >> h;

    if (w - x < x) {
        if (h-y < y) {
            if (h-y < w-x) output << h-y << "\n";
            else output << w-x << "\n";
        } else {
            if (y < w-x) output << y << "\n";
            else output << w-x << "\n";
        }
    } else {
        if (h-y < y) {
            if (h-y < x) output << h-y << "\n";
            else output << x << "\n";
        } else {
            if (y < x) output << y << "\n";
            else output << x << "\n";
        }
    }
    
    cout << output.str();
}