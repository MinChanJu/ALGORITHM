#include <iostream>
#include <sstream>

using namespace std;

double checkHak(string alpha);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    double totalSum;
    double totalScore;
    for (int i = 0; i < 20; i++) {
        string subject;
        double score;
        string alpha;

        cin >> subject >> score >> alpha;
        getline(cin, subject);

        if (alpha == "P") continue;

        totalSum += score;
        totalScore += score*checkHak(alpha);
    }
    
    cout << totalScore/totalSum << "\n";
}

double checkHak(string alpha) {
    if (alpha == "A+") return 4.5;
    if (alpha == "A0") return 4.0;
    if (alpha == "B+") return 3.5;
    if (alpha == "B0") return 3.0;
    if (alpha == "C+") return 2.5;
    if (alpha == "C0") return 2.0;
    if (alpha == "D+") return 1.5;
    if (alpha == "D0") return 1.0;
    return 0.0;
}