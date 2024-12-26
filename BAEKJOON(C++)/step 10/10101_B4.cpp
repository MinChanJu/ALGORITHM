#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int a, b, c;
    cin >> a >> b >> c;
    
    if (a+b+c == 180) {
        if (a == b && b == c) output << "Equilateral\n";
        else if (a == b || b == c || a == c) output << "Isosceles\n";
        else output << "Scalene\n";
    } else output << "Error\n";

    cout << output.str();
}