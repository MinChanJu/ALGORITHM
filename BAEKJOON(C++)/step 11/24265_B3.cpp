#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    long n;
    cin >> n;
    
    output << (n*(n-1))/2 << "\n2\n";

    cout << output.str();
}