#include <iostream>
#include <cstring>
using namespace std;

int pages[] = {1, 2, 3, 4, 2, 1, 5, 6, 2, 1, 2, 3, 7, 6, 3, 2, 1, 2, 3, 6};
int n = 20;

int fifoPageFaults(int capacity) {
    int frame[10], front = 0, rear = 0, size = 0, faults = 0;
    bool inFrame[100] = {false};
    for (int i = 0; i < n; i++) {
        int page = pages[i];
        if (!inFrame[page]) {
            faults++;
            if (size == capacity) {
                inFrame[frame[front]] = false;
                front = (front + 1) % capacity;
                size--;
            }
            frame[rear] = page;
            inFrame[page] = true;
            rear = (rear + 1) % capacity;
            size++;
        }
    }
    return faults;
}
int main() {
    cout<<"FIFO Page Replacement:\n";
    cout << "Frame No.       No.of Faults\n";
    for (int frames = 3; frames <= 7; frames++) {
        int faults = fifoPageFaults(frames);

        cout << frames << "\t\t" << faults << endl;
    }
    return 0;
}

