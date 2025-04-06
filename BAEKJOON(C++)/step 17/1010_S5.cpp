#include <string>

using namespace std;

namespace fio {
    inline char ReadChar();
    inline long ReadInt();

    inline void Flush();
    inline long GetSize(long nWrite);
    inline void WriteChar(char cWrite);
    inline void WriteInt(long nWrite);


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

        WriteChar('\n');
    }
}

using namespace fio;

int main() {
    int T = ReadInt();

    while (T--) {
        short K = ReadInt();
        short N = ReadInt();
        
        if (N-K < K) K = N-K;

        long mul = 1;
        for (short i = 0; i < K; i++) {
            mul *= N-i;
        }

        for (short i = 2; i <= K; i++) {
            mul /= i;
        }

        WriteInt(mul);
    }
    
    Flush();
}