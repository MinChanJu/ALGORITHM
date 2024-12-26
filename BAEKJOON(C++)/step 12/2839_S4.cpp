#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int N;
    cin >> N;

    if (N%5 == 0) output << N/5 << "\n";
    else if (N%5 == 1) output << N/5+1 << "\n";
    else if (N%5 == 2 && N > 10) output << N/5+2 << "\n";
    else if (N%5 == 3) output << N/5+1 << "\n";
    else if (N%5 == 4 && N > 5) output << N/5+2 << "\n";
    else output << "-1\n";

    cout << output.str();
}