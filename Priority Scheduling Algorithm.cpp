#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);

    int n;
    cout << "Enter The Number of Processes: ";
    cin >> n;
    int p[n], bt[n], prt[n], wt[n], tat[n];
    float wtavg = 0, tatavg = 0;

    for(int i = 0; i < n; i++)
    {
        p[i] = i+1;
        cout << "Enter Burst Time and Priority (With Space) of Process " << i+1 << ": ";
        cin >> bt[i] >> prt[i];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(prt[i] > prt[j])
            {
                swap(prt[i], prt[j]);
                swap(bt[i], bt[j]);
                swap(p[i], p[j]);
            }
            else if(prt[i] == prt[j])
            {
                if(p[i] > p[j])
                {
                    swap(prt[i], prt[j]);
                    swap(bt[i], bt[j]);
                    swap(p[i], p[j]);
                }
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
    cout << "\nPROCESS" << "\t\t" << "PRIORITY" << "\t" << "BURST TIME" << "\t" << "WAITING TIME" << "\t" << "TURNAROUND TIME" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << "P" << p[i] << "\t\t" << prt[i] << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }

    cout << fixed << setprecision(3) << "\nAverage Waiting Time: " << wtavg/n << endl;
    cout << fixed << setprecision(3) << "Average Turnaround Time: " << tatavg/n << endl;
    return 0;
}

