#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    int x, y;
    x = (c*e-f*b)/(a*e-d*b);
    if (b != 0) y = (c-a*x)/b;
    else y = (f-d*x)/e;

    output << x << " " << y << "\n";

    cout << output.str();
    
}