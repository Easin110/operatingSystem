#include <iostream>
using namespace std;

const int P = 5;
const int R = 3;

void printMatrix(int matrix[P][R], const string& title) {
    cout << "\n" << title << ":\n";
    for (int i = 0; i < P; i++) {
        cout << "P" << i << ": ";
        for (int j = 0; j < R; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int Allocation[P][R], int Need[P][R], int Available[R]) {
    bool finish[P] = {false};
    int work[R];
    int safeSeq[P];

    for (int i = 0; i < R; i++) work[i] = Available[i];

    int count = 0;
    while (count < P) {
        bool found = false;
        for (int i = 0; i < P; i++) {
            if (!finish[i]) {
                bool canRun = true;
                for (int j = 0; j < R; j++) {
                    if (Need[i][j] > work[j]) {
                        canRun = false;
                        break;
                    }
                }
                if (canRun) {
                    for (int k = 0; k < R; k++)
                        work[k] += Allocation[i][k];
                    safeSeq[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if (!found) return false;
    }

    cout << "\nSystem is in a safe state.\nSafe Sequence: ";
    for (int i = 0; i < P; i++) {
        cout << "P" << safeSeq[i] << " ";
    }
    cout << endl;
    return true;
}

int main() {
    int Allocation[P][R] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    int Max[P][R] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

    int Available[R] = {3, 3, 2};
    int Need[P][R];

    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            Need[i][j] = Max[i][j] - Allocation[i][j];

    printMatrix(Need, "Need Matrix");

    if (!isSafe(Allocation, Need, Available)) {
        cout << "System is NOT in a safe state.\n";
    }

    int Request[R] = {1, 0, 2};
    int process = 1;

    cout << "\nCheck Request (1,0,2) from P1...\n";
    bool canGrant = true;

    for (int i = 0; i < R; i++) {
        if (Request[i] > Need[process][i]) {
            cout << "Error: Request exceeds P1's maximum need.\n";
            canGrant = false;
            break;
        }
        if (Request[i] > Available[i]) {
            cout << "Resources not available. P1 must wait.\n";
            canGrant = false;
            break;
        }
    }

    if (canGrant) {
        int tempAvailable[R], tempAllocation[P][R], tempNeed[P][R];

        for (int i = 0; i < R; i++)
            tempAvailable[i] = Available[i] - Request[i];

        for (int i = 0; i < P; i++)
            for (int j = 0; j < R; j++) {
                tempAllocation[i][j] = Allocation[i][j];
                tempNeed[i][j] = Need[i][j];
            }

        for (int i = 0; i < R; i++) {
            tempAllocation[process][i] += Request[i];
            tempNeed[process][i] -= Request[i];
        }

        if (isSafe(tempAllocation, tempNeed, tempAvailable)) {
            cout << " Request CAN be granted immediately.\n";
        } else {
            cout <<  "Request cannot  be granted. unsafe state.\n";
        }
    }

    return 0;
}

