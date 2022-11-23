#include <iostream>
using namespace std;

void findwt(int process[],int n,int bt[],int wt[]){
    wt[0]=0;
    for(int i=1;i<n;i++){
        wt[i] = wt[i-1] + bt[i-1];
    }
}
void findtat(int process[],int n,int bt[],int wt[],int tat[]){
    for(int i=0;i<n;i++){
        tat[i] = bt[i]+wt[i];
    }
}
void findavgtime(int process[],int n,int bt[]){
    int wt[n],tat[n],total_wt = 0,total_tat = 0;
    findwt(process,n,bt,wt);
    findtat(process,n,bt,wt,tat);
    cout<<"Processes "<<" Burst time "<<" Waiting Time "<<" Turn Around Time \n";
    for(int i=0;i<n;i++){
        total_wt += wt[i];
        total_tat += tat[i];
        cout<<"   "<<i+1<<"\t\t"<<bt[i]<<"\t    "<<wt[i]<<"\t\t  "<<tat[i]<<endl;
    }
    cout<<"Average waiting time = "<<(float)total_wt/(float)n<<endl;
    cout<<"Average turn around time = "<<(float)total_tat/(float)n;
}
int main() {
    int processes[] = {1,2,3};
    int n = sizeof(processes)/sizeof(processes[0]);
    int burst_time[] = {10,5,8};
    findavgtime(processes,n,burst_time);
    return 0;
}