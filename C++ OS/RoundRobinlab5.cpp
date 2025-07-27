#include<iostream>
using namespace std;

int main()
{
    int n = 3;
    int p[3] = {1, 2, 3};
    int bt[3] = {24, 13, 9};  // Burst times
    int rt[3], wt[3] = {0}, tat[3];
    int tq = 4;               // Time quantum
    int t = 0;
    float avwt = 0, avtat = 0;

    for(int i = 0; i < n; i++)
        rt[i] = bt[i];

    bool done;
    do {
        done = true;
        for(int i = 0; i < n; i++) {
            if(rt[i] > 0) {
                done = false;
                if(rt[i] > tq) {
                    t += tq;
                    rt[i] -= tq;
                } else {
                    t += rt[i];
                    wt[i] = t - bt[i];
                    rt[i] = 0;
                }
            }
        }
    } while(!done);

    for(int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        avwt += wt[i];
        avtat += tat[i];
    }

    cout << "Process\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for(int i = 0; i < n; i++) {
        cout << "P[" << p[i] << "]\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << "\n";
    }

    cout << "\nAverage Waiting Time: " << avwt / n;
    cout << "\nAverage Turnaround Time: " << avtat / n;

    return 0;
}

