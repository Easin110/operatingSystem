#include<iostream>
using namespace std;

int main() {
    int n = 4;
    int at[] = {0, 1, 2, 3};
    int bt[] = {8, 4, 9, 5};
    int rt[4], ct[4], wt[4], tat[4];
    int complete = 0, t = 0, minm = 1e9;
    int shortest = 0;
    bool check = false;

    for (int i = 0; i < n; i++)
        rt[i] = bt[i];

    while (complete != n) {
        minm = 1e9;
        check = false;

        for (int j = 0; j < n; j++) {
            if ((at[j] <= t) && (rt[j] < minm) && rt[j] > 0) {
                minm = rt[j];
                shortest = j;
                check = true;
            }
        }

        if (!check) {
            t++;
            continue;
        }

        rt[shortest]--;

        if (rt[shortest] == 0) {
            complete++;
            int finish_time = t + 1;
            ct[shortest] = finish_time;
            wt[shortest] = finish_time - bt[shortest] - at[shortest];
            if (wt[shortest] < 0) wt[shortest] = 0;
        }
        t++;
    }

    int total_wt = 0, total_tat = 0;

    cout << "\nProcess\tArrival\tBurst\tWaiting\tTurnaround";
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        total_wt += wt[i];
        total_tat += tat[i];
        cout << "\nP[" << i+1 << "]\t" << at[i] << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i];
    }

    cout << "\n\nTotal Waiting Time = " << total_wt;
    cout << "\nTotal Turnaround Time = " << total_tat;
    cout << "\nAverage Waiting Time = " << (float)total_wt / n;
    cout << "\nAverage Turnaround Time = " << (float)total_tat / n << endl;

    return 0;
}
