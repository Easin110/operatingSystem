
#include<iostream>
using namespace std;

int main()
{
    int n = 5;
    int p[5] = {1, 2, 3, 4, 5};
    int bt[5] = {10, 1, 2, 1, 5};          // Burst times
    int priority[5] = {3, 1, 4, 5, 2};     // Priorities
    int wt[5], tat[5];
    int avwt = 0, avtat = 0;

    // Sort based on priority
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(priority[i] > priority[j]) {
                swap(priority[i], priority[j]);
                swap(bt[i], bt[j]);
                swap(p[i], p[j]);
            }
        }
    }

    wt[0] = 0;
    for(int i = 1; i < n; i++) {
        wt[i] = 0;
        for(int j = 0; j < i; j++)
            wt[i] += bt[j];
    }

    cout << "Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n";
    for(int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        avwt += wt[i];
        avtat += tat[i];
        cout << "P[" << p[i] << "]\t" << bt[i] << "\t\t" << priority[i]
             << "\t\t" << wt[i] << "\t\t" << tat[i] << "\n";
    }

    cout << "\nAverage Waiting Time: " << (float)avwt / n;
    cout << "\nAverage Turnaround Time: " << (float)avtat / n;

    return 0;
}
