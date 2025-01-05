#include <cstdio>
#define max(a, b) (a > b ? a : b)

namespace fio {
    const short BUFFER_SIZE = 1 << 14;

    char readBuffer[BUFFER_SIZE]{};
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

    char writeBuffer[BUFFER_SIZE]{};
    short writeIndex = 0;

    inline void Flush() {
        fwrite(writeBuffer, 1, writeIndex, stdout);
        writeIndex = 0;
    }

    inline long GetSize(long nWrite) {
        long nSize = 1;

        if (nWrite < 0) nWrite = -nWrite;

        while (nWrite >= 10) {
            nWrite /= 10;
            nSize *= 10;
        }

        return nSize;
    }

    inline void WriteChar(char cWrite) {
        if (writeIndex >= BUFFER_SIZE) Flush();
        writeBuffer[writeIndex++] = cWrite;
    }

    inline void WriteInt(long nWrite) {
        long nSize = GetSize(nWrite);

        if (nWrite < 0) {
            if (writeIndex >= BUFFER_SIZE) Flush();
            writeBuffer[writeIndex++] = '-';
            nWrite = -nWrite;
        }

        while (nSize != 0) {
            if (writeIndex >= BUFFER_SIZE) Flush();
            writeBuffer[writeIndex++] = nWrite / nSize + 48;
            nWrite %= nSize;
            nSize /= 10;
        }
    }
}

using namespace fio;

int main() {
    int N = ReadInt();

    int stair[N];
    for (int i = 0; i < N; i++) stair[i] = ReadInt();

    int dp[N+1];
    dp[0] = 0; dp[1] = stair[0];
    if (N > 1) dp[2] = stair[0]+stair[1];
    for (int i = 3; i <= N; i++) dp[i] = max(dp[i-2], dp[i-3]+stair[i-2]) + stair[i-1];
    
    WriteInt(dp[N]);
    WriteChar('\n');

    Flush();
}