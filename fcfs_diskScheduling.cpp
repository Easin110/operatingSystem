#include <iostream>
#include <cmath>
using namespace std;

int main() {
    const int SIZE = 8;
    int requests[SIZE] = {98, 183, 37, 122, 14, 124, 65, 67};
    int head = 53;
    int total_seek_time = 0;

    cout << "Initial Head Position: " << head << endl;
    cout << "Seek Sequence: " << head;

    for (int i = 0; i < SIZE; i++) {
        total_seek_time += abs(head - requests[i]);
        head = requests[i];
        cout << " -> " << head;
    }

    cout << "\nTotal Seek Time: " << total_seek_time << endl;
    cout << "Average Seek Time: " << (float)total_seek_time / SIZE << endl;

    return 0;
}

