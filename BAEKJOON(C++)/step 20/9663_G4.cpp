#include <cstdio>
#include <chrono>

namespace fio {
    const short BUFFER_SIZE = 1 << 3;

    char readBuffer[BUFFER_SIZE] {};
    short readIndex = BUFFER_SIZE;

    inline char ReadChar() {
        if (readIndex == BUFFER_SIZE) {
            fread(readBuffer, 1, BUFFER_SIZE, stdin);
            readIndex = 0;
        }
        return readBuffer[readIndex++];
    }

    inline int ReadInt() {
        int sum = 0;
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

    inline void WriteChar(char ch) {
        writeBuffer[writeIndex++] = ch;
        if (writeIndex == BUFFER_SIZE) Flush();
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

    inline void WriteInt(long n) {
        long size = GetSize(n);
        if (n < 0) {
            WriteChar('-');
            n = -n;
        }
        while (size) {
            WriteChar(n/size + 48);
            n %= size;
            size /= 10;
        }
    }
}

using namespace fio;
using namespace std;

inline void back(int index, int a[]);
inline bool check(int idx, int jdx, int a[]);

int N, cnt = 0;

int main() {
    N = ReadInt();

    int a[N];
    for (int i = 0; i < N; i++) a[i] = 0;
    
    back(0, a);

    WriteInt(cnt);
    WriteChar('\n');

    Flush();
}

inline void back(int idx, int a[]) {
    if (idx == N) {
        cnt++;
        return;
    }
    for (int i = 0; i < N; i++) {
        if (check(idx, i, a)) {
            a[idx] = i;
            back(idx+1, a);
        }
    }
}

inline bool check(int idx, int jdx, int a[]) {
    for (int i = 0; i < idx; i++) {
        if (a[i] == jdx) return false;
        if (a[i]-jdx == idx-i) return false;
        if (jdx-a[i] == idx-i) return false;
    }
    return true;
}