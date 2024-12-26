#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_set>

using namespace std;

unordered_set<int> unionSets(unordered_set<int> set1, unordered_set<int> set2);
unordered_set<int> diffrenceSets(unordered_set<int> set1, unordered_set<int> set2);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream output;

    int N, M, x;
    cin >> N >> M;

    unordered_set<int> A;
    for (int i = 0; i < N; i++) {
        cin >> x;
        A.insert(x);
    }
    
    unordered_set<int> B;
    for (int i = 0; i < M; i++) {
        cin >> x;
        B.insert(x);
    }

    unordered_set<int> AmB = diffrenceSets(A, B);
    unordered_set<int> BmA = diffrenceSets(B, A);
    unordered_set<int> result = unionSets(AmB, BmA);

    output << result.size() << "\n";
    
    cout << output.str();
}

unordered_set<int> unionSets(unordered_set<int> set1, unordered_set<int> set2) {
    unordered_set<int> result = set1;
    for (int item : set2) result.insert(item);
    return result;
}

unordered_set<int> diffrenceSets(unordered_set<int> set1, unordered_set<int> set2) {
    unordered_set<int> result;
    for (int item : set1) {
        if (set2.find(item) == set1.end()) { // set2에 없는 경우
            result.insert(item);
        }
    }
    return result;
}