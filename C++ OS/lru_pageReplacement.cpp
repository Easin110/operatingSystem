#include <iostream>
#include <cstring>
using namespace std;

int pages[] = {1, 2, 3, 4, 2, 1, 5, 6, 2, 1, 2, 3, 7, 6, 3, 2, 1, 2, 3, 6};
int n = 20;

int lruPageFaults(int capacity) {
    int frame[10], time[10], faults = 0, count = 0;
    memset(frame, -1, sizeof(frame));

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;

        for (int j = 0; j < capacity; j++) {
            if (frame[j] == page) {
                found = 1;
                time[j] = i;
                break;
            }
        }

        if (!found) {
            faults++;
            if (count < capacity) {
                frame[count] = page;
                time[count] = i;
                count++;
            } else {
                int lru = 0;
                for (int j = 1; j < capacity; j++) {
                    if (time[j] < time[lru])
                        lru = j;
                }
                frame[lru] = page;
                time[lru] = i;
            }
        }
    }
    return faults;
}

int main() {
    for (int frames = 1; frames <= 7; frames++) {
        int faults = lruPageFaults(frames);
        cout << "Frames: " << frames << ", LRU Page Faults: " << faults << endl;
    }
    return 0;
}

