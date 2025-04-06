#include <cstdio>

namespace fio {
    const short BUFFER_SIZE = 1 << 14;

    char readBuffer[BUFFER_SIZE];
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
            sum = sum * 10 + now - 48;
            now = ReadChar();
        }

        return align ? sum : -sum;
    }

    char writeBuffer[BUFFER_SIZE];
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
            n /= 10;
            size *= 10;
        }

        return size;
    }

    inline void WriteInt(long n) {
        long size = GetSize(n);

        if (n < 0) WriteChar('-');
        while (size) {
            WriteChar(n / size + 48);
            n %= size;
            size /= 10;
        }
    }
}

using namespace fio;

inline void permutation(int k, int i);
inline int countOne(int n);

int N, M;

int main() {
    N = ReadInt();
    M = ReadInt();
    
    permutation(0, 0);
    Flush();
    
    return 0;
}

inline void permutation(int k, int i) {
    int a = countOne(k);
    if (a == M) {
        for (int j = 0; j <  N; j++) {
            if (k & (1 << j)) {
                WriteInt(j+1);
                WriteChar(' ');
            }
        }
        WriteChar('\n');
    } else if (a < M) {
        for (int j = i; j < N; j++) {
            permutation(k | (1 << j) , j+1);
        }
    }
}

inline int countOne(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}