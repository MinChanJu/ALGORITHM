#include <cstdio>

namespace fio {
    const short BUFFER_SIZE = 1 << 14;

    char readBuffer[BUFFER_SIZE];
    short readIndex = BUFFER_SIZE;
    FILE* readFile = stdin;

    inline void SetReadFile(FILE* file) {
        readFile = file;
    }

    inline char ReadChar() {
        if (readIndex == BUFFER_SIZE) {
            fread(readBuffer, 1, BUFFER_SIZE, readFile);
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

    char writeBuffer[BUFFER_SIZE];
    short writeIndex = 0;

    inline void Flush() {
        fwrite(writeBuffer, 1, writeIndex, stdout);
        writeIndex = 0;
    }

    inline int GetSize(int nWrite) {
        int nSize = 1;

        if (nWrite < 0) nWrite = -nWrite;
        
        while (nWrite >= 10) {
            nSize *= 10;
            nWrite /= 10;
        }

        return nSize;
    }

    inline void WriteChar(char ch) {
        if (writeIndex >= BUFFER_SIZE) Flush();
        writeBuffer[writeIndex++] = ch;
    }

    inline void WriteInt(int nWrite) {
        int nSize = GetSize(nWrite);

        if (nWrite < 0) {
            if (writeIndex >= BUFFER_SIZE) Flush();
            writeBuffer[writeIndex++] = '-';
            nWrite = -nWrite;
        }

        while (nSize != 0) {
            if (writeIndex >= BUFFER_SIZE) Flush();
            writeBuffer[writeIndex++] = nWrite/nSize + 48;
            nWrite %= nSize;
            nSize /= 10;
        }

        WriteChar(' ');
    }
}

using namespace fio;

int main() {
    FILE* file = fopen("../input.txt", "r");
    if (!file) file = stdin;
    SetReadFile(file);

    int N = ReadInt();
    bool A[N];
    int B[N];
    for (int i = 0; i < N; i++) A[i] = ReadInt();
    for (int i = 0; i < N; i++) B[i] = ReadInt();

    int M = ReadInt();
    int t = M;
    
    for (int i = N-1; i >= 0; i--) {
        if (!A[i] && M > 0) {
            WriteInt(B[i]);
            M--;
        }
    }

    for (int i = 0; i < M; i++) {
        WriteInt(ReadInt());
    }
    
    for (int i = M; i < t; i++) {
        ReadInt();
    }
    
    
    WriteChar('\n');
    
    Flush();
}