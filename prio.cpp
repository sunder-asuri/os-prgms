/*priority scheduling*/
#include<iostream>
using namespace std;
int main()
{
int p[20],bt[20],pri[20],wt[20],tat[20],i,k,n,temp;
float wtavg,tatavg;
cout<<"Enter the number of process : ";
cin>>n;
for(i=0;i<n;i++)
{
p[i] = 1;
cout<<"Enter the busrts time and priority of process "<<i;
cin>>bt[i]>>pri[i];
}
for(i=0;i<n;i++)
{
  for(k=i+1;k<n;k++)
  {
    if(pri[i]>pri[k])
    {
      temp = p[i];
      p[i]=p[k];
      p[k]=temp;
      temp = bt[i];
      bt[i]=bt[k];
      bt[k]=temp;
      temp=pri[i];
      pri[i]=pri[k];
      pri[k]=temp;
    }
   }
}
wtavg= wt[0] = 0;
tatavg = tat[0] = bt[0];
for(i = 1;i < n; i++)
{
wt[i]=wt[i-1] + bt[i - 1];
tat[i] = tat[i - 1] + bt[i];
wtavg = wtavg + wt[i];
tatavg = tatavg + tat[i];
}
cout<<"\nProcess\t\tpriority\t\tBurst Time\t\tWaiting time\t\tturnaround time";
for(i=0;i<n;i++)
{
cout<<"\n"<<p[i]<<"\t\t"<<pri[i]<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i];
}
cout<<"\nAVerage waiting Time: "<<wtavg/n;
cout<<"\nAVerage Turnaround Time : "<<tatavg/n;
}       
