#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int A, B;
    cin >> A >> B;

    output << A*B << "\n";
    
    cout << output.str();
}