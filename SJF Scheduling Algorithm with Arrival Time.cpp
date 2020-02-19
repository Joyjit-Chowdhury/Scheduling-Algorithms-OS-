#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);

    int n;
    cout << "Enter the Number of Processes: ";
    cin >> n;

    int p[n], bt[n], a_t[n], ct[n], tat[n], wt[n];

    for(int i = 0; i < n; i++)
    {
        p[i] = i+1;
        cout << "Enter Arrival Time and Burst Time (With Space) for Process " << i+1 << ": ";
        cin >> a_t[i] >> bt[i];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(a_t[i] > a_t[j])
            {
                swap(a_t[i], a_t[j]);
                swap(bt[i], bt[j]);
                swap(p[i],p[j]);
            }
            else if(a_t[i] == a_t[j])
            {
                if(bt[i] > bt[j])
                {
                    swap(a_t[i], a_t[j]);
                    swap(bt[i], bt[j]);
                    swap(p[i],p[j]);
                }
            }
        }
    }

    ct[0] = bt[0] + a_t[0];

    for(int i = 1; i < n; i++)
    {
        ct[i] = ct[i-1] + bt[i];
    }
    for(int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - a_t[i];
        wt[i] = tat[i] - bt[i];
    }
    cout << "\nProcess" << "\t\tArrival Time" << "\tBurst Time" << "\tCompletion Time" << "\t\tTurn Around Time" <<
         "\tWaiting Time" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << "P" << p[i] << "\t\t" << a_t[i] << "\t\t" << bt[i] << "\t\t" << ct[i] << "\t\t\t" << tat[i] <<
             "\t\t\t" << wt[i] << endl;
    }
    return 0;
}
