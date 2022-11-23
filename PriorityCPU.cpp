//program to take the priority of the process the arrival time and the burst time and calculate the average waiting time and the average turn around time using the priority scheduling algorithm
#include<iostream>
using namespace std;
int main()
{
int n;
cout<<"Enter the number of processes: ";
cin>>n;
int Process_no[n],Arrival_time[n],Burst_time[n],Wait[n],Turnaround[n],pr[n],i,j;
for(i=0;i<n;i++)
{
cout<<"Enter the process number: ";
cin>>Process_no[i];
cout<<"Enter the arrival time: ";
cin>>Arrival_time[i];
cout<<"Enter the burst time: ";
cin>>Burst_time[i];
cout<<"Enter the priority: ";
cin>>pr[i];
}
int temp;
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(pr[i]>pr[j])
{
temp=pr[i];
pr[i]=pr[j];
pr[j]=temp;
temp=Arrival_time[i];
Arrival_time[i]=Arrival_time[j];
Arrival_time[j]=temp;
temp=Burst_time[i];
Burst_time[i]=Burst_time[j];
Burst_time[j]=temp;
temp=Process_no[i];
Process_no[i]=Process_no[j];
Process_no[j]=temp;
}
}
}
int total=0;
Wait[0]=0;
for(i=1;i<n;i++)
{
Wait[i]=0;
for(j=0;j<i;j++)
Wait[i]+=Burst_time[j];
total+=Wait[i];
}
float avg_wt=(float)total/n;
total=0;
cout<<"Process\tPriority\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time"<<endl;
for(i=0;i<n;i++)
{
Turnaround[i]=Burst_time[i]+Wait[i];
total+=Turnaround[i];
cout<<Process_no[i]<<"\t"<<pr[i]<<"\t\t"<<Arrival_time[i]<<"\t\t"<<Burst_time[i]<<"\t\t"<<Wait[i]<<"\t\t"<<Turnaround[i]<<endl;
}
float avg_tat=(float)total/n;
cout<<"Average Waiting Time: "<<avg_wt<<endl;
cout<<"Average Turnaround Time: "<<avg_tat<<endl;
return 0;
}
