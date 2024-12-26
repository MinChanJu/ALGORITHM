#include <iostream>

using namespace std;

int N, K, cnt = 0, num = -1;

void merge_sort(int array[], int s, int e);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    int A[N];
    for (int i = 0; i < N; i++) cin >> A[i];

    merge_sort(A, 0, N-1);
    
    cout << num << "\n";
}

void merge_sort(int array[], int s, int e) {
    if (s == e) return;

    int mid = (s+e)/2;
    merge_sort(array, s, mid);
    merge_sort(array, mid+1, e);

    int sub[e-s+1];
    int idx = 0, i = s, j = mid+1;

    while (i <= mid && j <= e) {
        if (array[i] < array[j]) sub[idx++] = array[i++];
        else sub[idx++] = array[j++];
    }

    while (i <= mid) sub[idx++] = array[i++];
    while (j <= e) sub[idx++] = array[j++];

    for (int i = 0; i <= e-s; i++) {
        array[i+s] = sub[i];
        cnt++;
        if (cnt == K) num = sub[i];
    }
    
}