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
        char now = ReadChar();

        while (now <= 32) now = ReadChar();
        while (48 <= now && now <= 57) {
            sum = sum*10 + now-48;
            now = ReadChar();
        }

        return sum;
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

        WriteChar('\n');
    }
}

using namespace fio;

int data[2000000];
int s = 1000000, e = 1000000;

int main() {
    int N = ReadInt();

    while (N--) {
        int t = ReadInt();
        if (t == 1) data[--s] = ReadInt();
        else if (t == 2) data[e++] = ReadInt();
        else if (t == 3) WriteInt(s == e ? -1 : data[s++]);
        else if (t == 4) WriteInt(s == e ? -1 : data[--e]);
        else if (t == 5) WriteInt(s == e ?  0 : e - s);
        else if (t == 6) WriteInt(s == e ?  1 : 0);
        else if (t == 7) WriteInt(s == e ? -1 : data[s]);
        else if (t == 8) WriteInt(s == e ? -1 : data[e-1]);
    }
    
    Flush();
}