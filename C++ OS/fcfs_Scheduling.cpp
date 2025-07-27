#include<iostream>
#include<algorithm>
using namespace std;
int main()
{   int n,bt[10],wt[10],tat[10],avwt=0,avtat=0,twt=0,i,j;
    cout<<"Enter total number processes:";
    cin>>n;

    cout<<"\nEnter Process Burst \n";
    for(i=0;i<n;i++)
    {
        cout<<"P["<<i+1<<"]:";
        cin>>bt[i];
    }
    sort(bt,bt+n);//change for SJF
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }
    cout<<"\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";

    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];

        cout<<"\nP["<<i+1<<"]"<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i];
    }
    avwt/=i;
    avtat/=i;
    cout<<"\n\nTotal waiting Time:"<<avwt*n;
    cout<<"\n\nAverage Waiting Time:"<<avwt;
    cout<<"\n\nAverage Turnaround Time:"<<avtat<<endl;


    return 0;
}

