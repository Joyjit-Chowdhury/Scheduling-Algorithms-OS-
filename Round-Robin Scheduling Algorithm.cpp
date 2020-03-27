#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);

    int n, i, j, MAX, time_slice;
    float awt=0,att=0,temp=0;
    cout << "Enter The Number of Process: ";
    cin >> n;
    int bt[n], tmp[n], tat[n], wt[n], p[n];
    for(i=0;i<n;i++)
    {
        p[i] = i+1;
        cout << "Enter The Burst TIme for Process " << i+1 << ": ";
        cin >> bt[i];
        tmp[i]=bt[i];
    }
    cout << "Enter The Size of Time Slice: ";
    cin >> time_slice;

    MAX=bt[0];
    for(i=1;i<n;i++) {
        if (MAX < bt[i]) {
            MAX = bt[i];
        }
        for (j = 0; j < (MAX / time_slice) + 1; j++) {
            for (i = 0; i < n; i++) {
                if (bt[i] != 0) {
                    if (bt[i] <= time_slice) {
                        tat[i] = temp + bt[i];
                        temp = temp + bt[i];
                        bt[i] = 0;
                    } else {
                        bt[i] = bt[i] - time_slice;
                        temp = temp + time_slice;
                    }
                }
            }
        }
    }
        for(i=0;i<n;i++)
        {
            wt[i]=tat[i]-tmp[i];
            att+=tat[i];
            awt+=wt[i];
        }

        cout << "\nPROCESS\t\t BURST TIME\t\t WAITING TIME\t\t TURNAROUND TIME\n";
        for(i=0;i<n;i++)
        {
            cout << p[i] << "\t\t\t" << tmp[i] << "\t\t\t" << wt[i] << "\t\t\t" << tat[i] << "\t\t\t" << endl;
        }
        cout << fixed << setprecision(2) << "\nAverage Wating Time: " << awt/n << endl;
        cout << fixed << setprecision(2) << "Average Turnaround Time: " << att/n << endl;
}