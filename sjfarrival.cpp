#include<iostream>
using namespace std;

int main()
{
    int n, p[10], bt[10], at[10], ct[10], wt[10], tt[10], i, j, completed = 0, time = 0, min_bt, idx;
    float tawt = 0, tatt = 0, awt = 0, att = 0;
    bool done[10] = {false};

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

    // SJF with Arrival Time (Non-preemptive)
    while(completed < n)
    {
        min_bt = 1e9;
        idx = -1;
        for(i = 0; i < n; i++)
        {
            if(!done[i] && at[i] <= time && bt[i] < min_bt)
            {
                min_bt = bt[i];
                idx = i;
            }
        }
        if(idx == -1)
        {
            time++;
            continue;
        }
        ct[idx] = time + bt[idx];
        wt[idx] = time - at[idx];
        tt[idx] = wt[idx] + bt[idx];
        time = ct[idx];
        done[idx] = true;
        completed++;
    }

    for(i = 0; i < n; i++)
    {
        tawt += wt[i];
        tatt += tt[i];
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
