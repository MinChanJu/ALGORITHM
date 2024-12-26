#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int a, b, c;
    cin >> a >> b >> c;

    int maximum = max(a, max(b, c));
    int k = min(a+b+c-maximum-1, maximum);

    output << a+b+c+k-maximum << "\n";

    cout << output.str();
}