#include <stdio.h>

int main() {
    int blockSize[20], processSize[20], b[20], p[20], m, n, i, j;

    printf("Enter number of blocks: ");
    scanf("%d", &m);
    printf("Enter size of each block:\n");
    for(i = 0; i < m; i++) {
        printf("Block[%d]: ", i + 1);
        scanf("%d", &blockSize[i]);
        b[i] = 0; 
    }

    printf("\nEnter number of processes: ");
    scanf("%d", &n);
    printf("Enter size of each process:\n");
    for(i = 0; i < n; i++) {
        printf("Process[%d]: ", i + 1);
        scanf("%d", &processSize[i]);
        p[i] = -1;
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            if(!b[j] && blockSize[j] >= processSize[i]) {
                p[i] = j;
                b[j] = 1;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for(i = 0; i < n; i++) {
        if(p[i] != -1)
            printf("%d\t\t%d\t\t%d\n", i + 1, processSize[i], p[i] + 1);
        else
            printf("%d\t\t%d\t\tNot Allocated\n", i + 1, processSize[i]);
    }
    return 0;
}