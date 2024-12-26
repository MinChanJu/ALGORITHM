#include <iostream>
#include <sstream>

#define MAX 10000000
#define MAX_Len 20000001

using namespace std;

int card[MAX_Len];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int N, M, x;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x;
        card[x+MAX]++;
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> x;
        output << card[x+MAX] << " ";
    }

    output << "\n";

    cout << output.str();
}