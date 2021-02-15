#include<iostream>
using namespace std;

void findWaitingTime(int arrival[], int n,
                          int bt[], int wt[])
{
    wt[0] = 0;

    for (int  i = 1; i < n ; i++ ){
        wt[i] =  bt[i-1] + wt[i-1] -arrival[i] + arrival[i-1];

        if(wt[i]<0)wt[i] = 0;
        }


}

void findTurnAroundTime( int arrival[], int n,int bt[], int wt[], int tat[])
{
    for (int  i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i] + arrival[i];
}

void findavgTime( int arrival[], int n, int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    findWaitingTime(arrival, n, bt, wt);

    findTurnAroundTime(arrival, n, bt, wt, tat);

    cout << "Arrival time  "<< " Burst time  "
         << " Waiting time  " << " Turn around time\n";

    for (int  i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "     " << arrival[i] << "\t\t" << bt[i] <<"\t    "
            << wt[i] <<"\t\t  " << tat[i] <<endl;
    }

    cout << "Average waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n;
}

int main()
{
    cout<<"Input total number of processess - ";
    int n;
    cin>>n;
    int arrival[n]; 
    int  bursttime[n];

    cout<<"Input arrival time of all processess-"<<endl;
   

    for(int i =0;i<n;i++){
      cin>>arrival[i];
    }

    cout<<"Input burst time of all processess-"<<endl;
    
    for(int i =0;i<n;i++){
      cin>>bursttime[i];
    }

    cout<<endl;

    findavgTime(arrival, n ,bursttime);
    return 0;
}