#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int n;
    cin >> n;
    
    output << n << "\n1\n";

    cout << output.str();
}