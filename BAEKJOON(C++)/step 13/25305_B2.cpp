#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int N, K;
    cin >> N >> K;
    
    int score[N];
    for (int i = 0; i < N; i++) cin >> score[i];

    sort(score, score+N);
    
    output << score[N-K] << "\n";

    cout << output.str();
}