#include <cstdio>

namespace fio {
    const short BUFFER_SIZE = 1 << 3;

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
    }
}

using namespace fio;
using namespace std;

struct  Node {
    Node *previous, *next;
    int data;
};

Node *front = nullptr, *back = nullptr;

Node* makeNode(int x) {
    Node* tmp = new Node();
    tmp->data = x;
    tmp->previous = nullptr;
    tmp->next = nullptr;
    return tmp;
}

void push(int x) {
    Node* tmp = makeNode(x);
    if (front == nullptr) front = tmp;
    else {
        back->next = tmp;
        tmp->previous = back;
    }
    back = tmp;
}

int pop() {
    Node* tmp = front;
    front = front->next;
    if (front != nullptr) front->previous = nullptr;
    else back = nullptr;
    int k = tmp->data; 
    delete tmp;
    return k;
}


int main() {
    short N = ReadInt();
    short K = ReadInt();

    for (int i = 0; i < N; i++) push(i+1);

    WriteChar('<');
    while (front != back) {
        for (int i = 1; i < K; i++) push(pop());
        WriteInt(pop());
        WriteChar(',');
        WriteChar(' ');
    }
    WriteInt(pop());
    WriteChar('>');
    WriteChar('\n');
    Flush();
}