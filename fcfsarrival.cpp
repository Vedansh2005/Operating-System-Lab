#include<iostream>
using namespace std;
int main()
{
    int n,p[10],bt[10],ct[10],wt[10],tt[10],i,at[10];
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
    }
    for(i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(at[i] > at[j])
            {
                int temp1,temp2,temp3;
               temp1=at[i];
               at[i]=at[j];
               at[j]=temp1; 
                
               temp2=p[i];
               p[i]=p[j];
               p[j]=temp2;
                
               
               temp3=bt[i];
               bt[i]=bt[j];
               bt[j]=temp3;
            }
        }
    }
    ct[0]=bt[0];
    for(i=1;i<n;i++)
    {
        ct[i]=ct[i-1]+bt[i];
    }
    for(i=0;i<n;i++)
    {
        wt[i]=ct[i]-bt[i]-at[i];
        tt[i]=wt[i]+bt[i];

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