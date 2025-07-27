#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int main() {
    const int SIZE = 8;
    int requests[SIZE] = {98, 183, 37, 122, 14, 124, 65, 67};
    bool visited[SIZE] = {false};

    int head = 53;
    int total_seek_time = 0;

    cout << "Initial Head Position: " << head << endl;
    cout << "Seek Sequence: " << head;

    for (int i = 0; i < SIZE; ++i) {
        int min_distance = INT_MAX;
        int index = -1;

        for (int j = 0; j < SIZE; ++j) {
            if (!visited[j]) {
                int distance = abs(head - requests[j]);
                if (distance < min_distance) {
                    min_distance = distance;
                    index = j;
                }
            }
        }
        visited[index] = true;
        total_seek_time += abs(head - requests[index]);
        head = requests[index];

        cout << " -> " << head;
    }

    cout << "\nTotal Seek Time: " << total_seek_time << endl;
    cout << "Average Seek Time: " << (float)total_seek_time / SIZE << endl;

    return 0;
}

