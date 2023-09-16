#include<stdio.h>
float SJF_AWT,RR_AWT,Pr_AWT,FCFS_AWT;
void SJF (int n, int bt[])
{int temp,pos;
int wt[n];
float awt=0;
for (int i=0;i<n;i++)
{pos=i;
for (int j=i+1;j<n;j++) {
if (bt[j]<bt[pos])
{ pos=j; } }
temp=bt[i];
bt[i]=bt[pos];
bt[pos]=temp; }
wt[0]=0;
printf("process\tburst time\twaiting time\n");
for (int i=0;i<n;i++)
{ wt[i]=0;
for (int j=0;j<i;j++)
{ wt[i]=wt[i]+bt[j]; }
awt=awt+wt[i];
printf("%d\t%d \t\t%d\n",i+1,bt[i],wt[i]); }
SJF_AWT=awt/n;
printf("Average waiting time for SJF = %2f\n\n",SJF_AWT);}
void RoundRobin (int n, int bt[],int rem_bt[] ,int qt)
{ int temp,flag,count=0,sq=0;
int wt[n],tat[n];
float awt=0;
while (flag!=1)
{ for (int i=0;i<n;i++)
{ temp=qt;
if (rem_bt[i]==0)
{ count++;}
else if (rem_bt[i]>qt)
{rem_bt[i]=rem_bt[i]-qt;}
else {
temp=rem_bt[i];
rem_bt[i]=0;}
sq=sq+temp;
tat[i]=sq;
}
if (n==count)
{
flag=1; } }
printf("process\tburst time\t\twaiting time\n");
for (int i=0;i<n;i++)
{
wt[i]=tat[i]-bt[i];
awt=awt+wt[i];
printf("%d\t %d\t\t\t%d\n",i+1,bt[i],wt[i]);
}
RR_AWT=awt/n;
printf("Average waiting time for Round Robin = %2f\n\n",RR_AWT);
}
void PrirorityScheduling (int n, int bt[],int pr[])
{ int temp,pos;
int wt[n];
float awt=0;
for (int i=0;i<n;i++)
{ pos=i;
for (int j=i+1;j<n;j++)
{ if (pr[j]<pr[pos])
{ pos=j; } }
temp=pr[i];
pr[i]=pr[pos];
pr[pos]=temp;
temp=bt[i];
bt[i]=bt[pos];
bt[pos]=temp;}
wt[0]=0;
printf("process\tburst time\tpriority\twaiting time\n");
for (int i=0;i<n;i++)
{ wt[i]=0;
for (int j=0;j<i;j++)
{wt[i]=wt[i]+bt[j];}
awt=awt+wt[i];
printf("%d\t %d \t\t%d\t\t%d\n",i+1,bt[i],pr[i],wt[i]); }
Pr_AWT=awt/n;
printf("Average waiting time for Priority Scheduling = %2f\n\n",Pr_AWT);}
void FCFS (int n, int at[],int bt[])
{ int temp,pos;
int wt[n];
float awt=0;
for (int i=0;i<n;i++)
{ pos=i;
for (int j=i+1;j<n;j++)
{ if (at[i]<at[pos])
{ pos=j;} }
temp=at[i];
at[i]=at[pos];
at[pos]=temp;
temp=bt[i];
bt[i]=bt[pos];
bt[pos]=temp; }
wt[0]=0;
printf("process\tarrival time\tburst time\twaiting time\n");
for (int i=0;i<n;i++)
{ wt[i]=0;
for (int j=0;j<i;j++)
{ wt[i]=wt[i]+bt[j];}
awt=awt+wt[i];
printf("%d\t %d \t\t%d\t\t%d\n",i+1,at[i],bt[i],wt[i]); }
FCFS_AWT=awt/n;
printf("Average waiting time for FSFS = %2f\n\n",FCFS_AWT);}
int main ()
{ int num, qt;
printf("Enter the number of process\n");
scanf("%d",&num);
int choice,AT[num],BT[num],Pr[num],remBt[num];
for (int i=0;i<num;i++)
{ printf("\nEnter the Arrival Time of process p[%d]\n",i+1);
scanf("%d",&AT[i]);
printf("Enter the Burst Time of process p[%d]\n",i+1);
scanf("%d",&BT[i]);
remBt[i]=BT[i];
printf("Enter the Priority of process p[%d]\n",i+1);
scanf("%d",&Pr[i]); }
while (choice!=7)
{ printf("\n1.SJF\n");
printf("2.Round Robin\n");
printf("3.Priority Scheduling\n");
printf("4.FCFS\n");
printf("5.Compare\n");
printf("6.Quit\n\n");
scanf("%d",&choice);
if (choice==1)
{ SJF(num,BT); }
else if (choice==2)
{ printf("Enter the quantam time\n");
scanf("%d",&qt);
RoundRobin(num,BT,remBt,qt);}
else if (choice==3)
{PrirorityScheduling(num,BT,Pr);}
else if (choice==4)
{ FCFS(num,AT,BT); }
else if (choice==5)
{ SJF(num,BT);
RoundRobin(num,BT,remBt,qt);
PrirorityScheduling(num,BT,Pr);
FCFS(num,AT,BT);
if (SJF_AWT<RR_AWT && SJF_AWT< Pr_AWT && SJF_AWT <FCFS_AWT) {
printf("The best algorithm is SJF, average waiting time= %2f",SJF_AWT); }
else if (SJF_AWT>RR_AWT && RR_AWT< Pr_AWT && RR_AWT <FCFS_AWT)
{ printf("The best algorithm is RR, average waiting time= %2f",RR_AWT);}
else if (Pr_AWT <RR_AWT && SJF_AWT> Pr_AWT && Pr_AWT <FCFS_AWT)
{ printf("The best algorithm is SJF, average waiting time= %2f",Pr_AWT); }
else if (FCFS_AWT <RR_AWT && SJF_AWT> FCFS_AWT && Pr_AWT >FCFS_AWT)
{ printf("The best algorithm is SJF, average waiting time= %2f",FCFS_AWT);}}
else if (choice==6)
{ printf("Program successfully Terminated ");
choice=7; }
else { printf("Invalid Input"); } }
return 0;}
