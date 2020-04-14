#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);

    int i, smallestIndex, processCompleted = 0, time, n;
    float awt = 0, atat = 0;
    cout << "Enter the Number of Processes: ";
    cin >> n;
    int p[n], a_t[n], bt[n + 1], temp[n], wt[n], tat[n], completion[n];
    for(i = 0; i < n; i++)
    {
        p[i] = i + 1;
        cout << "Enter Burst Time and Arrival Time for Process " << i+1 << ": ";
        cin >> bt[i] >> a_t[i];
        temp[i] = bt[i];
    }
    bt[n] = 9999;

    for(time = 0; processCompleted < n; time++)
    {

        smallestIndex = n;
        for(i = 0; i < n; i++)
        {
            if(a_t[i] <= time && bt[i] < bt[smallestIndex] && bt[i] > 0)
            {
                smallestIndex = i;
            }
        }
        bt[smallestIndex] = bt[smallestIndex] -1;

        if(bt[smallestIndex] == 0)
        {
            processCompleted++;
            completion[smallestIndex] = time + 1;

            tat[smallestIndex] = completion[smallestIndex] - a_t[smallestIndex];
            wt[smallestIndex] = tat[smallestIndex] - temp[smallestIndex];

            awt = awt + wt[smallestIndex];
            atat = atat + tat[smallestIndex];
        }
    }

    cout << "\nProcess" << "\t\tArrival Time" << "\tBurst Time" << "\tCompletion Time" << "\t\tTurn Around Time" <<
         "\tWaiting Time" << endl;

    for(i = 0; i < n; i++)
    {
        cout << p[i] << "\t\t" << a_t[i] << "\t\t" << temp[i] << "\t\t" << completion[i] << "\t\t\t" << tat[i] << "\t\t\t" << wt[i] << endl;
    }

    cout << fixed << setprecision(2) << "\nAverage Waiting Time: " << awt/n << endl;
    cout << fixed << setprecision(2) << "Average Turnaround Time: " << atat/n << endl;

    return 0;
}

