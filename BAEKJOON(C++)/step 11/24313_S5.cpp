#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int a1, a2, c, n0;
    cin >> a1 >> a2 >> c >> n0;

    if (a1 > c) output << "0\n";
    else if (a1*n0+a2 <= c*n0) output << "1\n";
    else output << "0\n";
    
    cout << output.str();
}