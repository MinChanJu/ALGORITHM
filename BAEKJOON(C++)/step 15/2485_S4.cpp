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

int gcd(int a, int b);

int main() {
    FILE* file = fopen("../local.txt", "r");
    if (!file) file = stdin;
    SetInputFile(file);

    int N = ReadInt();

    int first, A, B;
    A = ReadInt();
    B = ReadInt();

    int GCD = B-A;
    first = A;
    A = B;

    for (int i = 2; i < N; i++) {
        B = ReadInt();
        GCD = gcd(GCD, B-A);
        A = B;
    }

    WriteInt((B-first)/GCD+1-N);
    enter();

    Flush();

    fclose(file);
}

int gcd(int a, int b) {
    if (a == 0) return b;
    else if (b == 0) return a;
    else if (a > b) return gcd(a%b, b);
    else return gcd(a, b%a);
}