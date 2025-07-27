#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
    const int SIZE = 7;
    int requests[SIZE] = {12, 34, 52, 14, 25, 68, 39};
    int head = 53;
    int disk_size = 90;
    int total_head_movement = 0;
    int left[SIZE], right[SIZE];
    int leftCount = 0, rightCount = 0;
    for (int i = 0; i < SIZE; i++) {
        if (requests[i] < head)
            left[leftCount++] = requests[i];
        else
            right[rightCount++] = requests[i];
    }
    left[leftCount++] = 0;
    right[rightCount++] = disk_size;
    sort(left, left + leftCount);
    sort(right, right + rightCount);
    cout << "C-SCAN Seek Sequence: " << head;
    for (int i = 0; i < rightCount; i++) {
        total_head_movement += abs(head - right[i]);
        head = right[i];
        cout << " -> " << head;
    }
    total_head_movement += abs(head - 0);
    head = 0;
    for (int i = 0; i < leftCount; i++) {
        total_head_movement += abs(head - left[i]);
        head = left[i];
        cout << " -> " << head;
    }
    cout << "\nTotal Head Movement (C-SCAN): " << total_head_movement << endl;
    return 0;
}
