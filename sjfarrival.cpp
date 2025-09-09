#include<iostream>
using namespace std;
int main()
{
    int n, p[10], bt[10], at[10], ct[10], wt[10], tt[10], i;
    float tawt=0, tatt=0, awt=0, att=0;
    bool done[10] = {false};
    int completed = 0, time = 0;

    cout << "Enter the number of processes: ";
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cout << "Enter the process number: ";
        cin >> p[i];
        cout << "Enter the arrival time: ";
        cin >> at[i];
        cout << "Enter the burst time: ";
        cin >> bt[i];
    }

    // Simple SJF (non-preemptive) with arrival time
    int completed = 0, time = 0;
    while(completed < n) {
        int idx = -1;
        for(i = 0; i < n; i++) {
            if(!done[i] && at[i] <= time) {
                if(idx == -1 || bt[i] < bt[idx]) idx = i;
            }
        }
        if(idx == -1) {
            time++;
            continue;
        }
        wt[idx] = time - at[idx];
        if(wt[idx] < 0) wt[idx] = 0;
        ct[idx] = time + bt[idx];
        tt[idx] = ct[idx] - at[idx];
        time = ct[idx];
        done[idx] = true;
        completed++;
    }

    for(i = 0; i < n; i++)
    {
        tawt = tawt + wt[i];
        tatt = tatt + tt[i];
    }
    awt = tawt / n;
    att = tatt / n;
    cout << "Process\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n";
    for(i = 0; i < n; i++)
    {
        cout << "P" << p[i] << "\t\t" << at[i] << "\t\t" << bt[i] << "\t\t" << ct[i] << "\t\t" << wt[i] << "\t\t" << tt[i] << endl;
    }
    cout << "Average Waiting Time: " << awt << endl;
    cout << "Average Turnaround Time: " << att << endl;   
    return 0;
}
