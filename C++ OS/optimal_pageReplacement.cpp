#include <iostream>
#include <cstring>
using namespace std;

int pages[] = {1, 2, 3, 4, 2, 1, 5, 6, 2, 1, 2, 3, 7, 6, 3, 2, 1, 2, 3, 6};
int n = 20;

int optimalPageFaults(int capacity) {
    int frame[10], faults = 0, count = 0;
    memset(frame, -1, sizeof(frame));

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;

        for (int j = 0; j < capacity; j++) {
            if (frame[j] == page) {
                found = 1;
                break;
            }
        }

        if (!found) {
            faults++;
            if (count < capacity) {
                frame[count++] = page;
            } else {
                int farthest = -1, index = -1;
                for (int j = 0; j < capacity; j++) {
                    int k;
                    for (k = i + 1; k < n; k++) {
                        if (frame[j] == pages[k]) break;
                    }
                    if (k > farthest) {
                        farthest = k;
                        index = j;
                    }
                }
                frame[index] = page;
            }
        }
    }
    return faults;
}

int main() {
    for (int frames = 1; frames <= 7; frames++) {
        int faults = optimalPageFaults(frames);
        cout << "Frames: " << frames << ", Optimal Page Faults: " << faults << endl;
    }
    return 0;
}
