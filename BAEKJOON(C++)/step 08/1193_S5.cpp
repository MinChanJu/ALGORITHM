#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int X;
    cin >> X;

    int sum = 0;
    while (sum < X) {
        X -= sum;
        sum++;
    }

    if (sum % 2 == 0) output << X << "/" << sum+1-X << "\n";
    else output << sum+1-X << "/" << X << "\n";

    cout << output.str();
}