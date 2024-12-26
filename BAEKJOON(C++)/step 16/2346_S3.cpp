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

struct  Node {
    Node *previous, *next;
    int value;
    int index;
};

Node *front = nullptr, *back = nullptr;
int nodeSize = 0;

Node* makeNode(int index, int value) {
    Node* tmp = new Node();
    tmp->index = index;
    tmp->value = value;
    tmp->previous = nullptr;
    tmp->next = nullptr;
    return tmp;
}

void push_front(int index, int value) {
    Node* tmp = makeNode(index, value);
    if (back == nullptr) back = tmp;
    else {
        front->previous = tmp;
        tmp->next = front;
    }
    front = tmp;
    nodeSize++;
}

void push_back(int index, int value) {
    Node* tmp = makeNode(index, value);
    if (front == nullptr) front = tmp;
    else {
        back->next = tmp;
        tmp->previous = back;
    }
    back = tmp;
    nodeSize++;
}

Node* pop_front() {
    Node* tmp = front;

    front = front->next;
    if (front != nullptr) front->previous = nullptr;
    else back = nullptr;

    return tmp;
}

Node* pop_back() {
    Node* tmp = back;

    back = back->previous;
    if (back != nullptr) back->next = nullptr;
    else front = nullptr;

    return tmp;
}

int main() {
    FILE* file = fopen("../input.txt", "r");
    if (!file) file = stdin;
    SetReadFile(file);

    int N = ReadInt();

    for (int i = 0; i < N; i++) push_back(i+1, ReadInt());
    
    while (N--) {
        Node* data = pop_front();
        WriteInt(data->index);

        if (front != nullptr){
            if (data->value < 0) {
                for (int i = 0; i < -data->value; i++) {
                    Node* tmp = pop_back();
                    push_front(tmp->index, tmp->value);
                    delete tmp;
                }
            } else {
                for (int i = 1; i < data->value; i++) {
                    Node* tmp = pop_front();
                    push_back(tmp->index, tmp->value);
                    delete tmp;
                }
            }
        }

        delete data;
    }

    WriteChar('\n');
    
    Flush();
}