#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);

    int n, complete=0,minm=0,c=0;
    cout << "Enter the Number of Processes: ";
    cin >> n;

    int p[n], bt[n], a_t[n], ct[n], tat[n], wt[n], abt[n+1];
    float avgwt = 0, avgtat = 0;

    for(int i = 0; i < n; i++)
    {
        p[i] = i + 1;
        cout << "Enter Arrival Time and Burst Time for Process " << i+1 << ": ";
        cin >> a_t[i] >> bt[i];
    }
    abt[n] = 9999;
    for(int i=0;i<n;i++)
    {
        complete += bt[i];
        abt[i] = bt[i];
    }
    while(c != n)
    {
        for(int t = 0; t < complete; t++)
        {
            minm = n;
            for(int i = 0; i < n; i++)
            {
                if(a_t[i] <= t && abt[i] < abt[minm] && abt[i] != 0)
                    minm = i;
            }
            abt[minm]--;

            if(abt[minm] == 0)
            {
                c++;
                ct[minm] = t+1;

            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - a_t[i];
        wt[i] = tat[i] - bt[i];
        avgwt += wt[i];
        avgtat += tat[i];
    }
    cout << "\nProcess" << "\t\tArrival Time" << "\tBurst Time" << "\tCompletion Time" << "\t\tTurn Around Time" <<
         "\tWaiting Time" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << p[i] << "\t\t" << a_t[i] << "\t\t" << bt[i] << "\t\t" << ct[i] << "\t\t\t" << tat[i] <<
             "\t\t\t" << wt[i] << endl;
    }
    cout << fixed << setprecision(2) << "\nAverage Waiting Time: " << avgwt/n << endl;
    cout << fixed << setprecision(2) << "Average Turnaround Time: " << avgtat/n << endl;

    return 0;
}

