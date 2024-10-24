#include <stdio.h>
#include <stdlib.h>
int main() 
{
int s, n, b = 0, p = 0, c = 0;
printf("\nProducer and Consumer Problem");
printf("\nEnter the size of the buffer: ");
scanf("%d", &n);
do 
{
printf("\nMenu:");
printf("\n1. Produce an item");
printf("\n2. Consume an item");
printf("\n3. Add item to the buffer");
printf("\n4. Display status");
printf("\n5. Exit");
printf("\nEnter your choice: ");
scanf("%d", &s);
switch (s) 
{
case 1:
p = p + 1;
printf("\nItem produced. Total produced: %d", p);
break;
case 2:
if (b != 0) 
{
c = c + 1;
b = b - 1;
printf("\nItem consumed. Total consumed: %d", c);
} 
else 
{
printf("\nThe buffer is empty. Please wait...");
}
break;
case 3:
if (b < n) 
{
if (p > c) 
{
b = b + 1;
printf("\nItem added to buffer. Buffered items: %d", b);
} 
else 
{
printf("\nNo more produced items to add to buffer.");
}
} 
else 
{
printf("\nBuffer is full. Please wait...");
}
break;
case 4:
printf("\nNumber of items produced: %d", p);
printf("\nNumber of items consumed: %d", c);
printf("\nNumber of buffered items: %d", b);
break;
case 5:
exit(0);
default:
printf("\nInvalid choice. Please select a valid option.");
break;
}
} 
while (s != 5);
return 0;
}