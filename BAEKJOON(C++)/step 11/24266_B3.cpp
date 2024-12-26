#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    long n;
    cin >> n;
    
    output << n*n*n << "\n3\n";

    cout << output.str();
}