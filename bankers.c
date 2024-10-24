#include <stdio.h>
#include <stdlib.h>
int np, nr, r[10], safe[10], ava[10], f[10], all[10][10], max[10][10], need[10][10];
void input();
void calculateNeed();
int checkSafe();
void requestResources();
int main() 
{
input();
calculateNeed();
if (checkSafe()) {
printf("\nSystem is in a safe state.\n");
printf("Safe sequence: ");
for (int i = 0; i < np; i++)
printf("P[%d] ", safe[i]);
} 
else 
{
printf("\nSystem is not in a safe state.\n");
exit(0);
}
requestResources(); 
if (checkSafe()) 
{
printf("\nSystem remains in a safe state after the request.\n");
printf("Safe sequence: ");
for (int i = 0; i < np; i++)
printf("P[%d] ", safe[i]);
} 
else 
{
printf("\nRequest cannot be granted as it leads to an unsafe state.\n");
}
return 0;
}
void input() 
{
printf("Enter number of processes: ");
scanf("%d", &np);
printf("Enter number of resources: ");
scanf("%d", &nr);    
printf("Enter available instances of each resource:\n");
for (int i = 0; i < nr; i++)
scanf("%d", &ava[i]);    
printf("Enter allocation matrix:\n");
for (int i = 0; i < np; i++)
for (int j = 0; j < nr; j++)
scanf("%d", &all[i][j]);    
printf("Enter max requirement matrix:\n");
for (int i = 0; i < np; i++)
for (int j = 0; j < nr; j++)
scanf("%d", &max[i][j]);
}
void calculateNeed() 
{
for (int i = 0; i < np; i++)
for (int j = 0; j < nr; j++)
need[i][j] = max[i][j] - all[i][j];
}
int checkSafe() 
{
int work[10], index = 0;
for (int i = 0; i < nr; i++)
work[i] = ava[i];
for (int i = 0; i < np; i++)
f[i] = 0;
while (index < np) 
{
int found = 0;
for (int i = 0; i < np; i++) 
{
if (f[i] == 0) 
{
int canAllocate = 1;
for (int j = 0; j < nr; j++)
if (need[i][j] > work[j]) 
{
canAllocate = 0;
break;
}                
if (canAllocate) 
{
for (int j = 0; j < nr; j++)
work[j] += all[i][j];
safe[index++] = i;
f[i] = 1;
found = 1;
}
}
}
if (!found)
return 0; 
}
return 1; 
}
void requestResources() 
{
int pid, req[10];
printf("\nEnter process number making the request: ");
scanf("%d", &pid);
printf("Enter request for resources:\n");
for (int i = 0; i < nr; i++)
scanf("%d", &req[i]);
for (int i = 0; i < nr; i++) 
{
if (req[i] > need[pid][i] || req[i] > ava[i]) 
{
printf("\nRequest cannot be granted.\n");
exit(0);
}
}
for (int i = 0; i < nr; i++) 
{
ava[i] -= req[i];
all[pid][i] += req[i];
need[pid][i] -= req[i];
}
}