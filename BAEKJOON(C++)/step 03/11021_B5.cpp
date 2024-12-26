#include <iostream>
#include <sstream>

using namespace std;

int main() {
    int T;
    cin >> T;

    stringstream output;
    
    for (int i = 0; i < T; i++) {
        int A, B;
        cin >> A >> B;
        output << "Case #" << i+1 << ": " << A+B << "\n";
    }

    cout << output.str();
    
    return 0;
}