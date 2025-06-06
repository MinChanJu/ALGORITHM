#include <iostream>

namespace fio {
    inline void SetInputFile(FILE* file);

    inline char ReadChar();
    inline int ReadInt();
    inline std::string ReadString();

    inline int GetSize(int nWrite);
    inline void Flush();
    inline void WriteChar(char cWrite);
    inline void WriteInt(int nWrite);
    inline void WriteString(std::string strWrite);

    inline void space();
    inline void enter();


    const int BUFFER_SIZE = 1 << 14;

    char readBuffer[BUFFER_SIZE]{};
    int readIndex = BUFFER_SIZE;
    FILE* inputFile = stdin;
    
    char writeBuffer[BUFFER_SIZE]{};
    int writeIndex = 0;


    inline void SetInputFile(FILE* file) {
        inputFile = file;
    }


    inline char ReadChar() {
        if (readIndex == BUFFER_SIZE) {
            fread(readBuffer, 1, BUFFER_SIZE, inputFile);
            readIndex = 0;
        }
        return readBuffer[readIndex++];
    }

    inline int ReadInt() {
        int sum = 0;
        int align = 1;
        char now = ReadChar();

        while (now == 10 || now == 32) now = ReadChar();
        if (now == '-') {
            align = -1;
            now = ReadChar();
        }
        while (48 <= now && now <= 57) {
            sum = sum*10 + now-48;
            now = ReadChar();
        }

        return align*sum;
    }

    inline std::string ReadString() {
        char cRead = ReadChar();
        std::string result;

        while (cRead <= 32) cRead = ReadChar();

        while (cRead >= 33)
        {
            result += cRead;
            cRead = ReadChar();
        }

        return result;
    }


    inline int GetSize(int nWrite) {
        int nSize = 1;

        if (nWrite < 0) nWrite = -nWrite;

        while (nWrite >= 10) {
            nWrite /= 10;
            nSize++;
        }

        return nSize;
    }

    inline void Flush() {
        fwrite(writeBuffer, 1, writeIndex, stdout);
        writeIndex = 0;
    }

    inline void WriteChar(char cWrite) {
        if (writeIndex >= BUFFER_SIZE) Flush();

        writeBuffer[writeIndex++] = cWrite;
    }

    inline void WriteInt(int nWrite) {
        int nSize = GetSize(nWrite);

        if (nSize + writeIndex >= BUFFER_SIZE) Flush();

        if (nWrite < 0) {
            nWrite = -nWrite;
            writeBuffer[writeIndex++] = '-';
        }

        int nNext = nSize + writeIndex;

        while (nSize--) {
            writeBuffer[nSize + writeIndex] = nWrite % 10 + 48;
            nWrite /= 10;
        }

        writeIndex = nNext;
    }

    inline void WriteString(std::string strWrite) {
        int nIndex = 0;
        int nLength = strWrite.length();

        if (writeIndex + nLength + 1 >= BUFFER_SIZE) Flush();

        while (nLength--) writeBuffer[writeIndex++] = strWrite[nIndex++];
    }


    inline void space() {
        WriteChar(' ');
    }

    inline void enter() {
        WriteChar('\n');
    }
}

using namespace fio;
using namespace std;

int main() {
    FILE* file = fopen("../local.txt", "r");
    if (!file) file = stdin;
    SetInputFile(file);

    int max = 1000000;
    bool prime[max];
    for (int i = 0; i < max; i++) prime[i] = 1;
    prime[0] = 0, prime[1] = 0;

    for (int i = 2; i < max; i++) {
        if (prime[i]) {
            for (int j = i+i; j < max; j += i) prime[j] = 0;
        }
    }

    int T = ReadInt();

    while (T--) {
        int n = ReadInt();
        int cnt = 0;
        for (int i = 2; i <= n/2; i++) {
            if (prime[i] && prime[n-i]) cnt++;
        }
        WriteInt(cnt);
        enter();
    }

    Flush();
}