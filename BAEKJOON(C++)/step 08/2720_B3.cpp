#include <iostream>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int T;
    cin >> T;
    
    for (int _ = 0; _ < T; _++) {
        int coin;
        cin >> coin;

        output << coin / 25 << " ";
        coin %= 25;

        output << coin / 10 << " ";
        coin %= 10;

        output << coin / 5 << " " << coin % 5 << "\n";
    }

    cout << output.str();
}