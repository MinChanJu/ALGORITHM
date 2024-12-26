#include <iostream>
#include <cmath>
#include <map>

using namespace std;

namespace fio {
    const short BUFFER_SIZE = 1 << 14;

    char readBuffer[BUFFER_SIZE] {};
    short readIndex = BUFFER_SIZE;

    inline char ReadChar() {
        if (readIndex == BUFFER_SIZE) {
            fread(readBuffer, 1, BUFFER_SIZE, stdin);
            readIndex = 0;
        }
        return readBuffer[readIndex++];
    }

    inline long ReadInt() {
        long sum = 0;
        bool align = true;

        char now = ReadChar();
        while (now <= 32) now = ReadChar();
        if (now == '-') {
            align = false;
            now = ReadChar();
        }
        while (48 <= now && now <= 57) {
            sum = sum*10 + now-48;
            now = ReadChar();
        }

        return align ? sum : -sum;
    }

    char writeBuffer[BUFFER_SIZE] {};
    short writeIndex = 0;

    inline void Flush() {
        fwrite(writeBuffer, 1, writeIndex, stdout);
        writeIndex = 0;
    }

    inline long GetSize(long n) {
        long size = 1;

        if (n < 0) n = -n;
        while (n >= 10) {
            size *= 10;
            n /= 10;
        }

        return size;
    }

    inline void WriteChar(char ch) {
        writeBuffer[writeIndex++] = ch;
        if (writeIndex >= BUFFER_SIZE) Flush();
    }

    inline void WriteInt(long n) {
        long size = GetSize(n);
        if (n < 0) {
            writeBuffer[writeIndex++] = '-';
            if (writeIndex >= BUFFER_SIZE) Flush();
            n = -n;
        }

        while (size) {
            writeBuffer[writeIndex++] = n/size + 48;
            if (writeIndex >= BUFFER_SIZE) Flush();
            n %= size;
            size /= 10;
        }

        WriteChar('\n');
    } 
}

using namespace fio;

inline void merge_sort(int array[], int s, int e);

int main() {
    int N = ReadInt();

    int num[N];
    double sum = 0;
    int min = 4000, max = -4000;
    map<int, int> count;

    for (int i = 0; i < N; i++) {
        num[i] = ReadInt();
        sum += num[i];
        count[num[i]]++;
        if (min > num[i]) min = num[i];
        if (max < num[i]) max = num[i];
    }

    merge_sort(num, 0, N-1);

    int many = -1, idx = 0, check = 1;
    for (int i = 0; i < N; i++) {
        if (count[num[i]] > many) {
            many = count[num[i]];
            idx = i;
            check = 1;
        } else if (count[num[i]] == many && check == 1 && num[i] != num[idx]) {
            check = 0;
            idx = i;
        }
    }

    WriteInt((int) round(sum/N));
    WriteInt(num[N/2]);
    WriteInt(num[idx]);
    WriteInt(max-min);
    
    Flush();
}

inline void merge_sort(int array[], int s, int e) {
    if (s == e) return;

    int mid = (s+e)/2;
    merge_sort(array, s, mid);
    merge_sort(array, mid+1, e);

    int sub[e-s+1];
    int i = s, j = mid+1, idx = 0;

    while (i <= mid && j <= e) {
        if (array[i] < array[j]) sub[idx++] = array[i++];
        else sub[idx++] = array[j++];
    }

    while (i <= mid) sub[idx++] = array[i++];
    while (j <= e) sub[idx++] = array[j++];

    for (int i = 0; i <= e-s; i++) {
        array[i+s] = sub[i];
    }
    
}