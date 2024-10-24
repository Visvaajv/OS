#include<stdio.h>
#include<conio.h>
void main()
{
int nop,t,wt[10],twt,tat[10],ttat,i,j,p[10],bt[10],tmp;
float awt, atat;
awt=0.0;
atat=0.0;
printf("Enter the number of process:");
scanf("%d",&nop);
for(i=0;i<nop;i++)
{
printf("Enter the burst time of  Process %d:",i);
scanf("%d",&bt[i]);
}
for(i=0;i<nop;i++)
{
printf("Enter the priority number of each Process %d:",i);
scanf("%d",&p[i]);
}
for(i=0;i<nop;i++)
{
for(j=i+1;j<nop;j++)
{
if(p[i]>p[j])
{
t=p[i];
p[i]=p[j];
p[j]=t;
tmp=bt[i];
bt[i]=bt[j];
bt[j]=tmp;
}
}
}
wt[0]=0;
tat[0]=bt[0];
twt=wt[0];
ttat=tat[0];
for(i=1;i<nop;i++)
{
wt[i]=wt[i-1]+bt[i-1];
tat[i]=wt[i]+bt[i];
twt+=wt[i];
ttat+=tat[i];
}
awt=(float)twt/nop;
atat=(float)ttat/nop;
printf("Process No:\tPriority:\tBurst Time:\tWaiting Time\tTurnaround Time:\n");
for(i=0;i<nop;i++)
printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i,p[i],bt[i],wt[i],tat[i]);
printf("Total TurnAround Time:%d\n",ttat);
printf("Total Waiting Time:%d\n",twt);
printf("Average Waiting Time:%f\n",awt);
printf("Average Turnaround Time:%f\n",atat);
getch();
}