#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int A, B, V;
    cin >> A >> B >> V;

    if ((V-B)%(A-B) == 0) output << (V-B)/(A-B) << "\n";
    else output << (V-B)/(A-B)+1 << "\n";

    cout << output.str();
}