#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);

    int n;
    cout << "Enter the Number of Processes: ";
    cin >> n;
    int p[n], bt[n], wt[n], tat[n];
    float wtavg, tatavg;
    for(int i = 0; i < n; i++)
    {
        p[i] = i+1;
        cout << "\nEnter Burst Time for Process " << i+1 << ": ";
        cin >> bt[i];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(bt[i] > bt[j])
            {
                swap(bt[i], bt[j]);
                swap(p[i], p[j]);
            }
        }
    }
    wt[0] = wtavg = 0;
    tat[0] = tatavg = bt[0];

    for(int i = 1; i < n; i++)
    {
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = tat[i-1] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }
    cout << "\n\tPROCESS\t\tBURST TIME\tWAITING TIME\tTURNAROUND TIME" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << "\tP" << p[i] << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }

    cout << fixed << setprecision(3) << "\nAverage Waiting Time: " << wtavg/n << endl;
    cout << fixed << setprecision(3) << "Average Turnaround Time: " << tatavg/n << endl;

    return 0;
}