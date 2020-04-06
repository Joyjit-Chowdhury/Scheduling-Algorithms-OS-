#include<bits/stdc++.h>
using namespace std;

struct resources
{
    int allocation[100];
    int maximum[100];
    int remaining[100];
    int flag;
}res[100];
int main()
{
    ios::sync_with_stdio(0);
    struct resources;
    int n, r, g, b, fl, cnt = 0, check = 0;
    cout << "Enter Number of Processes : ";
    cin >> n;
    int available[n], sequence[n];
    cout << "Enter Number of Resources : ";
    cin >> r;

    for(int i = 0; i < n; i++)
    {
        cout << "Enter all Informations for P" << i+1 << "-" << endl;
        cout << "Enter Allocations : ";
        for(int j = 0; j < r; j++)
        {
            cin >> res[i].allocation[j];
        }
        cout << "Enter Maximum Needs : ";
        for(int j = 0; j < r; j++)
        {
            cin >> res[i].maximum[j];
        }
        res[i].flag = 0;
    }
    cout << "Enter Available Resources : ";
    for(int i = 0; i < r; i++)
    {
        cin >> available[i];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < r; j++)
        {
            res[i].remaining[j] = res[i].maximum[j] - res[i].allocation[j];
            if(res[i].remaining[j] < 0)
            {
                res[i].remaining[j] = 0;
            }
        }
    }
    cnt = 0;
    fl = 0;
    while(cnt != n)
    {
        g = 0;
        for(int j = 0; j < n; j++)
        {
            if(res[j].flag == 0)
            {
                b = 0;
                for(int p = 0; p < r; p++)
                {
                    if(available[p] >= res[j].remaining[p])
                    {
                        b += 1;
                    } else
                    {
                        b -= 1;
                    }
                }
                if(b == r)
                {
                    if(check == 0)
                    {
                        cout << "\nAvailble -";
                        check++;
                    }
                    cout << "\nP" << j+1 << " is visited ";
                    sequence[fl++] = j;
                    res[j].flag = 1;
                    for(int k = 0; k < r; k++)
                    {
                        available[k] += res[j].allocation[k];
                    }
                    cnt += 1;
                    cout << "( ";
                    for(int k = 0; k < r; k++)
                    {
                        cout << available[k] << " ";
                    }
                    cout << ")";
                    g = 1;
                }
            }
        }
        if(g == 0)
        {
            cout << "\nRequest Not Granted. Deadlock Occurred.";
            cout << "\nSystem is in UNSAFE STATE.";
            goto y;
        }
    }
    cout << "\n\nSystem is in SAFE STATE.";

    y: cout << "\n\nProcess\t\tAllocation\t\tMaximum Need\t\tRemaining\n";
    for(int i = 0; i < n; i++)
    {
        cout << "P" << i+1 << "\t\t";
        for(int j = 0; j < r; j++)
        {
            cout << res[i].allocation[j] << " ";
        }
        cout << "\t\t\t";
        for(int j = 0; j < r; j++)
        {
            cout << res[i].maximum[j] << " ";
        }
        cout << "\t\t\t";
        for(int j = 0; j < r; j++)
        {
            cout << res[i].remaining[j] << " ";
        }
        cout << "\n";
    }

    return 0;
}