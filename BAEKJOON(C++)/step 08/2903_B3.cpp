#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int N;
    cin >> N;

    N = pow(2,N);
    output << (N+1)*(N+1) << "\n";

    cout << output.str();
}