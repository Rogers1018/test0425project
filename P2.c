#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a, b, u, v, n, i, j, ne = 1;
int visited[150] = {0}, min, mincost = 0, cost[150][150];

int main()
{
    printf("\n Enter the number of nodes:");  
    scanf("%d", &n);
    printf("\n Enter the adjacency matrix:\n");  

    clock_t starttime, endtime;  
    for (i = 1; i <= n; i++)     
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }

    visited[1] = 1;  
    printf("\nThe Edges of Spanning Tree are:\n"); 

    starttime = clock();  

    while (ne < n)
    {
        for (i = 1, min = 999; i <= n; i++)  
            for (j = 1; j <= n; j++)
                if (cost[i][j] < min)
                    if (visited[i] != 0) {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }

        if (visited[u] == 0 || visited[v] == 0)  
        {
            printf("\n%d edge(%d,%d) =%d", ne++, a, b, min);
            mincost += min;
            visited[b] = 1;
        }

        cost[a][b] = cost[b][a] = 999;  
    }

    endtime = clock();
    printf("\n\nMinimum cost = %d\n", mincost);
    printf("Time taken: %f\n", (endtime - starttime) / (double)CLOCKS_PER_SEC);
}

