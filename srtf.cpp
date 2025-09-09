#include<iostream>
using namespace std;
int main()
{
    int n,p[10],bt[10],ct[10],wt[10],tt[10],i,at[10],rembt[10],small,time=0,count=0;
    float tawt=0,tatt=0,awt=0,att=0;
    cout<<"Enter the number of processes: ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"Enter the process number: ";
        cin>>p[i];
        cout<<"Enter the burst time: ";
        cin>>bt[i];
        cout<<"Enter the arrival time: ";
        cin>>at[i];
        rembt[i]=bt[i];
    }
    rembt[9]=9999;
    for(time=0;count!=n;time++)
    {
        small=9;
        for(i=0;i<n;i++)
        {
            if(at[i]<=time&&rembt[i]>0&&rembt[i]<rembt[small])
            {
                small=i;
            }
        }
        rembt[small]--;
        if(rembt[small]==0)
        {
            count++;
            ct[small]=time+1;
            wt[small]=ct[small]-bt[small]-at[small];
            tt[small]=ct[small]-at[small]; 
        }
    }

    for(i=0;i<n;i++)
    {
        tawt=tawt+wt[i];
        tatt=tatt+tt[i];
    }
    awt=tawt/n;
    att=tatt/n;
    cout<<"Process\t Burst Time\tArrival Time\tCompletion Time\tWaiting Time\tTurnaround Time\n";
    for(i=0;i<n;i++)
    {
        cout<<"P"<<p[i]<<"\t\t"<<bt[i]<<"\t\t"<<at[i]<<"\t\t"<<ct[i]<<"\t\t"<<wt[i]<<"\t\t"<<tt[i]<<endl;
    }
    cout<<"Average Waiting Time: "<<awt<<endl;
    cout<<"Average Turnaround Time: "<<att<<endl;   
    return 0;

}